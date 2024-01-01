#ifndef CANDYCRUSH_CANDIES_H
#define CANDYCRUSH_CANDIES_H

#include <SFML/Graphics.hpp>
#include "Observable.h"

class Candies: public Observable{
//the candy will need to know from the business layer which kind it is

sf::Texture texture;
Observable observable;

public:
    sf::Sprite candy;

    Candies(int type, float size);
    void render(sf::RenderTarget* renderTarget);

    float size;
};


#endif //CANDYCRUSH_CANDIES_H
