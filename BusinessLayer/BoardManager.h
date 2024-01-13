
#ifndef PROJECTTESTING_BOARDMANAGER_H
#define PROJECTTESTING_BOARDMANAGER_H

/* Short description...

Class BoardManager is the most important one
it is responsible for:
a-checking the board to update the candies that are matching
b-updating the board which means popping the matching candies and handling the gravity and generating new candies
c-validating that the board is playable O(n^3)
d-swapping candies
e-checking if the swap is valid or not

*/
#include "Board.h"
class BoardManager {
public:
    bool checkBoard(Board&);//O(n^2)
    void updateBoard(Board&);//O(n^3)
    bool IsValidBoard(Board&);//O(n^3)
    bool swapCandies(int i1, int j1, int i2, int j2, Board &board);//O(1)
    bool isValidSwap(int, int, int, int, Board&);//O(n^2)

    void handleMatches(Board& grid);
    void handleGravity(Board& grid);
private:
};


#endif //PROJECTTESTING_BOARDMANAGER_H
