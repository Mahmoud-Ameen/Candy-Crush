
#include "pages/gameplayPage/LevelLostWidget.h"

LevelLostWidget::LevelLostWidget(){
    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
    texture.setSmooth(true);
    homeButton.addObserver(this);
}


void LevelLostWidget::render(sf::RenderTarget *renderTarget) {
    homeButton.home.setPosition(renderTarget->getSize().x/2 - homeButton.home.getGlobalBounds().width/2,450);

    sprite.setScale((float)(renderTarget->getSize().x-80) / (float)texture.getSize().x,
                    (float)(renderTarget->getSize().x-80) / (float)texture.getSize().x);
    sprite.setPosition(renderTarget->getSize().x/2 - sprite.getGlobalBounds().width/2,
                       renderTarget->getSize().y/2 - sprite.getGlobalBounds().height/2);

    renderTarget->draw(sprite);
    homeButton.render(renderTarget);
}

void LevelLostWidget::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {
    if(homeButton.getGlobalBounds().contains(mousePosition)) {
        homeButton.setHovered(true);
        homeButton.handleEvent(ev,mousePosition);
    }
}

void LevelLostWidget::onEvent(const std::string &eventName) {
    notifyObservers(eventName);
}
