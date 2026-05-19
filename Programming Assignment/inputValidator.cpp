#include "InputValidator.hpp"
#include <iostream>
#include <limits> //for numeric_limits
#include <string> 
#include <cctype> // for tolower

// ===============================
// Integer validation
// ===============================

int InputValidator::getInt(int min, int max)
{
    int value;

    while (true)
    {
        std::cin >> value;

        bool validNumber = !std::cin.fail();              // valid numeric input
        bool cleanInput = std::cin.peek() == '\n';        // no extra characters
        bool inRange = value >= min && value <= max;      // within allowed range

        if (validNumber && cleanInput && inRange)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        // Reset stream state
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\nInvalid input. Enter a number between "
            << min << " and " << max << ": ";
    }
}

// ===============================
// Float validation
// ===============================

float InputValidator::getFloat(float min, float max)
{
    float value;

    while (true)
    {
        std::cin >> value;

        bool validNumber = !std::cin.fail();
        bool cleanInput = std::cin.peek() == '\n';
        bool inRange = value >= min && value <= max;

        if (validNumber && cleanInput && inRange)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\nInvalid input. Enter a value between "
                  << min << " and " << max << ": ";
    }
}

// ===============================
// Yes/No validation
// ===============================

bool InputValidator::getYesNo()
{
    std::string response;

    while (true)
    {
        std::cin >> response;

        // Convert to lowercase
        for (char& c : response)
        {
            c = std::tolower(c);
        }

        if (response == "yes" || response == "y")
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }

        if (response == "no" || response == "n")
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }

        std::cout << "\nInvalid input. Please type 'yes' or 'no': ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// ===============================
// String validation
// ===============================

std::string InputValidator::getString(const std::string& prompt)
{
    std::string input;

    std::cout << prompt;
    std::getline(std::cin, input);

    while (input.empty())
    {
        std::cout << "\nInput cannot be empty. Try again: ";
        std::getline(std::cin, input);
    }

    return input;
}
