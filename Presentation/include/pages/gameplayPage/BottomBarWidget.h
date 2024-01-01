#ifndef CANDYCRUSH_BOTTOMBARWIDGET_H
#define CANDYCRUSH_BOTTOMBARWIDGET_H

#include "Widget.h"
#include "TemporaryDTOs.h"
#include "BackgroundImage.h"
#include "ObjectiveWidget.h"

class BottomBarWidget: public Widget {
public:
    BottomBarWidget(int width, int height);

    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;

private:
    sf::RenderTexture renderTexture;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string imagePath = "../../assets/ObjectivesArea.png";
    BackgroundImage* backgroundImage;

    std::vector<ObjectiveInfo> objectives;
    std::vector<ObjectiveWidget*> objectiveWidgets;
};



#endif //CANDYCRUSH_BOTTOMBARWIDGET_H
