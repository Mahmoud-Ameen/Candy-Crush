
#ifndef CANDYCRUSH_GAMEEVENTS_H
#define CANDYCRUSH_GAMEEVENTS_H

#include <utility>
#include <vector>
#include <algorithm>
#include "DTOs.h"

enum GameEventType{
    MatchingEvent,
    GravityEvent,
};

class GameEvent{
public :

    GameEvent(GameEventType eventType,DTOs::GameState initialState,DTOs::GameState modifiedState):
        eventType(eventType),
        initialGameState(std::move(initialState)),
        modifiedGameState(std::move(modifiedState)){};

    GameEventType eventType;
    DTOs::GameState initialGameState;
    DTOs::GameState modifiedGameState;
};


class GameEventObserver {
public:
    virtual void onGameEvent(const GameEvent& event) = 0;
};

class GameEventSubject {
private:
    std::vector<GameEventObserver*> observers;

public:
    void addObserver(GameEventObserver* observer) {
        observers.push_back(observer);
    }

    void removeObserver(GameEventObserver* observer) {
        observers.erase(std::find(observers.begin(),observers.end(),observer));
    }

    void notifyObservers(const GameEvent& event) {
        for (auto observer : observers) {
            observer->onGameEvent(event);
        }
    }
};

#endif //CANDYCRUSH_GAMEEVENTS_H
