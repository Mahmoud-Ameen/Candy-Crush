#include "PageManager.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantConditionsOC"
PageManager::PageManager(sf::RenderTarget *renderTarget) : renderTarget(renderTarget){
    // Initialize Pages
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

void PageManager::handleEvent(const sf::Event &event) {
//    pages[currentPageIndex]->handleEvent(event);
}


void PageManager::onEvent(const std::string &eventName) {
// Handle events triggered by pages
}

#pragma clang diagnostic pop