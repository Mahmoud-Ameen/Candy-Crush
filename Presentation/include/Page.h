
#ifndef CANDYCRUSH_PAGE_H
#define CANDYCRUSH_PAGE_H

#include <SFML/Graphics.hpp>
#include "Widget.h"

/**
 * @brief The Page class represents an abstract page in the application.
 *
 * This class serves as a base class for pages(screens) of the application.
 * It also implements the Observable and Observer interfaces for event propagation.
 */
class Page: public Observable, public Observer {
public:
    /**
     * @brief Constructs a Page with a specified render target.
     *
     * @param renderTarget The render target on which the page will be drawn.
     */
    explicit Page(sf::RenderTarget* renderTarget) : renderTarget(renderTarget), isActive(false){};

    /**
     * @brief Renders the content of the page.
     *
     * This method must be implemented by derived classes to render the specific content of the page.
     */
    virtual void render() = 0;

    /**
     * @brief Updates the content of the page.
     *
     * @param dt The elapsed time since the last update.
     */
    virtual void update(const sf::Time& dt) = 0;

    /**
     * @brief Handles an SFML event, delegating it to the current page.
     *
     * @param ev The SFML event to be handled.
     * @param originCoords         The coordinates of the origin of the rendering area.
     * @param mousePositionInView  The current mouse position in view coordinates.
     * @param scaleFactor          The scaling factor applied to the rendering area,
     *                             affecting the interpretation of coordinates.
     *
     * @note Depending on the implementation of the current page, the provided parameters
     *       are used to determine how the event should be processed and interacted with
     *       the page's elements.
     */
     virtual void handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords, const sf::Vector2f &mousePositionInView,
                float scaleFactor) = 0;

    /**
     * @brief Sets the activation state of the page.
     *
     * @param active True if the page should be active, false otherwise.
     */
    void setActive(bool active) { isActive = active;};

protected:
    sf::RenderTarget* renderTarget;
    std::vector<Widget*> widgets; ///< The collection of widgets on the page.
    bool isActive;

    void addWidget(Widget* widget){
        widgets.push_back(widget);
    };
};



#endif //CANDYCRUSH_PAGE_H
