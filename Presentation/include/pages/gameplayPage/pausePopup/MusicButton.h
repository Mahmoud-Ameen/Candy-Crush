//
// Created by Shady Ali on 02/01/2024.
//

#ifndef CANDYCRUSH_MUSICBUTTON_H
#define CANDYCRUSH_MUSICBUTTON_H


#include "Widget.h"
#include "MusicPlayer.h"

class MusicButton: public Widget {
    //to switch between music on and off when clicked on it
    sf::Texture off, on;

public:
    sf::Sprite music;

    MusicButton();
    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;
    ~MusicButton();
};


#endif //CANDYCRUSH_MUSICBUTTON_H
