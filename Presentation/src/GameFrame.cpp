#include "GameFrame.h"


GameFrame::GameFrame(sf::RenderWindow *renderWindow):
        renderWindow(renderWindow)
{
    renderTexture.create(initialWidth, initialHeight);
    gameFrameTexture = renderTexture.getTexture();
    gameFrameSprite.setTexture(gameFrameTexture);
    handleResize();

    // Initialize PageManager
    pageManager = new PageManager(&renderTexture);
}

void GameFrame::render() {
    // render page content to the frame
    pageManager->renderPage();

    // Draw the frame
    gameFrameTexture = renderTexture.getTexture();
    gameFrameTexture.setSmooth(true);
    gameFrameSprite.setTexture(gameFrameTexture);
    renderWindow->draw(gameFrameSprite);
}

void GameFrame::update(sf::Time dt) {
    // Update content of the frame
    pageManager->updatePage(dt);

    renderTexture.clear(sf::Color::Magenta);
    renderTexture.display();
}

void GameFrame::handleEvent(const sf::Event &ev) {
    if(ev.type == sf::Event::Resized){
        handleResize();
    }

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*renderWindow);
    sf::Vector2f mousePositionInView = renderWindow->mapPixelToCoords(mousePosition);

    pageManager->handleEvent(ev, gameFrameSprite.getPosition(), mousePositionInView, scaleFactor);
}

void GameFrame::handleResize() {

    unsigned int newHeight = renderWindow->getSize().y;
    unsigned int newWidth = renderWindow->getSize().x;
    scaleFactor = (float)newHeight / gameFrameSprite.getLocalBounds().height;

    gameFrameSprite.setScale(scaleFactor,scaleFactor);
    gameFrameSprite.setPosition({static_cast<float>((float)newWidth / 2 - (float)gameFrameSprite.getGlobalBounds().width / 2),
                                        0});
}
