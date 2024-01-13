#ifndef CANDYCRUSH_LEVELINFOWIDGET_H
#define CANDYCRUSH_LEVELINFOWIDGET_H


#include "Widget.h"
#include "BackgroundImage.h"

class LevelInfoWidget: public Widget {
public:
    LevelInfoWidget(float height);

    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;

    void setRemainingMoves(int inputRemainingMoves);


private:
    int levelNumber;
    int remainingMoves;

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

    void initWidget(int height);
};

#endif //CANDYCRUSH_LEVELINFOWIDGET_H