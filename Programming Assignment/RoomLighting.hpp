#ifndef ROOMLIGHTING_HPP
#define ROOMLIGHTING_HPP

#include "Device.hpp"

// ============================================
// RoomLighting device
// Represents a smart lighting system with
// adjustable brightness levels.
// Demonstrates simple device-specific behaviour.
// ============================================

class RoomLighting : public Device
{
private:
    int brightnessLevel;

public:
    RoomLighting(int id,
        const std::string& name,
        const std::string& manufacturer,
		const std::string& type,
        int brightnessLevel);

    // Overrides
    void interactionEvent() override;
    void editSpecificSettings() override;
    void viewInfo() override;
};

#endif // ROOMLIGHTING_HPP
