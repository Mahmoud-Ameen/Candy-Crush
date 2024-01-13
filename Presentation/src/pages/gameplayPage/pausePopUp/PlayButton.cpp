//
// Created by Shady Ali on 02/01/2024.
//

#include "pages/gameplayPage/pausePopup/PlayButton.h"

PlayButton::PlayButton() {
    texture.loadFromFile("../../assets/playButton.png");
    play.setTexture(texture);
    play.scale(0.25f, 0.25f);
}

void PlayButton::render(sf::RenderTarget *renderTarget) {
    if(isHovered) {
        play.setScale(0.3f, 0.3f);
        notifyObservers("clickableHovered");
    }

    else {
        play.setScale(0.25f, 0.25f);
    }

    renderTarget->draw(play);
}

void PlayButton::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {
    if(ev.type == sf::Event::MouseButtonPressed){
        musicPlayer.playANiceSong(false, 100);
        notifyObservers("PlayButtonClicked");
    }
}

void PlayButton::update(sf::Time dt) {

}

sf::Rect<float> PlayButton::getGlobalBounds() {
    return play.getGlobalBounds();
}
