#include "BoardManager.h"
#include "Board.h"
#include "public/DTOs.h"


bool BoardManager::isValidSwap(int Candy1i, int Candy1j, int Candy2i, int Candy2j, Board &board){ //O(n^2)
//First Check those candies are on the same line horizontally or vertically
    if (Candy1i != Candy2i && Candy1j != Candy2j)
        return false;
//Second check to see they're right next each other
    if (abs(Candy1i-Candy2i)!=1 && abs(Candy1j-Candy2j) != 1)
        return false;
//Third check to see if there's similar candies for the swap to be true

// Swap Candies and check if a match occurred
    bool isValid = swapCandies(Candy1i, Candy1j, Candy2i, Candy2j, board);
// Revert Changes made
    swapCandies(Candy1i, Candy1j, Candy2i, Candy2j, board);

    return isValid;
}

bool BoardManager::checkBoard(Board& board) { // O(n^2)
    for (int i = 1; i <= board.rows; ++i) {
        for (int j = 1; j <= board.cols; ++j) {
            board.grid[i][j].match = 0;
        }
    }
    bool check = false;
    for(int i=1; i <= board.rows; i++)
        for(int j=1; j <= board.cols; j++)
        {
            if (board.grid[i][j].color == board.grid[i + 1][j].color)
                if (board.grid[i][j].color == board.grid[i - 1][j].color) {
                    check = true;
                    for (int n = -1; n <= 1; n++) board.grid[i + n][j].match++;
                }
            if (board.grid[i][j].color == board.grid[i][j + 1].color)
                if (board.grid[i][j].color == board.grid[i][j - 1].color) {
                    check = true;
                    for (int n = -1; n <= 1; n++) board.grid[i][j + n].match++;
                }
        }
    return check;
}

void BoardManager::handleMatches(Board &grid) {
    for(int i=1;i<=grid.rows;i++) {
        for (int j = 1; j <= grid.cols; j++) {
            if(grid[i][j].match>=1){
                grid[i][j] = Candy(0);
            }
        }
    }
}

void BoardManager::updateBoard(Board& grid) { //O(n^3)
    for(int i = 1;i <= grid.rows;i++) {
        for (int j = 1; j <= grid.cols; j++) {
            if(grid[i][j].match>=1){
                grid[i][j] = Candy();
                for(int index = i;index>1;index--){
                    int tmp = grid[index][j].match;
                    grid[index][j]= grid[index-1][j];
                    grid[index][j].match = tmp;
                }
                grid[1][j] = Candy();
                grid[i][j].match = 0;
            }
        }
    }
}

bool BoardManager::IsValidBoard(Board& grid){ //O(n^3)
    for(int i = 1;i<grid.rows;i++){
        for(int j = 1;j<grid.cols;j++){
            //check up ->check two rows and one column
            swap(grid[i][j],grid[i-1][j]);
            for(int col = 1;col<=grid.cols;col++){
                if(grid[i][col] == grid[i][col-1] && grid[i][col] == grid[i][col+1]){
                    swap(grid[i][j],grid[i-1][j]);
                    return true;
                }
                if(grid[i-1][col] == grid[i-1][col-1] && grid[i-1][col] == grid[i-1][col+1]){
                    swap(grid[i][j],grid[i-1][j]);
                    return true;
                }
            }
            for(int row = 1;row<=grid.rows;row++){
                if(grid[row][j] == grid[row-1][j] && grid[row][j] == grid[row+1][j]){
                    swap(grid[i][j],grid[i-1][j]);
                    return true;
                }
            }
            swap(grid[i][j],grid[i-1][j]);
            //check down ->check two rows and one column
            swap(grid[i][j],grid[i+1][j]);
            for(int col = 1;col<=grid.cols;col++){
                if(grid[i][col] == grid[i][col-1] && grid[i][col] == grid[i][col+1]){
                    swap(grid[i][j],grid[i+1][j]);
                    return true;
                }
                if(grid[i+1][col] == grid[i+1][col-1] && grid[i+1][col] == grid[i+1][col+1]){
                    swap(grid[i][j],grid[i+1][j]);
                    return true;
                }
            }
            for(int row = 1;row<=grid.rows;row++){
                if(grid[row][j] == grid[row-1][j] && grid[row][j] == grid[row+1][j]){
                    swap(grid[i][j],grid[i+1][j]);
                    return true;
                }
            }
            swap(grid[i][j],grid[i+1][j]);
            //check right->check two columns and one row
            swap(grid[i][j],grid[i][j+1]);
            for(int row = 1;row<11;row++){
                if(grid[row][j] == grid[row-1][j] && grid[row][j] == grid[row+1][j]){
                    swap(grid[i][j],grid[i][j+1]);
                    return true;
                }
                if(grid[row][j+1] == grid[row-1][j+1] && grid[row][j+1] == grid[row+1][j+1]){
                    swap(grid[i][j],grid[i][j+1]);
                    return true;
                }
            }
            for(int col = 1;col<=grid.cols;col++){
                if(grid[i][col] == grid[i][col-1] && grid[i][col] == grid[i][col+1]){
                    swap(grid[i][j],grid[i][j+1]);
                    return true;
                }
            }
            swap(grid[i][j],grid[i][j+1]);
            //check left->check two columns and one row
            swap(grid[i][j],grid[i][j-1]);
            for(int row = 1;row<11;row++){
                if(grid[row][j] == grid[row-1][j] && grid[row][j] == grid[row+1][j]){
                    swap(grid[i][j],grid[i][j-1]);
                    return true;
                }
                if(grid[row][j-1] == grid[row-1][j-1] && grid[row][j-1] == grid[row+1][j-1]){
                    swap(grid[i][j],grid[i][j-1]);
                    return true;
                }
            }
            for(int col = 1;col<=grid.cols;col++){
                if(grid[i][col] == grid[i][col-1] && grid[i][col] == grid[i][col+1]){
                    swap(grid[i][j],grid[i][j-1]);
                    return true;
                }
            }
            swap(grid[i][j],grid[i][j-1]);
        }
    }
    return false;
}

bool BoardManager::swapCandies(int i1, int j1, int i2, int j2, Board& board) { //O(1)
    swap((board.grid)[i1][j1], (board.grid)[i2][j2]);
    return checkBoard(board);
}

void BoardManager::handleGravity(Board &board) {
    for (int i = 1; i <= board.rows; ++i) {
        for (int j = 1; j <= board.cols; ++j) {
            if(board[i][j].color != 0) continue;

            board[i][j] = Candy();
            for (int k = i; k > 1; --k) {
                std::swap(board[k][j],board[k-1][j]);
            }
            board[1][j] = Candy();
        }
    }
}
