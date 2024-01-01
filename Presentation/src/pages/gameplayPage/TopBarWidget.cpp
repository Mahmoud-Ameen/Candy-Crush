#include "pages/GameplayPage/TopBarWidget.h"
#include "BackgroundImage.h"

TopBarWidget::TopBarWidget(int width, int height) {
    // TODO: Get Game State From Game Controller having Integrated
    //       with the Business Layer
    levelNumber = 1;
    remainingMoves = 10;

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

void TopBarWidget::handleEvent(sf::Event) {

}

void TopBarWidget::update(sf::Time dt) {

    // Get remaining moves and update text

}

sf::Rect<float> TopBarWidget::getGlobalBounds() {
    return sf::Rect<float>();
}
