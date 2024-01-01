#ifndef CANDYCRUSH_LEVELINFOWIDGET_H
#define CANDYCRUSH_LEVELINFOWIDGET_H


#include "Widget.h"
#include "BackgroundImage.h"

class LevelInfoWidget: public Widget {
public:
    LevelInfoWidget(float height);

    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;

private:

    sf::RenderTexture renderTexture;
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;
    std::string fontPath = "../assets/Roboto/Roboto-Black.ttf";
    sf::Text levelTextObject;
    sf::Text movesTextObject;
    sf::Text movesLabelTextObject;

    std::string levelText;

    std::string imagePath = "../assets/rect.png";
    BackgroundImage* backgroundImage;


    void setTextPosition();

    void initTopBar(int height);
};

#endif //CANDYCRUSH_LEVELINFOWIDGET_H