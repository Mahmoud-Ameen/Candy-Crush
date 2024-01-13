#include "pages/gameplayPage/pausePopup/pausePopUp.h"

PausePopUp::PausePopUp() {
    backTexture.loadFromFile("../../assets/pauseMenuBackground.png");
    background.setTexture(backTexture);
    background.setScale(0.25f, 0.25f);

    homeButton.addObserver(this);
    playButton.addObserver(this);
    musicButton.addObserver(this);
}

void PausePopUp::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {

    // if the mouse is hovering on the buttons
    if(homeButton.getGlobalBounds().contains(mousePosition)) {
        homeButton.setHovered(true);
        homeButton.handleEvent(ev,mousePosition);
    }
    else
        homeButton.setHovered(false);

    if(musicButton.getGlobalBounds().contains(mousePosition)) {
        musicButton.setHovered(true);
        std::cout << " hovered " ;

        if(ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left){
            musicButton.handleEvent(ev, mousePosition);
        }

    }
    else
        musicButton.setHovered(false);

    if(playButton.getGlobalBounds().contains(mousePosition)) {
        playButton.setHovered(true);
        playButton.handleEvent(ev,mousePosition);
    }
    else
        playButton.setHovered(false);
}

void PausePopUp::render(sf::RenderTarget *renderTarget) {
    background.setPosition(renderTarget->getSize().x/2-background.getGlobalBounds().width/2,
                     renderTarget->getSize().y/2-background.getGlobalBounds().height/2);

    //positioning tthe buttons in their place, yours will probably be entirely different :(
    homeButton.home.setPosition(background.getPosition().x + 50.f, background.getPosition().y + 100.f);
    musicButton.music.setPosition(background.getPosition().x + 280.f, background.getPosition().y + 110.f);
    playButton.play.setPosition(background.getPosition().x + 120.f, background.getPosition().y + 275.f);


    renderTarget->draw(background);
    homeButton.render(renderTarget);
    musicButton.render(renderTarget);
    playButton.render(renderTarget);
}

void PausePopUp::update(sf::Time dt) {

}

sf::Rect<float> PausePopUp::getGlobalBounds() {
    return background.getGlobalBounds();
}

void PausePopUp::onEvent(const std::string &eventName) {
    notifyObservers(eventName);
}

