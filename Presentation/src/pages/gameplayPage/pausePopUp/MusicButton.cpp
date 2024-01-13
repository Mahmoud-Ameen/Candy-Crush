#include "pages/gameplayPage/pausePopup/MusicButton.h"

MusicButton::MusicButton() {
    //loading both textures
    off.loadFromFile("../../assets/musicOffButton.png");
    on.loadFromFile("../../assets/musicOnButton.png");

    //initial mode is music on
    music.setTexture(on);
    music.scale(0.45f, 0.45f);
}

void MusicButton::render(sf::RenderTarget *renderTarget) {
    if(isHovered) {
        //scale up
        music.setScale(0.47f, 0.47f);
        notifyObservers("clickableHovered");
    }

    else {
        //reset the scale
        music.setScale(0.45f, 0.45f);
    }

    renderTarget->draw(music);
}

void MusicButton::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {
    if(music.getTexture() == &on) {
        music.setTexture(off);
        notifyObservers("muteMusic");
    }
    else {
        music.setTexture(on);
        notifyObservers("playMusic");
    }
}

void MusicButton::update(sf::Time dt) {

}

sf::Rect<float> MusicButton::getGlobalBounds() {
    return music.getGlobalBounds();
}

MusicButton::~MusicButton()= default;