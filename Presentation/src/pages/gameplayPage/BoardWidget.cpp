#include "pages/gameplayPage/BoardWidget.h"
#include "../../../../BusinessLayer/public/GameController.h"
#include <iostream>
#include <cmath>
BoardWidget::BoardWidget(float boardLength, sf::Vector2f position) {

    board.setSize(sf::Vector2f(boardLength,boardLength));
    board.setFillColor(sf::Color::Transparent);
    board.setPosition(position);

    cols = GameController::getInstance().getCols();
    rows = GameController::getInstance().getRows();

    cellSize = std::min(boardLength / float(cols), boardLength / float(rows));
    candies.resize(rows,std::vector<CandyWidget*>(cols  , nullptr));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            candies[i][j] = new CandyWidget(GameController::getInstance().getCandyAt(i, j), cellSize);
            candies[i][j]->candy.setPosition(board.getGlobalBounds().left + j * cellSize,
                                             board.getGlobalBounds().top + i * cellSize);
        }
    }

}

void BoardWidget::setBoard(std::vector<std::vector<DTOs::CandyType>> &inputBoard) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            if(candies[i][j]) delete candies[i][j];

            candies[i][j] = new CandyWidget(inputBoard[i][j], cellSize);
            candies[i][j]->candy.setPosition(board.getGlobalBounds().left + j * cellSize,
                                             board.getGlobalBounds().top + i * cellSize);
        }
    }
}

void BoardWidget::render(sf::RenderTarget* renderTarget) {
    renderTarget->draw(this->board);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            candies[i][j]->render(renderTarget);
        }
    }
}

void BoardWidget::onEvent(const std::string &eventName) {

}

void BoardWidget::handleEvent(sf::Event ev, sf::Vector2f mousePosition) {
    if(ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
        handleClick(ev, mousePosition);
}

void BoardWidget::update(sf::Time dt) {
    if(selectionGhosting && !swapping && selectedCandy.first != -1 && selectedCandy.second != -1){
        if(dc.a <= 70) {
            c1->candy.setColor(initColor);
            dc = initColor;
        }
        else
        {
            dc.a -= opacity;
            c1->candy.setColor(dc);
        }

    }
    //resets the candy opacity
    else if(c1 != nullptr)
        c1->candy.setColor(initColor);


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
    if(popping){
        poppingTimer-=0.02;
        if(poppingTimer<=0) {
            poppingTimer = 0.75;
            popping = false ;
            notifyObservers("matchingAnimationFinished");
        }
    }
}

sf::Rect<float> BoardWidget::getGlobalBounds() {
    return board.getGlobalBounds();
}

void BoardWidget::handleClick(sf::Event ev, sf::Vector2f mousePosition) {

    std::cout << mousePosition.x << "  " << mousePosition.y << " ";
    //to check if the mouse clicked within the bounds of a candy
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!candies[i][j]->candy.getGlobalBounds().contains(mousePosition))
                continue;

            // First Candy to be Selected
            if (selectedCandy.first == -1 && selectedCandy.second == -1) {
                selectedCandy.first = i;
                selectedCandy.second = j;

                //first candy to be selected, it will start selectionGhosting in its place until another one is selected
                initColor = candies[selectedCandy.first][selectedCandy.second]->candy.getColor();
                c1 = candies[selectedCandy.first][selectedCandy.second];
                selectionGhosting = true;
                return;
            }

            // Same Candy Clicked Twice
            if (candies[selectedCandy.first][selectedCandy.second]->candy.getGlobalBounds().contains(mousePosition))
                return;

            // Second Candy selected but it's an illegal swap
            if(!GameController::getInstance().isValidSwap(selectedCandy.first,selectedCandy.second,i,j)){
                selectedCandy = {-1,-1};
                return;
            };

            //it's the second candy to be selected, perform swap
            c1 = candies[selectedCandy.first][selectedCandy.second];
            c2 = candies[i][j];

            initPos1 = c1->candy.getPosition();
            initPos2 = c2->candy.getPosition();

            //it should stop selectionGhosting because another one was selected
            selectionGhosting = false;

            //swap sound
            musicPlayer.playANiceSong(false, 50);

            swapAnimation();
            GameController::getInstance().swapCandies(selectedCandy.first,selectedCandy.second,i,j);
            std::swap(candies[selectedCandy.first][selectedCandy.second],candies[i][j]);

            selectedCandy = {-1, -1};

            return;
        }
    }
    
}

void BoardWidget::swapAnimation() {
    swapping = true;
    dx = c2->candy.getPosition().x - c1->candy.getPosition().x;
    dy = c2->candy.getPosition().y - c1->candy.getPosition().y;
}

void BoardWidget::matchingAnimation(const std::vector<std::pair<int, int>>& matchedIndices) {
    popping = true;
    for (auto index:matchedIndices) {
        candies[index.first][index.second]->pop();
    }
}

void BoardWidget::gravityAnimation(const vector<std::pair<int, int>> &fallingIndices, 
                                   const vector<int> &fallDistance) {
    for (int i = 0; i < fallingIndices.size(); ++i) {
        // Gravity Animation
    }
}

