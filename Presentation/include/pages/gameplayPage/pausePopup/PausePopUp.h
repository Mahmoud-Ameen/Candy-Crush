#ifndef CANDYCRUSH_PAUSEPOPUP_H
#define CANDYCRUSH_PAUSEPOPUP_H


#include "Widget.h"
#include "pages/gameplayPage/HomeButton.h"
#include "MusicButton.h"
#include "PlayButton.h"

class PausePopUp: public Widget, public Observer{
    sf::Sprite background;
    sf::Texture backTexture;

    HomeButton homeButton;
    MusicButton musicButton;
    PlayButton playButton;

    void onEvent(const std::string& eventName) override;


public:
    PausePopUp();
    void render(sf::RenderTarget* renderTarget) override;
    void handleEvent(sf::Event ev, sf::Vector2f mousePosition) override;
    void update(sf::Time dt) override;
    sf::Rect<float> getGlobalBounds() override;
};


#endif //CANDYCRUSH_PAUSEPOPUP_H
