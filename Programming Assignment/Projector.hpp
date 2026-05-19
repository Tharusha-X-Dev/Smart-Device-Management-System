#ifndef PROJECTOR_HPP
#define PROJECTOR_HPP

#include "Device.hpp"
#include <string>

// ============================================
// Projector device
// Represents a smart projector with adjustable
// input source and brightness settings.
// Demonstrates polymorphic behaviour.
// ============================================

class Projector : public Device
{
private:
    std::string inputSource;
    int brightnessLevel;

    // Internal interaction helpers
    void setInputSource();
    void setBrightnessLevel();
    int interactionMenu();

public:
    Projector(int id,
        const std::string& name,
        const std::string& manufacturer,
		const std::string& type,
        const std::string& inputSource,
        int brightnessLevel);

    void interactionEvent() override;
    void editSpecificSettings() override;
    void viewInfo() override;
};

#endif // PROJECTOR_HPP
