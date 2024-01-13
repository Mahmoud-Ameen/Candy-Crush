//
// Created by Shady Ali on 02/01/2024.
//

#ifndef CANDYCRUSH_HOMEBUTTON_H
#define CANDYCRUSH_HOMEBUTTON_H


#include "Widget.h"
#include "MusicPlayer.h"
#include <iostream>

class HomeButton: public Widget{
    sf::Texture texture;

public:
    sf::Sprite home;

    HomeButton();
    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;
};


#endif //CANDYCRUSH_HOMEBUTTON_H
