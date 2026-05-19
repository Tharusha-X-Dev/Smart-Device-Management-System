#ifndef DEVICEMANAGER_HPP
#define DEVICEMANAGER_HPP

#include "Device.hpp"
#include <vector>
#include <memory>


// ======================================================
// DeviceManager
// Central controller responsible for managing the
// lifecycle, interaction, and ownership of devices.
// Uses smart pointers to ensure safe memory management
// and encapsulates system-level operations.
// ======================================================

class DeviceManager
{
private:
    // ======================================================
    // Data
    // ======================================================
    std::vector<std::unique_ptr<Device>> devices;
	int nextId = 1; //ID generator for new devices

    // ======================================================
    // Utility Helpers
    // ======================================================
    bool hasDevices() const;
    Device* findDeviceById(int id);
    Device* selectDeviceById();

    // ======================================================
    // View Operations
    // ======================================================
    void viewAllDevices();
    void viewOneDeviceInfo();

    // ======================================================
    // Bulk Operations
    // ======================================================
    void activateAll();
    void deactivateAll();
    void interactAll();

    // ======================================================
    // Single Device Operations
    // ======================================================
    void activateOne();
    void deactivateOne();
    void interactOne();

    // ======================================================
    // Connection Management
    // ======================================================
    void showConnectedDevices();
    void showDisconnectedDevices();
    void toggleDeviceConnection();

    // ======================================================
    // Device Creation Helpers
    // ======================================================
    std::unique_ptr<Device> createProjector(int id, const std::string& name, const std::string& manufacturer);
    std::unique_ptr<Device> createSecurityCamera(int id, const std::string& name, const std::string& manufacturer);

    void addNewDevice();
    void removeDevice();
    void editDevice();

public:
    // ======================================================
    // Entry point
    // ======================================================
    void run();
};

#endif // DEVICEMANAGER_HPP
