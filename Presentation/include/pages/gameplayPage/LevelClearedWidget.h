
#ifndef CANDYCRUSH_LEVELCLEAREDWIDGET_H
#define CANDYCRUSH_LEVELCLEAREDWIDGET_H


#include "Widget.h"
#include "HomeButton.h"

class LevelClearedWidget : public Observer, public Observable {
public:
    void render(sf::RenderTarget *renderTarget);
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition);

    LevelClearedWidget();

    void onEvent(const std::string &eventName) override;
private:
    sf::Texture texture;
    std::string imagePath = "../../assets/GameWonPopup.png";

    sf::Sprite sprite;

    HomeButton homeButton;
};


#endif //CANDYCRUSH_LEVELCLEAREDWIDGET_H
