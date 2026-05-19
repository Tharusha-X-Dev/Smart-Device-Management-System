#ifndef AIRCONDITIONING_HPP
#define AIRCONDITIONING_HPP

#include "Device.hpp"
#include <string>

// ============================================
// AirConditioning device
// Represents a smart AC unit with adjustable
// target temperature.
// Demonstrates device-specific behaviour
// through polymorphism.
// ============================================
 
class AirConditioning : public Device
{
private:
    float targetTemperature;
     
public:
    AirConditioning(int id,
        const std::string& name,
        const std::string& manufacturer,
		const std::string& type,
        float targetTemperature);

    void interactionEvent() override;
    void editSpecificSettings() override;
    void viewInfo() override;

    // Specific setter
    void setTargetTemperature(float temp);
};

#endif // AIRCONDITIONING_HPP
