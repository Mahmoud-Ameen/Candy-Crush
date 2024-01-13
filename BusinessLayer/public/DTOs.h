#ifndef UNTITLED_DTOS_H
#define UNTITLED_DTOS_H

#include <vector>

namespace DTOs{


    /**
     * @brief Enum representing different types of candies in the game.
     */
    enum CandyType{
        blue,    ///< Blue candy type.
        red,     ///< Red candy type.
        yellow,  ///< Yellow candy type.
        green,   ///< Green candy type.
        purple,  ///< Purple candy type.
        orange,  ///< Orange candy type.
        pink,    ///< Pink candy type.
        RemovedCandy  ///< Special value indicating a removed candy.
    };

    /**
     * @brief Struct representing information about an objective in the game/level.
     */
    struct ObjectiveInfo{
        CandyType candyType; ///< The type of candy for the objective.
        int amount;          ///< The required amount of this candy type to complete the objective.

        /**
         * @brief Constructor for ObjectiveInfo.
         * @param candy The type of candy for the objective.
         * @param amount The required amount to complete the objective.
         */
        ObjectiveInfo(CandyType candy,int amount):candyType(candy),amount(amount){};

        /**
         * @brief Check if the objective is completed.
         * @return True if the objective is completed, false otherwise.
         */
        [[nodiscard]] bool isCompleted() const{return amount == 0;};
    };

    /**
     * @brief Struct representing the overall state of the game.
     */
    struct GameState{
        std::vector<std::vector<CandyType>> board;       ///< The game board configuration.
        std::vector<ObjectiveInfo> objectives;           ///< The list of objectives for the game.
        int remainingMoves;
        bool isGameWon = false;
        bool isGameLost = false;
    };
}

#endif //UNTITLED_DTOS_H