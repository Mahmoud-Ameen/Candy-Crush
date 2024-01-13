#include <iostream>
#include <unordered_map>
#include "pages/gameplayPage/CandyWidget.h"

CandyWidget::CandyWidget(DTOs::CandyType candyType, float size): size(size) {
    std::unordered_map<DTOs::CandyType,std::string> imagePaths;
    imagePaths[DTOs::CandyType::orange] = "../../assets/gem-orange.png";
    imagePaths[DTOs::CandyType::red] = "../../assets/gem-red-2.png";
    imagePaths[DTOs::CandyType::yellow] = "../../assets/gem-yellow.png";
    imagePaths[DTOs::CandyType::green] = "../../assets/gem-green-2.png";
    imagePaths[DTOs::CandyType::purple] = "../../assets/gem-purple.png";
    imagePaths[DTOs::CandyType::blue] = "../../assets/gem-blue-2.png";
    imagePaths[DTOs::CandyType::pink] = "../../assets/gem-pink.png";


    if(candyType != DTOs::RemovedCandy && !texture.loadFromFile(imagePaths[candyType]))
        std::cerr<<"error loading " <<imagePaths[candyType];

    texture.setSmooth(true);
    candy.setTexture(texture);
    candy.scale(size/(float)texture.getSize().x, size/(float)texture.getSize().y);
}

void CandyWidget::pop(){
    isPopping = true;
    animationClock.restart();
}

void CandyWidget::render(sf::RenderTarget* renderTarget) {
    if(isMoving){
        float elapsedSeconds = animationClock.getElapsedTime().asSeconds();
        candy.move(dx*elapsedSeconds, dy*elapsedSeconds);

        deltaX-=dx;
        deltaX-=dy;

        if( deltaX <= 0 && deltaY <= 0){
            isMoving = false;
            animationClock.restart();
        }
    }
    else if (isPopping) {
        float elapsedSeconds = animationClock.getElapsedTime().asSeconds();
        if(elapsedSeconds <= 0.75 ){
            auto alpha = static_cast<sf::Uint8>(255 - elapsedSeconds/0.75 * 255);
            candy.setColor(sf::Color(255, 255, 255, alpha));
        }
    }
    renderTarget->draw(candy);
}

void CandyWidget::animateMovement(const sf::Vector2f &destination, float seconds) {
    deltaX = destination.x - candy.getPosition().x;
    deltaY = destination.y - candy.getPosition().y;
    isMoving = true;

    animationTime = seconds;
    dx = deltaX / seconds;
    dy = deltaY / seconds;

    animationClock.restart();
}

