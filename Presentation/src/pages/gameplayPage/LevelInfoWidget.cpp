#include <iostream>
#include "pages/gameplayPage/LevelInfoWidget.h"
#include "BackgroundImage.h"

LevelInfoWidget::LevelInfoWidget(float height) {
    if(!texture.loadFromFile(imagePath)){
        std::cerr << "Error loading image " << imagePath << std::endl;
    }

    if(!font.loadFromFile(fontPath)){
        std::cerr << "Error loading Font " << fontPath << std::endl;
    }


    initTopBar(height);
    renderTexture.create(260,185);
    texture = renderTexture.getTexture();
    sprite.setTexture(texture);
    setTextPosition();
}

void LevelInfoWidget::initTopBar(int height) {
    int levelNumber = 5;
    int remainingMoves = 26;

    backgroundImage = new BackgroundImage(imagePath,260,height);
    levelText = "Level " + std::to_string(levelNumber);
    levelTextObject.setString(levelText);
    levelTextObject.setFont(font);
    levelTextObject.setCharacterSize(20);
    levelTextObject.setFillColor({170,95,37});
    levelTextObject.setStyle(sf::Text::Bold);

    movesTextObject.setString(std::to_string(remainingMoves));
    movesTextObject.setFont(font);
    movesTextObject.setFillColor({255,255,255});
    movesTextObject.setOutlineColor(sf::Color(0,0,0,175));
    movesTextObject.setOutlineThickness(3);
    movesTextObject.setStyle(sf::Text::Style::Bold);
    movesTextObject.setCharacterSize(60 );

    movesLabelTextObject.setString("Moves");
    movesLabelTextObject.setFont(font);
    movesLabelTextObject.setFillColor({255,255,255});
    movesLabelTextObject.setCharacterSize(20 );
}

void LevelInfoWidget::render(sf::RenderTarget *renderTarget) {


    renderTexture.clear(sf::Color::Transparent);
    backgroundImage->render(&renderTexture);
    renderTexture.draw(levelTextObject);
    renderTexture.draw(movesTextObject);
    renderTexture.draw(movesLabelTextObject);
    renderTexture.display();

    texture = renderTexture.getTexture();
    texture.setSmooth(true);
    sprite.setTexture(texture);

    float scaleFactor = 0.9;
    sprite.setScale(scaleFactor,scaleFactor);

    sprite.setPosition(renderTarget->getSize().x/2-renderTexture.getSize().x * scaleFactor/2,0);

    renderTarget->draw(sprite);
}

void LevelInfoWidget::handleEvent(sf::Event) {

}

void LevelInfoWidget::update(sf::Time dt) {

}

sf::Rect<float> LevelInfoWidget::getGlobalBounds() {
    return sf::Rect<float>();
}

void LevelInfoWidget::setTextPosition() {
    sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = levelTextObject.getGlobalBounds();
    levelTextObject.setPosition(bounds.left + (bounds.width - textBounds.width) / 2,
                           bounds.top + 10);

    movesTextObject.setPosition(bounds.left + (bounds.width - movesTextObject.getGlobalBounds().width) / 2,
                                levelTextObject.getPosition().y + levelTextObject.getGlobalBounds().height + 10);

    movesLabelTextObject.setPosition(bounds.left + (bounds.width - movesLabelTextObject.getGlobalBounds().width) / 2,
                                movesTextObject.getPosition().y + movesTextObject.getGlobalBounds().height + 25);

}
