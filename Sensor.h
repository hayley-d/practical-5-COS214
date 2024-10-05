#ifndef SENSOR_H
#define SENSOR_H

#include "Event.h"

/**
 * @class Sensor
 * @brief Abstract base class representing a generic sensor that reacts to events.
 */
class Sensor {
protected:
    int id; ///< Unique identifier for the sensor.

public:
    /**
     * @brief Constructor for the Sensor class.
     * @param id Unique identifier for the sensor.
     */
    Sensor(int id) { this->id = id; }

    /**
     * @brief Virtual destructor for the Sensor class.
     */
    virtual ~Sensor() = default;

    /**
     * @brief Updates the sensor based on the event received.
     * 
     * This is a pure virtual function that must be overridden in derived classes.
     * 
     * @param e The event that triggers the update.
     */
    virtual void update(Event e) = 0;

    /**
     * @brief Gets the unique identifier of the sensor.
     * @return The ID of the sensor.
     */
    int getId() { return id; }
};

#endif // SENSOR_H
