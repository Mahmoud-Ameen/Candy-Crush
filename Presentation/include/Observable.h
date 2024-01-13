#ifndef CMAKESFMLPROJECT_OBSERVABLE_H
#define CMAKESFMLPROJECT_OBSERVABLE_H

#include <Observer.h>
#include <vector>

/**
 * @brief The Observable class represents an object that can be observed by one or multiple observers.
 *
 * This class allows observers to register themselves and be notified when specific events occur.
 */
class Observable {

public:
    /**
     * @brief Adds an observer to the list of observers.
     *
     * @param observer A pointer to the observer to be added.
     */
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    /**
     * @brief Notifies all registered observers of a specific event.
     *
     * This method iterates through the list of observers and calls their onEvent method,
     * passing the specified event name.
     *
     * @param eventName The name or identifier of the event.
     */
    void notifyObservers(const std::string& eventName) {
        for (Observer* observer : observers) {
            observer->onEvent(eventName);
        }
    }

protected:
    std::vector<Observer*> observers;
};


#endif //CMAKESFMLPROJECT_OBSERVABLE_H
