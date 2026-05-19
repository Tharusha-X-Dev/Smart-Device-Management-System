#include "DeviceManager.hpp"
#include "ConsoleMenu.hpp"
#include "inputValidator.hpp"

#include "AirConditioning.hpp"
#include "Projector.hpp"
#include "RoomLighting.hpp"
#include "SecurityCamera.hpp"
#include "DoorLock.hpp"

#include <iostream>

// ======================================================
// Utility Helpers
// ======================================================

bool DeviceManager::hasDevices() const
{
    if (devices.empty())
    {
        std::cout << "\nNo devices in the system.\n";
        return false;
    }
    return true;
}

Device* DeviceManager::findDeviceById(int id)
{
    for (auto& d : devices) {

        if (d->getId() == id) {
            return d.get();
        }
    }

    return nullptr;
}

Device* DeviceManager::selectDeviceById()
{
    if (!hasDevices()) return nullptr;

    std::cout << "\nAvailable Devices:\n";

    for (auto& d : devices) {
        std::cout << "ID: " << d->getId() 
                  << " - " << d->getName() << '\n';
    }
        
    std::cout << "\nEnter device ID (0 to cancel): ";

	int id = InputValidator::getInt(0, 1000); // Assume ID won't exceed 1000 for simplicity

    if (id == 0) return nullptr;

    Device* selected = findDeviceById(id);

    if (!selected)
        std::cout << "\nInvalid ID.\n";

    return selected;
}

// ======================================================
// Core Loop
// ======================================================
void DeviceManager::run()
{
    int choice = -1;

    do
    {
        ConsoleMenu::showMainMenu();
        choice = InputValidator::getInt(0, 5);

        switch (choice)
        {
            // ===============================
            // Manage All Devices
            // ===============================
        case 1:
        {
            int subChoice;
            do
            {
                ConsoleMenu::manageAllDevicesMenu();
                subChoice = InputValidator::getInt(0, 4);

                switch (subChoice)
                {
                case 1: viewAllDevices(); break;
                case 2: activateAll(); break;
                case 3: deactivateAll(); break;
                case 4: interactAll(); break;
                }
            } while (subChoice != 0);
            break;
        }

        // ===============================
        // Manage One Device
        // ===============================
        case 2:
        {
            int subChoice;
            do
            {
                ConsoleMenu::manageOneDeviceMenu();
                subChoice = InputValidator::getInt(0, 5);

                switch (subChoice)
                {
                case 1: viewOneDeviceInfo(); break;
                case 2: activateOne(); break;
                case 3: deactivateOne(); break;
                case 4: interactOne(); break;
                case 5: editDevice(); break;
                }
            } while (subChoice != 0);
            break;
        }

        // ===============================
		// Add New Device
        // ===============================
        case 3:
            addNewDevice();
			break;
           
        // ===============================
        // Remove a Device
        // ===============================
        case 4:
            removeDevice();
			break;

        // ===============================
        // Connection Management
        // ===============================
        case 5:
        {
            int subChoice;
            do
            {
                ConsoleMenu::connectionManagementMenu();
                subChoice = InputValidator::getInt(0, 3);

                switch (subChoice)
                {
                case 1: showConnectedDevices(); break;
                case 2: showDisconnectedDevices(); break;
                case 3: toggleDeviceConnection(); break;
                }
            } while (subChoice != 0);
            break;
        }

        case 0:
            std::cout << "\nExiting Device Manager.\n";
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ======================================================
// Bulk Operations
// ======================================================

void DeviceManager::viewAllDevices()
{
    if (!hasDevices()) return; // if the vector is empty, return

    for (auto& device : devices)
    {
        device->viewInfo();
        std::cout << "------------------------\n";
    }
}

void DeviceManager::activateAll()
{
    if (!hasDevices()) return;

    for (auto& d : devices) {

		if (!d->checkConnection())
        {
            std::cout << "\nDevice " << d->getName() << " is not connected. Skipping activation.\n";
            continue;
        }

        if (d->getIsActive())
        {
            std::cout << "\nDevice " << d->getName() << " is already active. Skipping.\n";
            continue;
		}

        if (d->checkConnection() && !d->getIsActive()) {
            d->activate();
            std::cout << "\nDevice " << d->getName() << " activated.\n";
        }
    
    }
    //std::cout << "\nAll devices activated.\n";
}

void DeviceManager::deactivateAll()
{
    if (!hasDevices()) return;

    for (auto& d : devices) {

		if (d->getIsActive() && d->checkConnection())
        {
            d->deactivate();
            std::cout << "\nDevice " << d->getName() << " deactivated.\n";
        }
        else if (!d->checkConnection())
        {
            std::cout << "\nDevice " << d->getName() << " is not connected. Skipping deactivation.\n";
            continue;
		}
        else if (!d->getIsActive())
        {
            std::cout << "\nDevice " << d->getName() << " is already inactive. Skipping.\n";
			continue;
        }
    }
}

void DeviceManager::interactAll()
{
    if (!hasDevices()) return;

    for (auto& d : devices) {

		if (d->getIsActive() && d->checkConnection())
        {
            std::cout << "\nInteracting with " << d->getName() << "...\n";
            d->interactionEvent();
        }
        else if (!d->checkConnection())
        {
            std::cout << "\nDevice " << d->getName() << " is not connected. Skipping interaction.\n";
        }
        else if (!d->getIsActive())
        {
            std::cout << "\nDevice " << d->getName() << " is not active. Skipping interaction.\n";
        }
    }
}

// ======================================================
// Single Device Operations
// ======================================================

void DeviceManager::viewOneDeviceInfo()
{
    Device* device = selectDeviceById();
    if (device) device->viewInfo();
}

void DeviceManager::activateOne()
{
    Device* device = selectDeviceById();
    if (device)
    {
        device->activate();
		std::cout << "\nDevice " << device->getName() << " activated.\n";
    }
}

void DeviceManager::deactivateOne()
{
    Device* device = selectDeviceById();
    if (device)
    {
        device->deactivate();
		std::cout << "\nDevice " << device->getName() << " deactivated.\n";
    }
}

void DeviceManager::interactOne()
{
    Device* device = selectDeviceById();

    if (device) device->interactionEvent();
}

// ======================================================
// Connection Management
// ======================================================

void DeviceManager::showConnectedDevices()
{
    std::cout << "\nConnected Devices:\n---------------------\n";

    if (!hasDevices()) return;

    bool found = false;

    for (auto& d : devices)
    {
        if (d->checkConnection())
        {
            std::cout << "ID: " << d->getId() << " - " << d->getName() << '\n';
            found = true;
        }
    }

    if (!found)
        std::cout << "\nNo connected devices found.\n";
}

void DeviceManager::showDisconnectedDevices()
{
    std::cout << "\nDisconnected Devices:\n---------------------\n";

    if (!hasDevices()) return;

    bool found = false;

    for (auto& d : devices)
    {
        if (!d->checkConnection())
        {
            std::cout << "ID: " << d->getId() << " - " << d->getName() << '\n';
            found = true;
        }
    }

    if (!found)
        std::cout << "\nNo disconnected devices found.\n";
}

void DeviceManager::toggleDeviceConnection()
{
    Device* device = selectDeviceById();
    if (!device) return;

    device->changeConnectionStatus();

    std::cout << "\n" << device->getName()
              << (device->checkConnection() ? " is now connected.\n" : " is now disconnected.\n");
}

// ======================================================
// Device Creation Helpers
// ======================================================

std::unique_ptr<Device> DeviceManager::createProjector(int id, const std::string& name, const std::string& manufacturer)
{
    std::cout << "\n1. HDMI\n2. VGA\n3. USB\n\nEnter input source: ";
    int input = InputValidator::getInt(1, 3);

    std::string source = (input == 1) ? "HDMI" :(input == 2) ? "VGA" : "USB";

    std::cout << "\nEnter brightness level (0-100): ";

    int brightness = InputValidator::getInt(0, 100);

    return std::make_unique<Projector>(id, name, manufacturer, "Projector", source, brightness);
}

std::unique_ptr<Device> DeviceManager::createSecurityCamera(int id, const std::string& name, const std::string& manufacturer)
{
    std::string quality = InputValidator::getString("\nEnter Camera quality (720P/1080P/4K/8K) : ");

    std::cout << "\n1. mains powered\n2. battery\n3. battery + solar\n\nEnter power source: ";
    int input = InputValidator::getInt(1, 3);

    std::string power = (input == 1) ? "mains powered" : (input == 2) ? "battery" : "battery + solar";

    return std::make_unique<SecurityCamera>(id, name, manufacturer,"Security Camera", quality, power);
}

// ======================================================
// Add New Device
// ======================================================

void DeviceManager::addNewDevice()
{
    ConsoleMenu::addNewDeviceMenu();

    int choice = InputValidator::getInt(0, 5);
    if (choice == 0) return;

    int id = nextId++;

    std::string name = InputValidator::getString("\nEnter device name: ");
    std::string manufacturer = InputValidator::getString("\nEnter manufacturer: ");

    std::unique_ptr<Device> newDevice;

    switch (choice)
    {
    case 1: newDevice = createProjector(id, name, manufacturer); break;
    case 2: newDevice = std::make_unique <DoorLock>(id, name, manufacturer, "Door Lock"); break;
    case 3: newDevice = createSecurityCamera(id, name, manufacturer); break;

    case 4:
    {
        std::cout << "\nEnter brightness level (0-100): ";
        int brightness = InputValidator::getInt(0, 100);
        newDevice = std::make_unique <RoomLighting>(id, name, manufacturer,"Room Light", brightness);
        break;
    }

    case 5:
    {
        std::cout << "\nEnter target temperature (16 - 30 C): ";
        float temp = InputValidator::getFloat(16, 30);
        newDevice = std::make_unique<AirConditioning>(id, name, manufacturer, "Air Conditioner", temp);
        break;
    }
    default:
		std::cout << "\nInvalid choice.\n";
    }

    if (newDevice)
    {
        devices.push_back(std::move(newDevice));
        std::cout << "\nDevice added successfully! (ID: " << id << ")\n";
    }
}

// ======================================================
// Remove an old Device
// ======================================================
void DeviceManager::removeDevice()
{
    Device* device = selectDeviceById();
    if (!device) return;

    for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        if (it->get() == device)   // get the raw ptr from the unique ptr and Compare with raw ptr
        {
            devices.erase(it);     // Erase owner (unique_ptr)
            std::cout << "\nDevice removed successfully.\n";
            return;
        }
    }
}

// ======================================================
// Edit Device Attributes
// ======================================================

void DeviceManager::editDevice()
{
    Device* d = selectDeviceById();

    if (!d) return;

    if (!d->checkConnection()) {

        std::cout << "\nDevice " << d->getName() << " is not connected. Cannot edit settings.\n";
		return;
    }

    std::cout << "\n1. Change name\n"
              << "2. Change manufacturer\n"
              << "3. Edit device-specific settings\n"
              << "\nEnter your Choice: ";

    int choice = InputValidator::getInt(1, 3);

    if (choice == 1)
        d->setName(InputValidator::getString("\nNew name: "));
    else if (choice == 2)
        d->setManufacturer(InputValidator::getString("\nNew manufacturer: "));
    else
		d->editSpecificSettings(); //Call the virtual function to handle device-specific settings
}
