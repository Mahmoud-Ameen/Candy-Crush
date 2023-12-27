
#ifndef CANDYCRUSH_PAGEMANAGER_H
#define CANDYCRUSH_PAGEMANAGER_H

#include "Page.h"

/**
 * @brief The PageManager class is responsible for managing pages in the game.
 *
 * This class manages switching between pages, rendering the current page,
 * updating the current page, and handling events.
 */
class PageManager: public Observer {
public:
    explicit PageManager(sf::RenderTarget* renderTarget);

    /**
     * @brief Renders the current page on the specified render target.
     */
    void renderPage();

    /**
     * @brief Updates the current page based on the elapsed time.
     *
     * @param dt The elapsed time since the last update.
     */
    void updatePage(const sf::Time &dt);

    /**
     * @brief Handles an SFML event, delegating it to the current page.
     *
     * @param event The SFML event to be handled.
     */
    void handleEvent(const sf::Event& event);

    /**
     * @brief Overrides the onEvent method to respond to events triggered by pages.
     *
     * @param eventName The name or identifier of the event.
     */
    void onEvent(const std::string& eventName) override;

private:
    sf::RenderTarget* renderTarget; // Render target to draw the pages on
    std::vector<Page*> pages;       // Application Pages
    int currentPageIndex = 0;       // Index of current active page

    /**
     * @brief Adds a new page to the PageManager.
     *
     * @param page A pointer to the page to be added.
     */
    void addPage(Page* page);

    /**
     * @brief Switches to the page at the specified index.
     *
     * @param index The index of the page to switch to.
     */
    void switchToPage(int index);
};


#endif //CANDYCRUSH_PAGEMANAGER_H
