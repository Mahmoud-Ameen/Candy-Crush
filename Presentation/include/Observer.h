#ifndef CandyCrush_Observer_h
#define CandyCrush_Observer_h

#include <string>

/**
 * @brief The Observer class represents an abstract observer in the Observer pattern.
 *
 * This class defines an interface for objects that need to be notified of events.
 * Concrete classes implementing this interface can subscribe to observables and respond
 * to specific events by implementing the onEvent method.
 */
class Observer {
public:
    /**
     * @brief Called when an event occurs.
     *
     * This method is invoked by an observable object to notify the observer of a specific event.
     *
     * @param eventName The name or identifier of the event.
     */
    virtual void onEvent(const std::string& eventName) = 0;
};

#endif //CandyCrush_Observer_h
