//
// Created by Ahmed sameh on 12/31/2023.
//

#include "public/GameController.h"

GameController GameController::instance;
GameController::GameController() = default;

void GameController::startGame(int levelNumber){
    level = new Level(levelNumber);
    while(mng.checkBoard(board)){
        mng.updateBoard(board);
    }
    while (!mng.IsValidBoard(board)){
        board.GenerateBoard();
        while(mng.checkBoard(board)){
            mng.updateBoard(board);
        }
    }
}

void GameController::endGame() {
    int curLevel;
    for(int i = 1;i<6;i++){
        if(levels[i] == 1){
            curLevel = i;
        }
    }
    if(true /*Replace by a check for whether game was won*/){
        curLevel++;
    }
    if(curLevel>5)
        curLevel = 5;
}

vector<DTOs::ObjectiveInfo> GameController::getObjectives() {
    if(!level) return {};

    std::vector<DTOs::ObjectiveInfo> objectives;
    auto levelObjectives = level->getObjectives();
    for (int i = 1; i < level->getObjectives().size(); ++i) {
        if(levelObjectives[i])
            objectives.emplace_back(intToCandyType(i),levelObjectives[i]);
    }
    return objectives;
}

std::vector<int> GameController::getAvailableLevels() {
    std::vector<int> availableLevels;
    for (int i = 0; i < levelsNumber; ++i) {
        if(levels[i])
            availableLevels.push_back(i+1);
    }
    return availableLevels;
}

DTOs::GameState GameController::getGameState(){
    DTOs::GameState state;
    state.board.resize(getRows(), std::vector<DTOs::CandyType>(getCols()));
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            state.board[i][j] = intToCandyType(board[i+1][j+1].color);
        }
    }
    state.objectives = getObjectives();
    state.remainingMoves = level->getRemainingMoves();
    state.isGameLost = level->lost();
    state.isGameWon = level->won();

    return state;
}

void GameController::swapCandies(int i1, int j1, int i2, int j2) {
    if(isValidSwap(i1,j1,i2,j2)){
        mng.swapCandies(i1+1,j1+1,i2+1,j2+1,board);
        // Create a snapshot of the gameState before handling matches
        DTOs::GameState initialGameState = getGameState();
        level->decrementMoves();

        while(mng.checkBoard(board)) {
            // Modify Game state (board,level objective and moves)
            level->updateObjectives(board);
            mng.handleMatches(board);

            // Create a snapshot of the gameState after swapping and matching
            DTOs::GameState stateBeforeGravity = getGameState();
            notifyObservers({GameEventType::MatchingEvent, initialGameState, stateBeforeGravity});

            // Handle Gravity Effect
            mng.handleGravity(board);
            DTOs::GameState stateAfterGravity = getGameState();
            notifyObservers({GameEventType::GravityEvent, stateBeforeGravity, stateAfterGravity});

            if(level->won() || level->lost()) return;

            initialGameState = stateBeforeGravity;
        }
    }
}

GameController::~GameController() {
    delete level;
}

GameController &GameController::getInstance() {
    return instance;
}

int GameController::getCurrentLevelNumber() const {
    return level->getLevelNumber();
}

int GameController::getRemainingMoves() const {
    return level->getRemainingMoves();
}

int GameController::getCols() const {
    return board.cols;
}
int GameController::getRows() const {
    return board.rows;
}

DTOs::CandyType GameController::getCandyAt(int i, int j) const {
    return intToCandyType(board.grid[i+1][1+j].color);
}

DTOs::CandyType GameController::intToCandyType(int number) {
    if(number < 0 || number > 7) return DTOs::CandyType::RemovedCandy;

    vector<DTOs::CandyType> candyTypes{
                                 DTOs::CandyType::RemovedCandy,
                                 DTOs::CandyType::red,
                                 DTOs::CandyType::green,
                                 DTOs::CandyType::blue,
                                 DTOs::CandyType::yellow,
                                 DTOs::CandyType::purple,
                                 DTOs::CandyType::orange,
                                 DTOs::CandyType::pink};

    return candyTypes[number];
}

bool GameController::isValidSwap(int i1, int j1, int i2, int j2) {
    return mng.isValidSwap(i1+1,j1+1,i2+1,j2+1,board);
}

bool GameController::gameWon() {
    return level->won();
}

bool GameController::gameLost() {
    return level->lost();
}

