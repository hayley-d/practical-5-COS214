#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H

#include "SmartDevice.h"

/**
 * @class SmartLight
 * @brief Represents a smart light, a concrete implementation of the SmartDevice interface.
 */
class SmartLight : public SmartDevice {
private:
    int intensity; ///< The brightness level of the smart light (0-100).
    int id;       ///< Unique identifier for the smart light.

public:
    /**
     * @brief Constructor for SmartLight.
     * @param id The unique identifier for the smart light.
     * @param intensity The initial brightness level of the light (default is 0).
     */
    SmartLight(int id, int intensity = 0);

    /**
     * @brief Destructor for SmartLight.
     */
    ~SmartLight() override = default;

    /**
     * @brief Sets the intensity of the smart light.
     * @param intensity The new brightness level to set (0-100).
     */
    void setIntensity(int intensity);

    /**
     * @brief Gets the current intensity of the smart light.
     * @return The current brightness level of the light.
     */
    int getIntensity() { return this->intensity; }

    /**
     * @brief Toggles the smart light's state (on/off).
     * This method overrides the toggle method in the SmartDevice base class.
     */
    void toggle() override;

    /**
     * @brief Turns the smart light on.
     * This method overrides the toggleOn method in the SmartDevice base class.
     */
    void toggleOn() override;

    /**
     * @brief Turns the smart light off.
     * This method overrides the toggleOff method in the SmartDevice base class.
     */
    void toggleOff() override;

    /**
     * @brief Gets the current status of the smart light.
     * @return A string indicating whether the light is on or off.
     */
    std::string getStatus() override;

    /**
     * @brief Gets the type of device.
     * @return The DeviceType representing that this is a light.
     */
    DeviceType getDeviceType() override { return DeviceType::Light; }

    /**
     * @brief Gets the unique identifier of the smart light.
     * @return The ID of the smart light.
     */
    int getId() override { return this->id; }
};

#endif // SMARTLIGHT_H
