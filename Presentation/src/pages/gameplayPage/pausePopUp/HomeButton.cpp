#include "pages/gameplayPage/HomeButton.h"

HomeButton::HomeButton() {
    texture.loadFromFile("../../assets/homeButton.png");
    texture.setSmooth(true);
    home.setTexture(texture);
    home.scale(0.4f, 0.4f);
}

void HomeButton::render(sf::RenderTarget *renderTarget) {

    if(isHovered) {
        home.setScale(0.45f, 0.45f);
        notifyObservers("clickableHovered");
    }

    else {
        home.setScale(0.4f, 0.4f);
    }
    renderTarget->draw(home);
}

void HomeButton::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {
    if(ev.type == sf::Event::MouseButtonPressed){
        notifyObservers("HomeButtonClicked");
        MusicPlayer musicPlayer = {"../../assets/click.mp3"};
    }
}

void HomeButton::update(sf::Time dt) {

}

sf::Rect<float> HomeButton::getGlobalBounds() {
    return home.getGlobalBounds();
}
