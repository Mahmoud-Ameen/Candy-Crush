#ifndef CANDY_CRUSH_BOARD_H
#define CANDY_CRUSH_BOARD_H

#include "Observer.h"
#include "Widget.h"
#include "Candies.h"

class Board: public Observer, public Widget{
public:
    Board(float boardLength, sf::Vector2f position);
    void update(sf::Time dt) override;
    void render(sf::RenderTarget* renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    sf::Rect<float>  getGlobalBounds() override;

    void onEvent(const std::string& eventName) override;

private:

    const int rows = 8;
    const int cols = 8;
    std::vector<std::vector<Candies*>> candies;
    sf::RectangleShape board;

    std::pair<int, int> selectedCandy = {-1, -1};

    Candies* c1, *c2;
    bool swapping = false;
    sf::Vector2f initPos1, initPos2;
    float dx, dy;

    void checkCandies(sf::Event ev, sf::Vector2f mousePosition);
    void swapAnimation();



};


#endif //CANDY_CRUSH_BOARD_H
