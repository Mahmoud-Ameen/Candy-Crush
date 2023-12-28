#include <iostream>
#include <cmath>
#include "pages/levelsPage/LevelButton.h"


LevelButton::LevelButton(int levelNumber): levelNumber(levelNumber){
    // Load Image
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Error loading image from file: " << imagePath << std::endl;
    }
    sprite.setTexture(texture);

    // Load Font
    if(!font.loadFromFile(fontPath)){
        std::cerr << "Error loading font from file: " << fontPath << std::endl;
    }
    textObject.setFont(font);
    textObject.setString("Level " + std::to_string(levelNumber));
    textObject.setCharacterSize(40);
    textObject.setStyle(sf::Text::Bold);
    textObject.setFillColor(sf::Color::Black);

}

void LevelButton::render(sf::RenderTarget* renderTarget) {

    const int padding = 15;
    sprite.setPosition({(float)renderTarget->getSize().x / 2 - sprite.getGlobalBounds().width / 2,
                        padding + (float)(sprite.getGlobalBounds().height+padding) * float(levelNumber-1) });
    setTextPosition();

    if(isHovered) {
        sprite.setColor({255, 255, 255, 240});
        notifyObservers("clickableHovered");
    }
    else {
        sprite.setColor({255, 255, 255, 255});
    }

    renderTarget->draw(sprite);
    renderTarget->draw(textObject);
}

void LevelButton::handleEvent(sf::Event event)  {
    if(event.type == sf::Event::MouseButtonPressed) {
        notifyObservers("StartLevel"+std::to_string(levelNumber));
    }
}

void LevelButton::update(sf::Time dt) {

}

sf::Rect<float> LevelButton::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void LevelButton::setTextPosition() {
    sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = textObject.getGlobalBounds();
    textObject.setPosition(bounds.left + (bounds.width - textBounds.width) / 2,
                           bounds.top + (bounds.height - textBounds.height) / 3);
}
