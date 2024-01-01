#include <iostream>
#include "pages/gameplayPage/Candies.h"

Candies::Candies(int type, float size): size(size) {
    if(!texture.loadFromFile("../../assets/gem-red.png"))
        std::cerr<<"error loading " << "../../assets/gem-red.png\n";

    candy.setTexture(texture);
    candy.scale(size/texture.getSize().x, size/texture.getSize().y);
}

void Candies::render(sf::RenderTarget* renderTarget) {
    renderTarget->draw(candy);
}

