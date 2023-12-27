#ifndef CANDYCRUSH_BACKGROUNDIMAGE_H
#define CANDYCRUSH_BACKGROUNDIMAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief The BackgroundImage class represents a background image that maintains
 * its aspect ratio while covering a target area.
 */
class BackgroundImage {
public:
    /**
     * @brief Constructs a BackgroundImage object with the specified image file,
     * target width, and target height.
     *
     * @param imagePath The path to the image file.
     * @param targetWidth The target width to cover.
     * @param targetHeight The target height to cover.
     */
    BackgroundImage(const std::string& imagePath, float targetWidth, float targetHeight) {
        if (!texture.loadFromFile(imagePath)) {
            std::cerr << "Error loading " << imagePath << "\n";
        }

        sprite.setTexture(texture);
        handleImageResize(targetWidth, targetHeight);
    }

    /**
     * @brief Renders the background image on the provided render target.
     *
     * @param target The render target to draw the background image on.
     */
    void render(sf::RenderTarget* target) {
        target->draw(sprite);
    }

    /**
     * @brief Handles resizing the background image to cover the specified
     * target width and height while maintaining its aspect ratio.
     *
     * @param targetWidth The target width to cover.
     * @param targetHeight The target height to cover.
     */
    void handleImageResize(float targetWidth, float targetHeight) {
        // Calculate the scale needed to cover the entire window
        float scaleX = static_cast<float>(targetWidth) / sprite.getLocalBounds().width;
        float scaleY = static_cast<float>(targetHeight) / sprite.getLocalBounds().height;

        // Set the scale to cover the window
        // Center the image in the view
        sprite.setScale(std::max(scaleX,scaleY),std::max(scaleX,scaleY));
        sprite.setPosition({float(targetWidth) / 2 - sprite.getGlobalBounds().width / 2,
                                      float(targetHeight) / 2 - sprite.getGlobalBounds().height / 2});
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};



#endif //CANDYCRUSH_BACKGROUNDIMAGE_H
