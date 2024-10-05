#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H

/**
 * @class LegacyThermostat
 * @brief A class representing a legacy thermostat with basic functionality to control temperature.
 */
class LegacyThermostat {
  double temperature;  ///< Current temperature of the thermostat.
  bool on;             ///< Indicates if the thermostat is on or off.

public:
  /**
   * @brief Constructor for LegacyThermostat.
   * @param temperature The initial temperature of the thermostat. Defaults to 0.
   */
  LegacyThermostat(double temperature = 0) { this->temperature = temperature; }

  /**
   * @brief Destructor for LegacyThermostat.
   */
  ~LegacyThermostat() = default;

  /**
   * @brief Gets the current temperature of the thermostat.
   * @return The current temperature.
   */
  double getTemperature();

  /**
   * @brief Decreases the temperature by a specified amount.
   * @param temperatureDecrease The amount to decrease the temperature by.
   */
  void decreaseTemperature(double temperatureDecrease);

  /**
   * @brief Increases the temperature by a specified amount.
   * @param temperatureIncrease The amount to increase the temperature by.
   */
  void increaseTemperature(double temperatureIncrease);

  /**
   * @brief Switches the thermostat off.
   */
  void switchOff();

  /**
   * @brief Switches the thermostat on.
   */
  void switchOn();

  /**
   * @brief Checks if the thermostat is on.
   * @return true if the thermostat is on, false otherwise.
   */
  bool isOn() { return this->on; }
};

#endif // LEGACYTHERMOSTAT_H
