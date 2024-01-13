//
// Created by Laila on 12/25/2023.
//
#include <random>
#include "Board.h"


void Board::GenerateBoard(){
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=cols;j++)
            grid[i][j]= Candy();
    }
}

Board::Board(){
    grid.resize(rows+2,std::vector<Candy>(cols+2));
    for (int j = 0; j < rows+2; j++) {
        grid[0][j].color = 0;
        grid[rows+1][j].color = 0;
        grid[j][0].color = 0;
        grid[j][rows+1].color = 0;
    }
    GenerateBoard();

}
