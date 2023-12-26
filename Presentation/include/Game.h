#ifndef CANDYCRUSH_GAME_H
#define CANDYCRUSH_GAME_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

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
    std::string backgroundImagePath = "../assets/BOOT-background_1.jpg";
    sf::Texture backgroundImage;
    sf::Sprite backgroundSprite;
    void resizeBackgroundImage(float windowWidth, float windowHeight);

    //
};


#endif //CANDYCRUSH_GAME_H
