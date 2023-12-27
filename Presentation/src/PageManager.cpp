#include "PageManager.h"
#include "pages/welcomePage/WelcomePage.h"

PageManager::PageManager(sf::RenderTarget *renderTarget) : renderTarget(renderTarget){
    auto welcomePage = new WelcomePage(renderTarget);
    addPage(welcomePage);
    switchToPage(0);
}

void PageManager::addPage(Page* page) {
    pages.push_back(page);
    page->addObserver(this);
}

void PageManager::switchToPage(int index) {
    if(index >= 0 && index < pages.size()){
        pages[currentPageIndex]->setActive(false);
        currentPageIndex = index;
        pages[currentPageIndex]->setActive(true);
    }
}

void PageManager::renderPage() {
    if (currentPageIndex >= 0 && currentPageIndex < pages.size()) {
        pages[currentPageIndex]->render();
    }
}

void PageManager::updatePage(const sf::Time &dt) {
    if (currentPageIndex >= 0 && currentPageIndex < pages.size()) {
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
    }
}
