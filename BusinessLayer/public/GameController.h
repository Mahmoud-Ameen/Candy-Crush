//
// Created by Ahmed sameh on 12/31/2023.
//

#ifndef UNTITLED_GAMECONTROLLER_H
#define UNTITLED_GAMECONTROLLER_H

#include "../Board.h"
#include "../level.h"
#include "../BoardManager.h"
#include "DTOs.h"
#include "GameEvents.h"
#include <string>
#include <fstream>
#include <vector>

/**
 * @brief Singleton GameController class responsible for managing the game state,
 * handling user input, and orchestrating game events.
 *
 * The GameController ensures that there is only one instance of itself throughout
 * the application, providing a centralized point of control for the game logic.
 *
 * Usage:
 * - To access the GameController instance: GameController& controller = GameController::getInstance();
 * - To perform game-related operations: controller.handleUserInput(), controller.updateGameState(), etc.
 */
class GameController: public GameEventSubject {
public:
    /**
     * @brief Get the singleton instance of the GameController.
     * @return Reference to the GameController instance.
     */
    static GameController& getInstance();
    ~GameController();

    void startGame(int levelNumber);
    void endGame();

    [[nodiscard]] int getCurrentLevelNumber() const;
    [[nodiscard]] int getRemainingMoves() const;
    [[nodiscard]] int getCols() const;
    [[nodiscard]] int getRows() const;
    [[nodiscard]] DTOs::CandyType getCandyAt(int i, int j) const;
    bool isValidSwap(int i1,int j1, int i2, int j2);

    bool gameWon();
    bool gameLost();

    vector<DTOs::ObjectiveInfo> getObjectives();
    void swapCandies(int i1, int j1, int i2, int j2);

    std::vector<int> getAvailableLevels();

    /**
     * @brief Retrieves the current game state.
     *
     * This function constructs and returns an instance of the GameState structure,
     * representing the current state of the game. It includes the current board
     * configuration and the active objectives.
     *
     * @return The current game state.
     */
    DTOs::GameState getGameState();
private:
    // Singleton instance
    static GameController instance;

    explicit GameController();
    Board board;
    BoardManager mng;
    Level* level = nullptr;
    int levels[6] = {1,1,1,1,1};
    int levelsNumber = 5;
    string playerName;

    /**
     * @brief convert number to corresponding candy
     * */
    [[nodiscard]] static DTOs::CandyType intToCandyType(int number) ;

};


#endif //UNTITLED_GAMECONTROLLER_H
