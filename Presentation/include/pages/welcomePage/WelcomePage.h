#ifndef CANDYCRUSH_WELCOMEPAGE_H
#define CANDYCRUSH_WELCOMEPAGE_H

#include "Page.h"
#include "BackgroundImage.h"
#include "MusicPlayer.h"

class WelcomePage: public Page{
public:
    explicit WelcomePage(sf::RenderTarget *renderTarget);

    void render() override;
    void update(const sf::Time &dt) override;
    void handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords, const sf::Vector2f &mousePositionInView,
                float scaleFactor) override;
    void onEvent(const std::string &eventName) override;

private:
    std::string backgroundImagePath =
    //            "../assets/image.jpg";
//            "../../assets/wp2347628-candy-crush-saga-wallpapers.jpg";
//    "../../assets/wp2347656-candy-crush-saga-wallpapers.png";
    "../../assets/background4.jpg";

    BackgroundImage* backgroundImage;

//    MusicPlayer musicPlayer = {"../../assets/welcome_music.mp3"};
};

#endif //CANDYCRUSH_WELCOMEPAGE_H
