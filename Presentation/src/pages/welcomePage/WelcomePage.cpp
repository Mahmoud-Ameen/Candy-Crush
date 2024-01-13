#include <iostream>
#include "pages/welcomePage/WelcomePage.h"
#include "pages/welcomePage/StartButton.h"

WelcomePage::WelcomePage(sf::RenderTarget *renderTarget): Page(renderTarget){
    backgroundImage = new BackgroundImage(backgroundImagePath,
                                          (float)renderTarget->getSize().x,
                                          (float)renderTarget->getSize().y);

    // Initialize Start Button
    auto startButton = new StartButton();
    startButton->addObserver(this);
    addWidget(startButton);
}

void WelcomePage::render() {

    // Render Background Image
    backgroundImage->render(renderTarget);

    for (auto& widget: widgets) {
        widget->render(renderTarget);
    }
}

void WelcomePage::update(const sf::Time &dt) {

}

void WelcomePage::handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords,
                              const sf::Vector2f &mousePositionInView, float scaleFactor) {
    if(ev.type == sf::Event::Resized) {
    }
    for (auto& widget: widgets) {
        sf::Vector2f mousePosition {mousePositionInView.x-originCoords.x,mousePositionInView.y - originCoords.y};
        mousePosition/=scaleFactor;
        if(widget->getGlobalBounds().contains(mousePosition))
        {
            widget->setHovered(true);
            widget->handleEvent(ev, sf::Vector2f());
        }
        else widget->setHovered(false);
    }

}

void WelcomePage::onEvent(const std::string &eventName) {
    if(eventName == "startButtonClicked") {
        notifyObservers("startButtonClicked");
    }
    else
        notifyObservers(eventName);
}
