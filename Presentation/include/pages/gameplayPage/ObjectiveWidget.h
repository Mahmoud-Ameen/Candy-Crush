#ifndef CANDYCRUSH_OBJECTIVEWIDGET_H
#define CANDYCRUSH_OBJECTIVEWIDGET_H

#include <unordered_map>
#include "Widget.h"
#include "BackgroundImage.h"
#include "../../../../BusinessLayer/public/DTOs.h"

class ObjectiveWidget{
public:
    explicit ObjectiveWidget(DTOs::ObjectiveInfo objectiveInfo, int number);
    void render(sf::RenderTarget *renderTarget);
    void update(sf::Time dt);
    void handleEvent(sf::Event);
    sf::Rect<float> getGlobalBounds();

private:
    int xPos;
    std::unordered_map<DTOs::CandyType,std::string> imagePaths;

    sf::Sprite containerSprite;
    sf::RenderTexture containerTexture;
    sf::Texture texture;
    BackgroundImage* background;

    sf::Texture gemImage;
    sf::Sprite gemSprite;

    sf::Text text;
    sf::Font font;

    float width = 70,height = 70;
    void initImagePaths();
};


#endif //CANDYCRUSH_OBJECTIVEWIDGET_H
