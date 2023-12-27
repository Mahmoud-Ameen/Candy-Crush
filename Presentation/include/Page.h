
#ifndef CANDYCRUSH_PAGE_H
#define CANDYCRUSH_PAGE_H

#include <SFML/Graphics.hpp>
#include "Widget.h"

class Page: public Observable, public Observer {
public:
    explicit Page(sf::RenderTarget* renderTarget) : renderTarget(renderTarget), isActive(false){};
    virtual void render() = 0;
    virtual void update(const sf::Time& dt) = 0;
    virtual void handleEvent(const sf::Event&) = 0;
    void setActive(bool active) { isActive = active;};

private:
    sf::RenderTarget* renderTarget;
    std::vector<Widget*> widgets;
    bool isActive;
};



#endif //CANDYCRUSH_PAGE_H
