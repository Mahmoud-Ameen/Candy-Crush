#ifndef CANDYCRUSH_STARTBUTTON_H
#define CANDYCRUSH_STARTBUTTON_H


#include "Widget.h"

class StartButton: public Widget {
public:
    StartButton();

    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;

private:

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;
    std::string fontPath = "../assets/Architects_Daughter/ArchitectsDaughter-Regular.ttf";
    sf::Text textObject;

    std::string text = "Start";
    std::string imagePath = "../assets/btn-orange2.png";

    void setTextPosition();

};


#endif //CANDYCRUSH_STARTBUTTON_H
