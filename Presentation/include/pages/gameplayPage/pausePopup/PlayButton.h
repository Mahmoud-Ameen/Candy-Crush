//
// Created by Shady Ali on 02/01/2024.
//

#ifndef CANDYCRUSH_PLAYBUTTON_H
#define CANDYCRUSH_PLAYBUTTON_H


#include "Widget.h"
#include "MusicPlayer.h"

class PlayButton: public Widget {
    sf::Texture texture;

    MusicPlayer musicPlayer = {"../../assets/play_button.mp3"};

public:
    sf::Sprite play;

    PlayButton();
    void render(sf::RenderTarget *renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;
};


#endif //CANDYCRUSH_PLAYBUTTON_H
