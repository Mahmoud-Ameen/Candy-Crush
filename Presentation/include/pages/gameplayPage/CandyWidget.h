#ifndef CANDYCRUSH_CANDYWIDGET_H
#define CANDYCRUSH_CANDYWIDGET_H

#include <SFML/Graphics.hpp>
#include "Observable.h"
#include "../../../../BusinessLayer/public/DTOs.h"

class CandyWidget: public Observable{
sf::Texture texture;
public:
    sf::Sprite candy;
    bool isPopping = false;
    bool isMoving = false;
    sf::Clock animationClock;

    CandyWidget(DTOs::CandyType candyType, float size);
    void render(sf::RenderTarget* renderTarget);
    float size;

    void pop();
    // Moving Animation
    // i.e. swapping, gravity fall, etc
    void animateMovement(const sf::Vector2f &destination, float time);
    float deltaX = 0,
            deltaY = 0,
            dx = 0, dy = 0;
    float animationTime = 0;
};


#endif //CANDYCRUSH_CANDYWIDGET_H
