#ifndef CANDY_CRUSH_BOARD_H
#define CANDY_CRUSH_BOARD_H

#include "Observer.h"
#include "Widget.h"
#include "CandyWidget.h"
#include "MusicPlayer.h"

class BoardWidget: public Observer, public Widget{
public:
    BoardWidget(float boardLength, sf::Vector2f position);
    void update(sf::Time dt) override;
    void render(sf::RenderTarget* renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    sf::Rect<float>  getGlobalBounds() override;

    void onEvent(const std::string& eventName) override;

    void matchingAnimation(const std::vector<std::pair<int, int>>& matchedIndices);
    void gravityAnimation(const std::vector<std::pair<int,int>>& fallingIndices, const std::vector<int>& fallDistance);
    void setBoard(std::vector<std::vector<DTOs::CandyType>> &board);

private:

    int rows = 8;
    int cols = 8;
    float cellSize;
    std::vector<std::vector<CandyWidget*>> candies;
    sf::RectangleShape board;

    // Swap Animation
    bool swapping = false;
    CandyWidget* c1 = nullptr, *c2 = nullptr;
    std::pair<int, int> selectedCandy = {-1, -1};
    sf::Vector2f initPos1, initPos2;
    float dx, dy;

    //selection animation
    bool selectionGhosting = false;
    sf::Color initColor;
    sf::Color dc = initColor;
    float opacity = 5.f;

    void swapAnimation();
    void handleClick(sf::Event ev, sf::Vector2f mousePosition);

    bool popping = false;
    float poppingTimer = 0.75;


    MusicPlayer musicPlayer = {"../../assets/swap.mp3"};

};


#endif //CANDY_CRUSH_BOARD_H
