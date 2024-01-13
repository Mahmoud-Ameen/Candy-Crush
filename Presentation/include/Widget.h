
#ifndef CANDYCRUSH_WIDGET_H
#define CANDYCRUSH_WIDGET_H

#include "Observable.h"
#include <SFML/Graphics.hpp>

/**
 * @brief The Widget class represents an abstract UI element.
 *
 * This class defines the interface for UI elements.
 * Derived classes must implement these methods based on
 * their specific UI functionality.
 */
class Widget : public Observable{
public:
    /**
     * @brief Renders the widget on a specified SFML render target.
     * Derived classes must implement this method to define the rendering logic for the widget.
     *
     * @param renderTarget The SFML render target on which the widget will be rendered.
     */
    virtual void render(sf::RenderTarget* renderTarget) = 0;

    /**
     * @brief Handles a specific SFML event for the widget.
     * Derived classes must implement this method to handle events relevant to the widget's functionality.
     * @param event The SFML event to be handled.
     */
    virtual void handleEvent(sf::Event ev, sf::Vector2f mousePosition) = 0;

    /**
     * @brief Updates the internal state of the widget.
     *
     * Derived classes must implement this method to update the widget's state based on the elapsed time.
     *
     * @param dt The elapsed time since the last update.
     */
    virtual void update(sf::Time dt) = 0;

    /**
     * @brief Gets the global bounding rectangle of the widget.
     *
     * Derived classes must implement this method to return the global bounding rectangle of the widget.
     *
     * @return The global bounding rectangle of the widget.
     */
    virtual sf::Rect<float>  getGlobalBounds() = 0;

    void setHovered(bool hovered){isHovered = hovered;}
protected:
    bool isHovered = false;
};

#endif //CANDYCRUSH_WIDGET_H
