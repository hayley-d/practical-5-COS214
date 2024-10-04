cmake_minimum_required(VERSION 3.28)
project(P5Tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(P5Tests main.cpp
        Button.h
        Command.h
        DeviceType.h
        Event.h
        LegacyThermostat.h
        LightSensor.h
        LockDoorsCommand.h
        MacroCommand.h
        Sensor.h
        SetLightIntensityCommand.h
        SetTemperatureCommand.h
        SmartDevice.h
        SmartDoor.h
        SmartLight.h
        SmartRoom.h
        SmartThermostat.h
        SmartThermostatIntegrator.h
        TemperatureSensor.h
        TurnOffLightsCommand.h
        TurnOnLightsCommand.h
        UnlockDoorsCommand.h
        SmartHomeApplication.h
        Button.cpp
        SetLightIntensityCommand.cpp
        SetTemperatureCommand.cpp
        SmartDoor.cpp
        SmartLight.cpp
        SmartRoom.cpp
        SmartThermostat.cpp
        SmartThermostatIntegrator.cpp
        SmartHomeApplication.cpp
        TemperatureSensor.cpp
        TurnOffLightsCommand.cpp
        TurnOnLightsCommand.cpp
        UnlockDoorsCommand.cpp
        MacroCommand.cpp
        LockDoorsCommand.cpp
        LegacyThermostat.cpp
        LightSensor.cpp
        )
