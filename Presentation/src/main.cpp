#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main(){

    Game game;
    sf::Clock clock;
    sf::Time deltaTime;
    while(game.isRunning()){
       game.update(deltaTime);
       game.render();

       deltaTime = clock.restart();
    }

}