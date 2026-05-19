#ifndef DOORLOCK_HPP
#define DOORLOCK_HPP

#include "Device.hpp"
#include <string>

// ============================================
// DoorLock device
// Represents a smart door lock with basic
// lock/unlock interaction and tracking of
// the last user interaction.
// ============================================

class DoorLock : public Device
{
private:
    bool isLocked;
    std::string lastOpenedBy;

public:
    DoorLock(int id,
        const std::string& name,
        const std::string& manufacturer,
        const std::string& type);

    // Overrides
    void interactionEvent() override;
    void editSpecificSettings() override;
	void viewInfo() override;
};

#endif // DOORLOCK_HPP
