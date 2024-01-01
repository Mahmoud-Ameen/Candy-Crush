#include "pages/gameplayPage/Board.h"
#include <iostream>
#include <cmath>
Board::Board(float boardLength, sf::Vector2f position) {

    board.setSize(sf::Vector2f(boardLength,boardLength));
    board.setFillColor(sf::Color::Transparent);
//    board.setFillColor(sf::Color(103, 78, 107, 200));
//    board.setOutlineColor(sf::Color(208, 93, 227, 255));
//    board.setOutlineThickness(5.f);
    board.setPosition(position);

    float cellSize = std::min(boardLength / float(cols), boardLength / float(rows));
    candies.resize(rows,std::vector<Candies*>(cols));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            candies[i][j] = new Candies(0, cellSize);
            candies[i][j]->candy.setPosition(board.getGlobalBounds().left + j * cellSize,
                                             board.getGlobalBounds().top + i * cellSize);
        }
    }

}

void Board::render(sf::RenderTarget* renderTarget) {
    renderTarget->draw(this->board);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            candies[i][j]->render(renderTarget);
        }
    }

}

void Board::onEvent(const std::string &eventName) {

}

void Board::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {
    checkCandies(ev, mousePosition);
}

void Board::update(sf::Time dt) {
    if(swapping){
        std::cout << c1->candy.getPosition().x << " ";
        if((std::abs(c1->candy.getPosition().x - initPos2.x) < 1 && std::abs(c1->candy.getPosition().y - initPos2.y) < 1) ||
        (std::abs(c2->candy.getPosition().x - initPos1.x) < 1 && std::abs(c2->candy.getPosition().y - initPos1.y) < 1)){
            swapping = false;

            c1->candy.setPosition(initPos2);
            c2->candy.setPosition(initPos1);
            return;
        }
        c1->candy.move(dx/10, dy/10);
        c2->candy.move(-dx/10,-dy/10);
    }

}

sf::Rect<float> Board::getGlobalBounds() {
    return board.getGlobalBounds();
}

void Board::checkCandies(sf::Event ev, sf::Vector2f mousePosition) {

    if(ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left) {
        std::cout << mousePosition.x << "  " << mousePosition.y << " ";
        //to check if the mouse clicked within the bounds of the candy
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)

                if (candies[i][j]->candy.getGlobalBounds().contains(mousePosition)){

                    if(selectedCandy.first == -1 && selectedCandy.second == -1) {
                        selectedCandy.first = i;
                        selectedCandy.second = j;
                        std::cout << "first one selected" << " ";
                        return;
                    }

                    if(!candies[selectedCandy.first][selectedCandy.second]->candy.getGlobalBounds().contains(mousePosition)) {

                        //it's the second candy to be selected, you gotta->do the swap animation
                        c1 = candies[selectedCandy.first][selectedCandy.second];
                        c2 = candies[i][j];

                        initPos1 = c1->candy.getPosition();
                        initPos2 = c2->candy.getPosition();

                        swapAnimation();
                        selectedCandy = {-1, -1};

                        std::cout << "swapped!" << " ";
                        return;
                    }
                }


        }
    }

}

void Board::swapAnimation() {
    swapping = true;
    dx = c2->candy.getPosition().x - c1->candy.getPosition().x;
    dy = c2->candy.getPosition().y - c1->candy.getPosition().y;

    std::cout << " moved  ";
}




