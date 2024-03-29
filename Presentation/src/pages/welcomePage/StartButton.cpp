#include <iostream>
#include "pages/welcomePage/StartButton.h"


StartButton::StartButton(){
    // Load Image
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Error loading image from file: " << imagePath << std::endl;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
//    sprite.setScale(0.75,0.75);
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
        sprite.setColor({255, 255, 255, 240});
    else
        sprite.setColor({255,255,255,255});

    renderTarget->draw(sprite);
    renderTarget->draw(textObject);
}

void StartButton::handleEvent(sf::Event event, sf::Vector2f mousePosition) {
    if(event.type == sf::Event::MouseButtonPressed) {
        notifyObservers("startButtonClicked");
//        musicPlayer.playANiceSong(false,100);
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
