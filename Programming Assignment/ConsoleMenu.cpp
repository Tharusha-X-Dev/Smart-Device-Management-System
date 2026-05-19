#include "ConsoleMenu.hpp"
#include <iostream>

void ConsoleMenu::showMainMenu()
{
    std::cout << R"(
==========================================
      Smart Campus Device Manager Menu    
==========================================
1. Manage All Devices
2. Manage One Device
3. Add Device
4. Remove Device
5. Connection Management
0. Exit

Enter your choice: )";

}

void ConsoleMenu::addNewDeviceMenu()
{
    std::cout << R"(
Add New Device :

1. Projector
2. Door Lock
3. Security Camera
4. Room Lighting
5. Air Conditioning
0. Cancel

Enter your choice: )";

}

void ConsoleMenu::manageAllDevicesMenu()
{
    std::cout << R"(
==========================================
      Manage All Devices Menu   
==========================================
1. View All
2. Activate All
3. Deactivate All
4. Interact All
0. Back

Enter Your choice: )";
}

void ConsoleMenu::manageOneDeviceMenu()
{
    std::cout << R"(
==========================================
      Manage One Devices Menu   
==========================================
1. View device info
2. Activate device
3. Deactivate device
4. Interact with device
5. Edit device
0. Back

Enter Your choice: )";
}

void ConsoleMenu::connectionManagementMenu() 
{
    std::cout << R"(
==========================================
      Connection Management Menu   
==========================================
1. Show connected devices
2. Show disconnected devices
3. Toggle device connection
0. Back

Enter Your choice: )";
}