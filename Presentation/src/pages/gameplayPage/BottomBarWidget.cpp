#include "pages/gameplayPage/BottomBarWidget.h"
#include "pages/gameplayPage/ObjectiveWidget.h"
#include "../../../../BusinessLayer/public/GameController.h"


BottomBarWidget::BottomBarWidget(int width, int height) {
    // TODO: Get Game State From Game Controller having Integrated
    //       with the Business Layer

    // Initialize Render Area
    renderTexture.create(width, height);
    backgroundImage = new BackgroundImage(imagePath, width, height);

    texture = renderTexture.getTexture();
    sprite.setTexture(texture);

    // Initialize Widgets

    objectives = GameController::getInstance().getObjectives();
    setObjectives(objectives);

}

void BottomBarWidget::render(sf::RenderTarget *renderTarget) {
    sprite.setPosition(0,(float) (renderTarget->getSize().y - renderTexture.getSize().y));

    backgroundImage->render(&renderTexture);
    for (auto obj:objectiveWidgets) {
        obj->render(&renderTexture);
    }

    texture = renderTexture.getTexture();
    sprite.setTexture(texture);

    renderTexture.display();

    renderTarget->draw(sprite);
}

void BottomBarWidget::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {

}

void BottomBarWidget::setObjectives(std::vector<DTOs::ObjectiveInfo>& objs){
    for (auto wid:objectiveWidgets)
        delete wid;
    objectiveWidgets.clear();

    objectives = objs;
    float widthWithPadding = 115;
    float start = ((float)renderTexture.getSize().x - ((float)objectives.size()*widthWithPadding)) / 2.0f;
    for (int i = 0; i < objectives.size(); i++) {
        objectiveWidgets.push_back(new ObjectiveWidget(objectives[i], start + (float)i*widthWithPadding));
    }
}

void BottomBarWidget::update(sf::Time dt) {
    // Get remaining moves and update text
}

sf::Rect<float> BottomBarWidget::getGlobalBounds() {
    return sf::Rect<float>();
}
