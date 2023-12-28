#include <iostream>
#include "pages/levelsPage/LevelsPage.h"
#include "pages/levelsPage/LevelButton.h"

LevelsPage::LevelsPage(sf::RenderTarget *renderTarget): Page(renderTarget){
    backgroundImage = new BackgroundImage(backgroundImagePath,
                                          (float)renderTarget->getSize().x,
                                          (float)renderTarget->getSize().y);

    // Get Available Level Numbers
    std::vector<int> lvlNumbers{1,2,3,4,5};
    for (auto num: lvlNumbers)
        addWidget(new LevelButton(num));

    for (auto& widget:widgets )
        widget->addObserver(this);
}

void LevelsPage::render() {

    // Render Background Image
    backgroundImage->render(renderTarget);

    for (auto& widget: widgets) {
        widget->render(renderTarget);
    }
}

void LevelsPage::update(const sf::Time &dt) {

}

void LevelsPage::handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords, const sf::Vector2f &mousePositionInView,
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
            widget->handleEvent(ev);
        }
        else widget->setHovered(false);
    }

}

void LevelsPage::onEvent(const std::string &eventName) {
        notifyObservers(eventName);
}
