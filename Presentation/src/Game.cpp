#include "Game.h"
#include "GameFrame.h"
#include <iostream>

Game::Game(){
    // Initialize window
    window = new sf::RenderWindow(sf::VideoMode(1200,800),"Candy Crush");
    window->setFramerateLimit(60);

    // Initialize Background Image
    backgroundImage = new BackgroundImage(backgroundImagePath,window->getSize().x,window->getSize().y);

    // Create Game Frame
    gameFrame = new GameFrame(window);
}

void Game::update(const sf::Time &dt) {

    sf::Event ev{};
    while(window->pollEvent(ev)){
        if(ev.type == sf::Event::Closed) window->close();
        else if(ev.type == sf::Event::Resized) {
            backgroundImage->handleImageResize(ev.size.width,ev.size.height);

            // Update window view
            window->setView(sf::View(sf::FloatRect(0, 0,
                                                   static_cast<float>(window->getSize().x),
                                                   static_cast<float>(window->getSize().y))));
        }
        // Inform Widgets about the event
        gameFrame->handleEvent(ev);
    }

    // Update Widgets
    gameFrame->update(dt);
}

void Game::render() {
    window->clear();
    backgroundImage->render(window);
    gameFrame->render();
    window->display();
}

bool Game::isRunning() const {
    return window->isOpen();
}
