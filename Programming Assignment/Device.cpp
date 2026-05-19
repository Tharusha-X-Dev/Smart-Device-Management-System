#include "Device.hpp"
#include <iostream>

Device::Device(int id, 
    const std::string& name, 
    const std::string& manufacturer, 
    const std::string& type)
    : id(id), 
    name(name), 
    manufacturer(manufacturer), 
    deviceType(type), 
    status(false), 
    isConnected(true)
{
}

// ===============================
// Activation control
// ===============================

void Device::activate()
{
    if (!isConnected)
    {
        std::cout << "\nCannot activate " << name
                  << " because it is not connected.\n";
        return;
    }

    if (status)
    {
        std::cout << "\nDevice " << name << " is already active.\n";
        return;
    }

    status = true;
}

void Device::deactivate()
{
    if (!isConnected)
    {
        std::cout << "\nCannot deactivate " << name
                  << " because it is not connected.\n";
        return;
    }

    if (!status)
    {
        std::cout << "\nDevice " << name << " is already inactive.\n";
        return;
    }

    status = false;
}

// ===============================
// Information display
// ===============================

void Device::viewInfo()
{
    std::cout << "\nDevice ID: " << id << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Manufacturer: " << manufacturer << '\n';
	std::cout << "Type: " << deviceType << '\n';
    std::cout << "Status: " << (status ? "Active" : "Inactive") << '\n';
    std::cout << "Connection: " << (isConnected ? "Connected" : "Disconnected") << '\n';
}

// ===============================
// Getters
// ===============================

bool Device::checkConnection() const
{
    return isConnected;
}

bool Device::getIsActive() const
{
    return status;
}

std::string Device::getName() const
{
    return name;
}

int Device::getId() const
{
    return id;
}

// ===============================
// State modifications (Setters)
// ===============================

void Device::changeConnectionStatus()
{
    isConnected = !isConnected;
}

void Device::setName(const std::string& newName)
{
    name = newName;
    std::cout << "\nDevice name updated to: " << name << '\n';
}

void Device::setManufacturer(const std::string& newManufacturer)
{
    manufacturer = newManufacturer;
    std::cout << "\nDevice manufacturer updated to: " << manufacturer << '\n';
}

// ===============================
// Virtual defaults
// ===============================

// Default implementation for devices without editable settings
void Device::editSpecificSettings()
{
    std::cout << "\nNo editable specific settings.\n";
}
