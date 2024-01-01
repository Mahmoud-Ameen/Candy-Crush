
#include "pages/gameplayPage/ObjectiveWidget.h"

void ObjectiveWidget::initImagePaths(){
    imagePaths[Candy::blue] = "../../assets/gem-blue.png";
    imagePaths[Candy::red] = "../../assets/gem-red.png";
    imagePaths[Candy::yellow] = "../../assets/gem-yellow.png";
}

ObjectiveWidget::ObjectiveWidget(ObjectiveInfo objectiveInfo, int x): xPos(x) {
    initImagePaths();

    containerTexture.create(width,height+30);
    containerTexture.setSmooth(true);
    background = new BackgroundImage("../../assets/glassBox.png",width,height);

    gemImage.loadFromFile(imagePaths[objectiveInfo.CandyType]);
    gemImage.setSmooth(true);
    gemSprite.setTexture(gemImage);
    gemSprite.scale((width-10)/gemImage.getSize().x,(height-10)/gemImage.getSize().y);
    gemSprite.setPosition(5,5);

    if(!font.loadFromFile("../../assets/Roboto/Roboto-Black.ttf"))
        std::cerr << "Unable to load Roboto-Black\n";
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setString(std::to_string(objectiveInfo.amount));
    text.setPosition(gemSprite.getGlobalBounds().left + gemSprite.getGlobalBounds().width/2-text.getGlobalBounds().width/2,
                     65);
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
