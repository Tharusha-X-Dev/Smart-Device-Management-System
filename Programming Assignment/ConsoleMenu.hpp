#ifndef CONSOLEMENU_HPP
#define CONSOLEMENU_HPP

// ============================================
// ConsoleMenu utility class
// Responsible for displaying structured
// command-line menus for user interaction.
// Separates UI presentation from core logic.
// ============================================

class ConsoleMenu
{
public:
    // Static menu renderers
    static void showMainMenu();
    static void addNewDeviceMenu();
    static void manageAllDevicesMenu();
    static void manageOneDeviceMenu();
    static void connectionManagementMenu();
};

#endif // CONSOLEMENU_HPP
