#ifndef CANDYCRUSH_SIDEBAR_H
#define CANDYCRUSH_SIDEBAR_H

#include "Widget.h"
#include "LevelInfoWidget.h"

class TopBarWidget: public Widget {
public:
    TopBarWidget(int width, int height);

    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void render(sf::RenderTarget *renderTarget) override;
    sf::Rect<float> getGlobalBounds() override;
    void update(sf::Time dt) override;

    void setRemainingMoves(int remainingMoves);

private:
    sf::RenderTexture renderTexture;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string imagePath = "../assets/GameStateArea.png";
    BackgroundImage* backgroundImage;

    LevelInfoWidget* levelInfoWidget;
};


#endif //CANDYCRUSH_SIDEBAR_H
