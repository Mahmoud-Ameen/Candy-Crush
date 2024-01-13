//
// Created by MAHMOUD on 1/3/2024.
//

#ifndef CANDYCRUSH_LEVELLOSTWIDGET_H
#define CANDYCRUSH_LEVELLOSTWIDGET_H


#include "Widget.h"
#include "pages/gameplayPage/HomeButton.h"

class LevelLostWidget: public Observer,public Observable {
public:
    void render(sf::RenderTarget *renderTarget);
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition);

    LevelLostWidget();

    void onEvent(const std::string& eventName) override;
private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string imagePath = "../../assets/gameLostPopup.png";

    HomeButton homeButton;
};

#endif //CANDYCRUSH_LEVELLOSTWIDGET_H
