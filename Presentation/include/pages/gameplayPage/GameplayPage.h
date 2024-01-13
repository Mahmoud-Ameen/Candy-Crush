#ifndef CANDYCRUSH_GAMEPLAYPAGE_H
#define CANDYCRUSH_GAMEPLAYPAGE_H

#include "Page.h"
#include "BackgroundImage.h"
#include "GameEvents.h"
#include "DTOs.h"
#include "BoardWidget.h"
#include "pages/gameplayPage/TopBarWidget.h"
#include "pages/gameplayPage/BottomBarWidget.h"
#include "pausePopup/PausePopUp.h"
#include "LevelClearedWidget.h"
#include "LevelLostWidget.h"

#include <queue>

class GameplayPage: public Page, public GameEventObserver {
public:
    explicit GameplayPage(sf::RenderTarget *renderTarget);

    void render() override;
    void update(const sf::Time &dt) override;
    void handleEvent(const sf::Event &ev, const sf::Vector2f &originCoords,
                     const sf::Vector2f &mousePositionInView,
                     float scaleFactor) override;
    void onEvent(const std ::string &eventName) override;

    void onGameEvent(const GameEvent& ev) override;

    ~GameplayPage();
private:
    bool isPaused = false;

    PausePopUp* pausePopUp;
    LevelClearedWidget* levelClearedWidget;
    LevelLostWidget* levelLostWidget;

    std::string backgroundImagePath = "../../assets/image.jpg";
    BackgroundImage* backgroundImage;

    BoardWidget* boardWidget;
    TopBarWidget* topBar;
    BottomBarWidget* bottomBar;

    DTOs::GameState gameState;
    std::queue<GameEvent> gameEventsQueue;

    bool isProcessingEvent = false;
};


#endif //CANDYCRUSH_GAMEPLAYPAGE_H
