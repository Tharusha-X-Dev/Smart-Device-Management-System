#include "AirConditioning.hpp"
#include "inputValidator.hpp"
#include <iostream>

// ===============================
// Constructor
// ===============================

AirConditioning::AirConditioning(int id,
    const std::string& name,
    const std::string& manufacturer,
	const std::string& type,
    float targetTemperature)
    : Device(id, name, manufacturer,type),
    targetTemperature(targetTemperature)
{
}

// ===============================
// Information display
// ===============================

void AirConditioning::viewInfo()
{
    Device::viewInfo(); // Show base device info first
    std::cout << "Target Temperature: " << targetTemperature << " °C\n";
}

// ===============================
// Interaction behaviour
// ===============================

void AirConditioning::interactionEvent()
{
    if (!checkConnection())
    {
        std::cout << "\nAir Conditioning " << name << " is not connected.\n";
        return;
    }

    if (!getIsActive())
    {
        std::cout << "\nAir Conditioning " << name << " is not active.\n";
        return;
    }

    std::cout << "\nAir Conditioning active. Current temperature: "
              << targetTemperature << " C\n";

    // Ask user if they want to change temperature
    std::cout << "\nChange temperature? (y/n): ";
    bool response = InputValidator::getYesNo();

    if (!response)
    {
        std::cout << "\nNo changes made to the target temperature.\n";
        return;
    }

    std::cout << "\nEnter new temperature (16 - 30 C): ";
    float input = InputValidator::getFloat(16.0f, 30.0f);

    targetTemperature = input;

    std::cout << "\nTemperature updated to: " << targetTemperature << " C\n";
}

// ===============================
// Editable settings override
// ===============================

void AirConditioning::editSpecificSettings()
{
    std::cout << "\nEnter new target temperature: ";
    float temp = InputValidator::getFloat(16, 30);
    setTargetTemperature(temp);
}

// ===============================
// Setter
// ===============================

void AirConditioning::setTargetTemperature(float temp)
{
    targetTemperature = temp;
}