#include "level.h"


void Level::UpdateScore(Board &board){
    for(int i=1;i<=board.rows;i++){
        for(int j=1;j<=board.cols;j++){
            cur_score-=(10*board.grid[i][j].match);
        }
    }
}

Level::Level(int levelNum) {
    LevelNumber = levelNum;
    switch(levelNum){
        case 1:
            eliminateCandies[1] = 3;
            moves = 10;
            break;
        case 2:
            moves = 20;
            eliminateCandies[1] = 15; //15
            eliminateCandies[2] = 15; //15
            break;
        case 3:
            moves = 30;
            score = 1;
            eliminateCandies[1] = 10;//10
            eliminateCandies[2] = 10;//10
            eliminateCandies[3] = 10;//10
            eliminateCandies[4] = 10;//10
            break;
        case 4:
            moves = 25;
            score = 1;//1000
            eliminateCandies[1] = 15;//15
            eliminateCandies[4] = 15;//15
            eliminateCandies[5] = 15;//15
            break;
        case 5:
            moves = 25;
            score = 1;//1500
            eliminateCandies[1] = 10;//10
            eliminateCandies[2] = 10;//10
            eliminateCandies[3] = 10;//10
            eliminateCandies[4] = 10;//10
            eliminateCandies[5] = 10;//10
            break;

    }
    cur_score = score;
}
int Level::getLevelNumber(){
    return LevelNumber;
}
std::vector<int> Level::getObjectives(){
    return eliminateCandies;
}
int Level::getRemainingMoves(){
    return moves;
}
void Level::decrementMoves(){moves--;};
void Level::updateObjectives(Board &board) {
    if(cur_score>0){
        UpdateScore(board);
    }
    for(int i = 1;i<=board.rows;i++){
        for(int j = 1;j<=board.cols;j++){
            if(board.grid[i][j].match >= 1){
                if(eliminateCandies[board.grid[i][j].color] > 0)
                     eliminateCandies[ board.grid[i][j].color ] -=1;
            }
        }
    }
}

bool Level::won(){

    if(cur_score <= 0 ){
        for(int i=1;i<6;i++){
            if (eliminateCandies[i]>0) return false;
        }
        return true;
    }
    return false;
}

bool Level::lost() const {
    return moves <= 0;
}

int Level::getPlayerScore() const {
    return score - cur_score;
}

int Level::getTargetScore() const {
    return score;
}
