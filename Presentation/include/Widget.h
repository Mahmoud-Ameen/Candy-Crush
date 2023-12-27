
#ifndef CANDYCRUSH_WIDGET_H
#define CANDYCRUSH_WIDGET_H

#include "Observable.h"
#include <SFML/Graphics.hpp>

class Widget : public Observable{
public:
    virtual void render(sf::RenderWindow*) = 0;
    virtual void handleEvent(sf::Event) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual sf::Rect<float>  getGlobalBounds() = 0;

};

#endif //CANDYCRUSH_WIDGET_H
