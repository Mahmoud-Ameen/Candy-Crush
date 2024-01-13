#include <iostream>
#include "pages/GameplayPage/GameplayPage.h"
#include "pages/gameplayPage/BottomBarWidget.h"
#include "GameController.h"

GameplayPage::GameplayPage(sf::RenderTarget *renderTarget): Page(renderTarget){
    backgroundImage = new BackgroundImage(backgroundImagePath,
                                          (float)renderTarget->getSize().x,
                                          (float)renderTarget->getSize().y);

    GameController::getInstance().addObserver(this);

    // Init PopUps Widget
    pausePopUp = new PausePopUp();
    levelClearedWidget = new LevelClearedWidget();
    levelLostWidget = new LevelLostWidget();

    pausePopUp->addObserver(this);
    levelLostWidget->addObserver(this);
    levelClearedWidget->addObserver(this);

    // Game State widgets
    topBar = new TopBarWidget((int)renderTarget->getSize().x,140);
    bottomBar = new BottomBarWidget((int)renderTarget->getSize().x,100);

    float boardLength = std::min((float) renderTarget->getSize().x,
                            (float)renderTarget->getSize().y-140-100);
    boardWidget = new BoardWidget(boardLength,
                                       sf::Vector2f((float)renderTarget->getSize().x/2-boardLength/2,
                                        130));

    addWidget(topBar);
    addWidget(bottomBar);
    addWidget(boardWidget);

    // Observe events in sub-widgets
    for (auto& widget:widgets )
        widget->addObserver(this);
}

void GameplayPage::render() {
    renderTarget->clear(sf::Color(103, 78, 107, 200));
    // Render Background Image
    backgroundImage->render(renderTarget);

    for (auto& widget: widgets) {
        widget->render(renderTarget);
    }
    if(gameState.isGameWon){
        levelClearedWidget->render(renderTarget);
        return;
    }
    if(gameState.isGameLost){
        levelLostWidget->render(renderTarget);
        return;
    }
    if(isPaused){
        pausePopUp->render(renderTarget);
    }
}

void GameplayPage::update(const sf::Time &dt) {
    if(isPaused || gameState.isGameWon || gameState.isGameLost) return;
    if(!isProcessingEvent && !gameEventsQueue.empty()){
        isProcessingEvent = true;

        // Process Game Event
        auto ev = gameEventsQueue.front();
        if(ev.eventType == GameEventType::MatchingEvent){
            std::vector<std::pair<int,int>> matchedIndices;
            for (int i = 0; i < ev.initialGameState.board.size(); ++i) {
                for (int j = 0; j < ev.initialGameState.board[i].size(); ++j) {
                    if(ev.modifiedGameState.board[i][j] == DTOs::CandyType::RemovedCandy)
                        matchedIndices.emplace_back(i,j);
                }
            }
            boardWidget->matchingAnimation(matchedIndices);
        }else if(ev.eventType == GameEventType::GravityEvent){
            gameState = ev.modifiedGameState;
            boardWidget->setBoard(gameState.board);
            bottomBar->setObjectives(gameState.objectives);
            gameEventsQueue.pop();
            isProcessingEvent = false;

        }
    }
    for (auto& widget: widgets) {
        widget->update(dt);
    }
}

void GameplayPage::handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords,
                               const sf::Vector2f &mousePositionInView,
                                float scaleFactor) {
    if(ev.type == sf::Event::Resized) {
        backgroundImage->handleImageResize((float)ev.size.width, (float)ev.size.height);
    }
    sf::Vector2f mousePosition {mousePositionInView.x-originCoords.x,mousePositionInView.y - originCoords.y};
    mousePosition/=scaleFactor;

    if(gameState.isGameWon){
        levelClearedWidget->handleEvent(ev,mousePosition);
        return;
    }
    if(gameState.isGameLost){
        levelLostWidget->handleEvent(ev,mousePosition);
        return;
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
    {
        isPaused = !isPaused;
        return;
    }

    if(isPaused){
        pausePopUp->handleEvent(ev,mousePosition);
        return;
    }
    for (auto& widget: widgets) {
        if(widget->getGlobalBounds().contains(mousePosition))
        {
            widget->setHovered(true);
            widget->handleEvent(ev, mousePosition);
        }
        else widget->setHovered(false);
    }

}

void GameplayPage::onEvent(const std::string &eventName) {
    if(eventName == "matchingAnimationFinished"){
        std::cout << "\nmatchingAnimationFinished\n\n";
        isProcessingEvent = false;
        gameState = gameEventsQueue.front().modifiedGameState;
        gameEventsQueue.pop();
        boardWidget->setBoard(gameState.board);
        topBar->setRemainingMoves(gameState.remainingMoves);
        bottomBar->setObjectives(gameState.objectives);
    }
    else if(eventName == "PlayButtonClicked") {
        isPaused = false;
    }

    notifyObservers(eventName);
}

void GameplayPage::onGameEvent(const GameEvent& ev) {
    gameEventsQueue.push(ev);
}

GameplayPage::~GameplayPage() {
    delete pausePopUp;
    delete levelClearedWidget;
    delete levelLostWidget;
}
