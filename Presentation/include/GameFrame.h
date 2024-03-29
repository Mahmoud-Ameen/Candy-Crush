
#ifndef CANDYCRUSH_GAMEFRAME_H
#define CANDYCRUSH_GAMEFRAME_H

#include <SFML/Graphics.hpp>
#include "PageManager.h"
#include "MusicPlayer.h"

/**
 * @brief The GameFrame class represents the central frame/widget where screens(pages) would be rendered.
 *
 * This frame has a fixed aspect ratio and is drawn onto a specified render target.
 */
class GameFrame: public Observer {
public:
    explicit GameFrame(sf::RenderWindow *renderWindow);
    /**
     * @brief Renders the GameFrame onto the specified render target.
     */
    void render();
    /**
     * @brief Updates the content of the GameFrame.
     *
     * @param dt The elapsed time since the last update.
     */
    void update(sf::Time);
    /**
     * @brief Handles events related to the GameFrame.
     *
     * @param ev The event to be handled.
     */
    void handleEvent(const sf::Event &ev);

    void onEvent(const std::string &eventName) override;
private:
    sf::RenderWindow* renderWindow; ///< The render target on which the GameFrame is drawn.

    sf::RenderTexture renderTexture; ///< The render texture used for drawing the GameFrame.
    sf::Texture gameFrameTexture;    ///< The texture containing the GameFrame content.
    sf::Sprite gameFrameSprite;      ///< The sprite used for rendering the GameFrame.

    unsigned int initialHeight = 800;
    unsigned int initialWidth = 600;
    float scaleFactor = 1;

    /**
     * @brief Handles resizing of the GameFrame.
     *
     * Adjusts the scale and position of the GameFrame sprite when the render target is resized.
     */
    void handleResize();

    PageManager* pageManager;

    MusicPlayer musicPlayer = {"../../assets/welcome_music.mp3"};
};


#endif //CANDYCRUSH_GAMEFRAME_H
