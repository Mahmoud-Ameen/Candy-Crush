#include <iostream>
#include "pages/GameplayPage/GameplayPage.h"
#include "pages/gameplayPage/LevelInfoWidget.h"
#include "pages/gameplayPage/TopBarWidget.h"
#include "pages/gameplayPage/BottomBarWidget.h"
#include "pages/gameplayPage/Board.h"

GameplayPage::GameplayPage(sf::RenderTarget *renderTarget): Page(renderTarget){
    backgroundImage = new BackgroundImage(backgroundImagePath,
                                          (float)renderTarget->getSize().x,
                                          (float)renderTarget->getSize().y);

    // Game State widgets
    auto  topBar = new TopBarWidget((int)renderTarget->getSize().x,160);
    auto  bottomBar = new BottomBarWidget((int)renderTarget->getSize().x,130);

    float boardLength = std::min((float) renderTarget->getSize().x,
                            (float)renderTarget->getSize().y-160-130);
    auto board = new Board(boardLength,
                           sf::Vector2f(renderTarget->getSize().x/2-boardLength/2,
                                        150));
    addWidget(topBar);
    addWidget(bottomBar);
    addWidget(board);

    // Observe events in sub-widgets
    for (auto& widget:widgets )
        widget->addObserver(this);
}

void GameplayPage::render() {
    renderTarget->clear(sf::Color::Transparent);
    // Render Background Image
    backgroundImage->render(renderTarget);

    for (auto& widget: widgets) {
        widget->render(renderTarget);
    }
}

void GameplayPage::update(const sf::Time &dt) {
    for (auto& widget: widgets) {
        widget->update(dt);
    }
}

void GameplayPage::handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords,
                               const sf::Vector2f &mousePositionInView,
                                float scaleFactor) {
    if(ev.type == sf::Event::Resized) {
        backgroundImage->handleImageResize(ev.size.width, ev.size.height);
    }
    for (auto& widget: widgets) {
        sf::Vector2f mousePosition {mousePositionInView.x-originCoords.x,mousePositionInView.y - originCoords.y};
        mousePosition/=scaleFactor;
        if(widget->getGlobalBounds().contains(mousePosition))
        {
            widget->setHovered(true);
            widget->handleEvent(ev, mousePosition);
        }
        else widget->setHovered(false);
    }

}

void GameplayPage::onEvent(const std::string &eventName) {
    notifyObservers(eventName);
}
