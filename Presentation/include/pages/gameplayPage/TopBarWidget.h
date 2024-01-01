#ifndef CANDYCRUSH_SIDEBAR_H
#define CANDYCRUSH_SIDEBAR_H

#include "Widget.h"
#include "TemporaryDTOs.h"
#include "LevelInfoWidget.h"

class TopBarWidget: public Widget {
public:
    TopBarWidget(int width, int height);

    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;

private:
    sf::RenderTexture renderTexture;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string imagePath = "../assets/GameStateArea.png";
    BackgroundImage* backgroundImage;
    int levelNumber;
    int remainingMoves;

    LevelInfoWidget* levelInfoWidget;
};


#endif //CANDYCRUSH_SIDEBAR_H
