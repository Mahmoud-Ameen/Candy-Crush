
#ifndef UNTITLED_LEVEL_H
#define UNTITLED_LEVEL_H

#include <vector>
#include "Board.h"
/* Short description...

Class Level contains the a-target score of the level
*notice that the player current score is the (intitial score - score)
b-moves and levelnumber
c-an array for the objectives: first index indicates if this level contains objectives or not, if -1 then the player needs
certain score only to win (no objectives), other indices indicate the needed amount for each gem
i index 2 holds 5 then the player needs to pop 5 candies of number or color 2 to complete this objective

*/
class Level {
    int score = 0;//the score needed to complete the level, if 0 then player completed the score objective
    int cur_score = 0;
    int moves = 0;//number of moves for the level
    int LevelNumber=0;
    std::vector<int> eliminateCandies= {0,0,0,0,0,0};
    void UpdateScore(Board&);
public:

    void updateObjectives(Board& );//updates the score and the objectives by checking the board ->O(n^2)
    int getLevelNumber();//returns level number O(1)
    std::vector<int> getObjectives();//returns an 6-sized array for the objectives (first index is -1 if level has no objectives) O(1)
    int getRemainingMoves();//O(1)
    void decrementMoves();
    [[nodiscard]] int getPlayerScore() const;
    [[nodiscard]] int getTargetScore() const;
    [[nodiscard]] bool won();//O(1)
    [[nodiscard]] bool lost() const;//O(1)
    //constructor that takes level number to set the target of the level
    Level() = default;
    explicit Level(int);

};


#endif //UNTITLED_LEVEL_H
