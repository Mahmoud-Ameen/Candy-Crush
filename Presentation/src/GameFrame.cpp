#include "GameFrame.h"


GameFrame::GameFrame(sf::RenderTarget *renderTarget): renderTarget(renderTarget) {
    renderTexture.create(initialWidth, initialHeight);
    gameFrameTexture = renderTexture.getTexture();
    gameFrameSprite.setTexture(gameFrameTexture);
    handleResize();
}

void GameFrame::render() {
    // Render content of the frame
    gameFrameTexture = renderTexture.getTexture();
    gameFrameSprite.setTexture(gameFrameTexture);
    renderTarget->draw(gameFrameSprite);
}

void GameFrame::update(sf::Time) {
    // Update content of the frame
    renderTexture.clear();
    renderTexture.display();
}

void GameFrame::handleEvent(const sf::Event &ev) {
    if(ev.type == sf::Event::Resized){
        handleResize();
    }
}

void GameFrame::handleResize() {

    unsigned int newHeight = renderTarget->getSize().y;
    unsigned int newWidth = renderTarget->getSize().x;
    float scaleFactor = (float)newHeight / gameFrameSprite.getLocalBounds().height;

    gameFrameSprite.setScale(scaleFactor,scaleFactor);
    gameFrameSprite.setPosition({static_cast<float>((float)newWidth / 2 - (float)gameFrameSprite.getGlobalBounds().width / 2),
                                        0});
}
