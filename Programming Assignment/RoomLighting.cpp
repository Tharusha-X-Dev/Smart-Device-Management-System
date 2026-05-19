#include "RoomLighting.hpp"
#include "inputValidator.hpp"
#include <iostream>

// ===============================
// Constructor
// ===============================

RoomLighting::RoomLighting(int id,
    const std::string& name,
    const std::string& manufacturer,
	const std::string& type,
    int brightnessLevel)
    : Device(id, name, manufacturer,type),
    brightnessLevel(brightnessLevel)
{
}

// ===============================
// Information display
// ===============================

void RoomLighting::viewInfo()
{
    Device::viewInfo(); // Show base device info first
    std::cout << "Brightness level: " << brightnessLevel << '\n';
}

// ===============================
// Interaction behaviour
// ===============================

void RoomLighting::interactionEvent()
{
    if (!checkConnection())
    {
        std::cout << "\nRoom Lighting " << name << " is not connected.\n";
        return;
    }

    if (!getIsActive())
    {
        std::cout << "\nRoom Lighting " << name << " is not active.\n";
        return;
    }

    std::cout << "\nRoom Lighting active. Current brightness: "
              << brightnessLevel << '\n';

    // Ask user if they want to change brightness
    std::cout << "\nDo you want to change the brightness level? (y/n): ";
    bool response = InputValidator::getYesNo();

    if (!response)
    {
        std::cout << "\nNo changes made to the brightness level.\n";
        return;
    }

    std::cout << "\nEnter brightness (0-100): ";
    int input = InputValidator::getInt(0, 100);
    brightnessLevel = input;

    std::cout << "\nBrightness updated to: " << brightnessLevel << '\n';
}

// ===============================
// Editable settings override
// ===============================

void RoomLighting::editSpecificSettings()
{
    std::cout << "\nEnter new brightness: ";
    int brightness = InputValidator::getInt(0, 100);
    brightnessLevel = brightness;

    std::cout << "\nBrightness level set to: " << brightnessLevel << '\n';
}