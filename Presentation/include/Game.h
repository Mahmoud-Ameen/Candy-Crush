#ifndef CANDYCRUSH_GAME_H
#define CANDYCRUSH_GAME_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameFrame.h"
#include "BackgroundImage.h"

/*
 * Main Class Responsible for App Display and Behavior
 * */
class Game {
public:
    Game();
    void update(const sf::Time& dt);
    void render();

    [[nodiscard]] bool isRunning() const;

private:
    sf::RenderWindow* window;

    // BackgroundImage
    std::string backgroundImagePath =
            //"../assets/video-game-candy-crush-soda-saga-wallpaper-preview.png";
//            "../../assets/wp2347628-candy-crush-saga-wallpapers.jpg";
                "../../assets/background4.jpg";
    BackgroundImage* backgroundImage;

    // Game Frame
    GameFrame* gameFrame;
};


#endif //CANDYCRUSH_GAME_H
