#include "SecurityCamera.hpp"
#include "inputValidator.hpp"
#include <iostream>

// ===============================
// Constructor
// ===============================

SecurityCamera::SecurityCamera(int id,
    const std::string& name,
    const std::string& manufacturer,
	const std::string& type,
    const std::string& cameraQuality,
    const std::string& powerType)
    : Device(id, name, manufacturer, type),
    cameraQuality(cameraQuality),
    powerType(powerType)
{
}

// ===============================
// Information display
// ===============================

void SecurityCamera::viewInfo()
{
    Device::viewInfo(); // Show base device info first
    std::cout << "Camera quality: " << cameraQuality << '\n';
    std::cout << "Power type: " << powerType << '\n';
}

// ===============================
// Editable settings override
// ===============================

void SecurityCamera::editSpecificSettings()
{
    std::string quality =
        InputValidator::getString("\nEnter new camera quality (720P/1080P/4K/8K): ");
    cameraQuality = quality;

    std::cout << "\nCamera quality updated to: " << cameraQuality << '\n';

    std::cout << "\nEnter new power type (1.mains powered / 2.battery / 3.battery + solar): ";
    int input = InputValidator::getInt(1, 3);

    std::string power =
        (input == 1) ? "mains powered" :
        (input == 2) ? "battery" :
        "battery + solar";

    powerType = power;

    std::cout << "\nPower type updated to: " << powerType << '\n';
}

// ===============================
// Interaction behaviour
// ===============================

void SecurityCamera::interactionEvent()
{
    if (!checkConnection())
    {
        std::cout << "\nSecurity Camera " << name << " is not connected.\n";
        return;
    }

    if (!getIsActive())
    {
        std::cout << "\nSecurity Camera " << name << " is not active.\n";
        return;
    }

    // Minimal interaction for camera viewing
    std::cout << "\nNow viewing camera: " << name << '\n';
}