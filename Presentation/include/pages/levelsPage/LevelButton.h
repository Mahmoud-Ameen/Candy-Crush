#ifndef CANDYCRUSH_LEVELBUTTON_H
#define CANDYCRUSH_LEVELBUTTON_H

#include "Widget.h"

class LevelButton : public Widget {
public:
    explicit LevelButton(int levelNumber);

    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;

private:
    int levelNumber;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;
    std::string fontPath = "../assets/Architects_Daughter/ArchitectsDaughter-Regular.ttf";
    sf::Text textObject;

    std::string text = "Start";
    std::string imagePath = "../assets/btn-orange3.png";

    void setTextPosition();

};

#endif //CANDYCRUSH_LEVELBUTTON_H
