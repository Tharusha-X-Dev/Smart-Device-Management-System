#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

// ============================================
// Base Device class
// Represents a generic smart device in the system.
// Provides shared attributes and polymorphic
// interfaces for all derived device types.
// ============================================

class Device
{
protected:
    int id;
    std::string name;
    std::string manufacturer;
	std::string deviceType; 
    bool status;
    bool isConnected;

public:
    // Constructor
    Device(int id, const std::string& name, const std::string& manufacturer, const std::string& type);

    // Basic control 
    void activate();
    void deactivate();
    void changeConnectionStatus();

    // Getters
    bool checkConnection() const;
    bool getIsActive() const;
    std::string getName() const;
    int getId() const;

    // Setters
    void setName(const std::string& newName);
    void setManufacturer(const std::string& newManufacturer);

    // Polymorphic behaviour
    virtual void interactionEvent() = 0;   // Must be implemented by derived classes
    virtual void editSpecificSettings();  // Optional override
    virtual void viewInfo();              // Can be extended by derived classes

    // Virtual destructor for polymorphic deletion
    virtual ~Device() = default;
};

#endif // DEVICE_HPP
