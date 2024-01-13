#include "PageManager.h"
#include "pages/welcomePage/WelcomePage.h"
#include "pages/levelsPage/LevelsPage.h"
#include "pages/GameplayPage/GameplayPage.h"

PageManager::PageManager(sf::RenderTarget *renderTarget) : renderTarget(renderTarget){
    // Create welcome Page
    auto welcomePage = new WelcomePage(renderTarget);
    addPage(welcomePage);

    // Create Levels Page
    auto levelsPage = new LevelsPage(renderTarget);
    addPage(levelsPage);

    switchToPage(0);
}

void PageManager::addPage(Page* page) {
    pages.push_back(page);
    page->addObserver(this);
}

void PageManager::switchToPage(int index) {
    if(index < pages.size()){
        currentPageIndex = index;
    }
}

void PageManager::renderPage() {
    if (currentPageIndex < pages.size()) {
        pages[currentPageIndex]->render();
    }
}

void PageManager::updatePage(const sf::Time &dt) {
    if (currentPageIndex < pages.size()) {
        pages[currentPageIndex]->update(dt);
    }
}

void PageManager::handleEvent(const sf::Event &event, const sf::Vector2f &originCoords,
                              const sf::Vector2f &mousePositionInView,
                              float scaleFactor) {
    pages[currentPageIndex]->handleEvent(event, originCoords, mousePositionInView, scaleFactor);
}


void PageManager::onEvent(const std::string &eventName) {
    // Handle events triggered by pages
    if(eventName == "startButtonClicked"){
        std::cout << "Switching to Levels' Page\n";
        switchToPage(1);
    }
    else if (eventName.rfind("StartLevel", 0) == 0) {
        int levelNumber = std::stoi(eventName.substr(10,eventName.npos));
        GameController& controller = GameController::getInstance();
        controller.startGame(levelNumber);
        addPage(new GameplayPage(renderTarget));
        pages[2]->addObserver(this);
        switchToPage(2);
    }
    else if (eventName == "HomeButtonClicked"){
        if(pages.size() < 3) return;
        pages[2] = nullptr;
        pages.erase(pages.begin() + 2);
        switchToPage(0);
    }
    notifyObservers(eventName);
}
