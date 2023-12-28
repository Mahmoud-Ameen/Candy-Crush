#ifndef CANDYCRUSH_LEVELSPAGE_H
#define CANDYCRUSH_LEVELSPAGE_H

#include "Page.h"
#include "BackgroundImage.h"

class LevelsPage: public Page{
public:
    explicit LevelsPage(sf::RenderTarget *renderTarget);

    void render() override;
    void update(const sf::Time &dt) override;
    void handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords, const sf::Vector2f &mousePositionInView,
                     float scaleFactor) override;
    void onEvent(const std::string &eventName) override;

private:
    std::string backgroundImagePath = "../assets/image.jpg";
    BackgroundImage* backgroundImage;

};

#endif //CANDYCRUSH_LEVELSPAGE_H
