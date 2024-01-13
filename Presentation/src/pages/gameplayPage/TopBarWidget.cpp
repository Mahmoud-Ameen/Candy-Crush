#include "pages/GameplayPage/TopBarWidget.h"
#include "BackgroundImage.h"
#include "../../../../BusinessLayer/public/GameController.h"

TopBarWidget::TopBarWidget(int width, int height) {
    // Initialize Render Area
    renderTexture.create(width, height);
    backgroundImage = new BackgroundImage(imagePath, width, height - 50);

    texture = renderTexture.getTexture();
    sprite.setTexture(texture);

    // Initialize Widgets
    levelInfoWidget = new LevelInfoWidget(renderTexture.getSize().y);
    levelInfoWidget->render(&renderTexture);
}

void TopBarWidget::render(sf::RenderTarget *renderTarget) {
    renderTexture.clear(sf::Color::Transparent);
    backgroundImage->render(&renderTexture);
    levelInfoWidget->render(&renderTexture);
    texture = renderTexture.getTexture();
    sprite.setTexture(texture);
    renderTexture.display();

    renderTarget->draw(sprite);
}

void TopBarWidget::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {

}

void TopBarWidget::update(sf::Time dt) {
    levelInfoWidget->update(dt);
}

sf::Rect<float> TopBarWidget::getGlobalBounds() {
    return sf::Rect<float>();
}

void TopBarWidget::setRemainingMoves(int remainingMoves) {
    levelInfoWidget->setRemainingMoves(remainingMoves);
}
