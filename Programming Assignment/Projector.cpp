#include "Projector.hpp"
#include "inputValidator.hpp"
#include <iostream>

// ===============================
// Constructor
// ===============================

Projector::Projector(int id,
    const std::string& name,
    const std::string& manufacturer,
	const std::string& type,
    const std::string& inputSource,
    int brightnessLevel)
    : Device(id, name, manufacturer,type),
    inputSource(inputSource),
    brightnessLevel(brightnessLevel)
{
}

// ===============================
// Information display
// ===============================

void Projector::viewInfo()
{
    Device::viewInfo(); // Call base info first

    std::cout << "Input Source: " << inputSource << '\n';
    std::cout << "Brightness: " << brightnessLevel << '\n';
}

// ===============================
// Interaction behaviour
// ===============================

void Projector::interactionEvent()
{
    if (!checkConnection())
    {
        std::cout << "\nProjector " << name << " is not connected.\n";
        return;
    }

    if (!getIsActive())
    {
        std::cout << "\nProjector " << name << " is not active.\n";
        return;
    }

    std::cout << "\nProjector is active. "
        << "Current input source: " << inputSource
        << ", Brightness: " << brightnessLevel << '\n';

    // Loop until user exits interaction menu
    while (true)
    {
        int choice = interactionMenu();
        switch (choice)
        {
        case 1:
            setInputSource();
            std::cout << "\nInput source updated to: " << inputSource << '\n';
            break;

        case 2:
            setBrightnessLevel();
            std::cout << "\nBrightness updated to: " << brightnessLevel << '\n';
            break;

        default:
            std::cout << "\nExiting projector interaction menu.\n";
            return;
        }
    }
}

// ===============================
// Internal helpers
// ===============================

void Projector::setBrightnessLevel()
{
    std::cout << "\nEnter brightness level (0-100): ";
    int value = InputValidator::getInt(0, 100);
    brightnessLevel = value;
}

void Projector::setInputSource()
{
    std::cout << "\nSelect input source (1.HDMI / 2.VGA / 3.USB): ";
    int choice = InputValidator::getInt(1, 3);

    switch (choice)
    {
    case 1: inputSource = "HDMI"; break;
    case 2: inputSource = "VGA"; break;
    default: inputSource = "USB"; break;
    }
}

int Projector::interactionMenu()
{
    std::cout << "\nProjector Interaction Menu:\n"
        << "1. Change Input Source\n"
        << "2. Adjust Brightness\n"
        << "3. Exit\n"
        << "\nEnter choice: ";

    return InputValidator::getInt(1, 3);
}

// ===============================
// Editable settings override
// ===============================

void Projector::editSpecificSettings()
{
    std::cout << "\nProjector Settings:\n"
        << "1. Change brightness\n"
        << "2. Change input source\n"
        << "0. Exit\n"
        << "\nEnter choice: ";

    int choice = InputValidator::getInt(0, 2);

    if (choice == 1)
        setBrightnessLevel();
    else if (choice == 2)
        setInputSource();
    else
        std::cout << "\nExiting projector settings.\n";
}