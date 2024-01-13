//
// Created by Laila on 12/25/2023.
//

#ifndef PROJECTTESTING_BOARD_H
#define PROJECTTESTING_BOARD_H


#include <vector>
#include "Candy.h"


/* Short description...

Class Board contains the grid which is 12x12 but 10x10 actually because the borders of the grid are 0's always (to be easier using one-indexed candies)
GenerateBoard() generates a completely random board
in the constructor the board manager checks if the board is playable, if not it generates random boards until a valid one is found

*/
class Board {
public:

    const int rows = 8;
    const int cols = 8;
    std::vector<std::vector<Candy>> grid;

    Board();
    //to access the index from board manager
   std::vector<Candy>(& operator[](int index)){
        return grid[index];
    }
    void GenerateBoard();//O(n^2)
};


#endif //PROJECTTESTING_BOARD_H
