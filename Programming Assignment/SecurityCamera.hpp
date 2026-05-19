#ifndef SECURITY_CAMERA_HPP
#define SECURITY_CAMERA_HPP

#include "Device.hpp"
#include <string>

// ============================================
// SecurityCamera device
// Represents a smart surveillance camera with
// configurable quality and power source.
// Demonstrates richer device specialization.
// ============================================

class SecurityCamera : public Device
{
private:
    std::string cameraQuality;
    std::string powerType;

public:
	// Constructor
    SecurityCamera(int id,
        const std::string& name,
        const std::string& manufacturer,
		const std::string& type,
        const std::string& cameraQuality,
        const std::string& powerType);

    // Overrides
    void interactionEvent() override;
    void editSpecificSettings() override;
    void viewInfo() override;
};

#endif // SECURITY_CAMERA_HPP
