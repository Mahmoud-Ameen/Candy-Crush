
#include "pages/gameplayPage/ObjectiveWidget.h"

void ObjectiveWidget::initImagePaths(){
    imagePaths[DTOs::CandyType::orange] = "../../assets/gem-orange.png";
    imagePaths[DTOs::CandyType::red] = "../../assets/gem-red-2.png";
    imagePaths[DTOs::CandyType::yellow] = "../../assets/gem-yellow.png";
    imagePaths[DTOs::CandyType::green] = "../../assets/gem-green-2.png";
    imagePaths[DTOs::CandyType::purple] = "../../assets/gem-purple.png";
    imagePaths[DTOs::CandyType::blue] = "../../assets/gem-blue-2.png";
    imagePaths[DTOs::CandyType::pink] = "../../assets/gem-pink.png";}

ObjectiveWidget::ObjectiveWidget(DTOs::ObjectiveInfo objectiveInfo, int x): xPos(x) {
    initImagePaths();

    containerTexture.create(width+35,height+30);
    containerTexture.setSmooth(true);
    background = new BackgroundImage("../../assets/glassBox.png",width,height);

    gemImage.loadFromFile(imagePaths[objectiveInfo.candyType]);
    gemImage.setSmooth(true);
    gemSprite.setTexture(gemImage);
    gemSprite.scale((width-10)/gemImage.getSize().x,(height-10)/gemImage.getSize().y);
    gemSprite.setPosition(5,5);

    if(!font.loadFromFile("../../assets/Roboto/Roboto-Black.ttf"))
        std::cerr << "Unable to load Roboto-Black\n";
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setString(std::to_string(objectiveInfo.amount));
    text.setPosition(gemSprite.getGlobalBounds().left + gemSprite.getGlobalBounds().width + 5,
                     gemSprite.getGlobalBounds().top + gemSprite.getGlobalBounds().height/2 - text.getGlobalBounds().height/2);
}

void ObjectiveWidget::render(sf::RenderTarget *renderTarget) {
    containerTexture.clear(sf::Color::Transparent);

    containerTexture.draw(gemSprite);
    containerTexture.draw(text);
    background->render(&containerTexture);


    containerTexture.display();
    texture = containerTexture.getTexture();
    containerSprite.setTexture(texture);

    float yPos = 30;
    containerSprite.setPosition(xPos,yPos);
    renderTarget->draw(containerSprite);

}
