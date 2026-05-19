#include "DoorLock.hpp"
#include "inputValidator.hpp"
#include <iostream>

// ===============================
// Constructor
// ===============================

DoorLock::DoorLock(int id,
    const std::string& name,
    const std::string& manufacturer,
    const std::string& type)
    : Device(id, name, manufacturer, type),
    isLocked(true),
    lastOpenedBy("Unknown")
{
}

// ===============================
// Interaction behaviour
// ===============================

void DoorLock::interactionEvent()
{
    if (!checkConnection())
    {
        std::cout << "\nDoor Lock " << name << " is not connected.\n";
        return;
    }

    if (!getIsActive())
    {
        std::cout << "\nDoor Lock " << name << " is not active.\n";
        return;
    }

    std::cout << "\nDoor is currently "
              << (isLocked ? "LOCKED" : "UNLOCKED") << ".\n";

    std::cout << "\nDo you want to toggle the lock? (y/n): ";
    bool response = InputValidator::getYesNo();

    if (!response)
    {
        std::cout << "\nNo changes made to the door lock.\n";
        return;
    }

    // Get name of the user performing the action
    std::string input = InputValidator::getString("\nEnter your name: ");
    lastOpenedBy = input;

    // Toggle lock state
    isLocked = !isLocked;

    std::cout << "\nDoor is now "
              << (isLocked ? "LOCKED" : "UNLOCKED")
              << ", Last changed by: " << lastOpenedBy << '\n';
}

// ===============================
// Editable settings override
// ===============================

void DoorLock::editSpecificSettings()
{
    std::string name = InputValidator::getString("\nEnter name of last opener: ");
    lastOpenedBy = name;
    std::cout << "\nLast opened by set to: " << lastOpenedBy << '\n';
}

// ===============================
// Information display
// ===============================

void DoorLock::viewInfo()
{
    Device::viewInfo(); // Show base device info first
    std::cout << "Lock Status: " << (isLocked ? "Locked" : "Unlocked") << '\n';
    std::cout << "Last opened by: " << lastOpenedBy << '\n';
}