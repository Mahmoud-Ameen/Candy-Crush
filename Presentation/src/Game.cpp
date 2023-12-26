#include "Game.h"
#include "GameFrame.h"
#include <iostream>

Game::Game(){
    // Initialize window
    window = new sf::RenderWindow(sf::VideoMode(1200,800),"Candy Crush");
    window->setFramerateLimit(60);

    // Create Background Image
    if(!backgroundImage.loadFromFile(backgroundImagePath)){
        // Handle image failed to load
        std::cerr << "Unable to load BOOT-background_1\n";
    }
    backgroundSprite.setTexture(backgroundImage);
    resizeBackgroundImage(float(window->getSize().x),float(window->getSize().y));

    // Create Game Frame
    gameFrame = new GameFrame(window);
}

void Game::update(const sf::Time &dt) {

    sf::Event ev{};
    while(window->pollEvent(ev)){
        if(ev.type == sf::Event::Closed) window->close();
        else if(ev.type == sf::Event::KeyPressed)
            std::cout << backgroundSprite.getGlobalBounds().width<<" " <<backgroundSprite.getGlobalBounds().height << std::endl;
        else if(ev.type == sf::Event::Resized) {
            resizeBackgroundImage(ev.size.width, ev.size.height);

            // Update window view
            window->setView(sf::View(sf::FloatRect(0, 0,
                                                   static_cast<float>(window->getSize().x),
                                                   static_cast<float>(window->getSize().y))));

            // Inform Widgets about the event
            gameFrame->handleEvent(ev);
        }
    }

    // Update Widgets
    gameFrame->update(dt);
}

void Game::render() {
    window->clear();
    window->draw(backgroundSprite);
    gameFrame->render();
    window->display();
}

bool Game::isRunning() const {
    return window->isOpen();
}

void Game::resizeBackgroundImage(float windowWidth, float windowHeight) {
    // Calculate the scale needed to cover the entire window
    float scaleX = static_cast<float>(windowWidth) / backgroundSprite.getLocalBounds().width;
    float scaleY = static_cast<float>(windowHeight) / backgroundSprite.getLocalBounds().height;

    // Set the scale to cover the window
    // Center the image in the view
    backgroundSprite.setScale(std::max(scaleX,scaleY),std::max(scaleX,scaleY));
    backgroundSprite.setPosition({float(windowWidth) / 2 - backgroundSprite.getGlobalBounds().width / 2,
                                  float(windowHeight) / 2 - backgroundSprite.getGlobalBounds().height / 2});
}

