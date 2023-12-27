#include <iostream>
#include "pages/welcomePage/StartButton.h"


StartButton::StartButton(){

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
    textObject.setString(text);
    textObject.setCharacterSize(48);
    textObject.setStyle(sf::Text::Bold);
    textObject.setFillColor(sf::Color::Black);

}

void StartButton::render(sf::RenderTarget* renderTarget) {

    sprite.setPosition({(float)renderTarget->getSize().x / 2 - sprite.getGlobalBounds().width / 2,
                        (float)renderTarget->getSize().y / 2.f });
    setTextPosition();

    if(isHovered)
        sprite.setColor({255, 255, 255, 200});
    else
        sprite.setColor({255,255,255,255});

    renderTarget->draw(sprite);
    renderTarget->draw(textObject);
}

void StartButton::handleEvent(sf::Event event)  {
    if(event.type == sf::Event::MouseButtonPressed) {
        notifyObservers("startButtonClicked");
    }
}

void StartButton::update(sf::Time dt) {

}

sf::Rect<float> StartButton::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void StartButton::setTextPosition() {
    sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = textObject.getGlobalBounds();
    textObject.setPosition(bounds.left + (bounds.width - textBounds.width) / 2,
                              bounds.top + (bounds.height - textBounds.height) / 3);
}
