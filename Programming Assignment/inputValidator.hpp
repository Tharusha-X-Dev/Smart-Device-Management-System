#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <string>

// ============================================
// InputValidator utility class
// Provides static helper functions for
// validating and sanitizing console input.
// Ensures robust user input handling.
// ============================================

class InputValidator
{
public:
    // Static validation helpers
    static int getInt(int min, int max);
    static float getFloat(float min, float max);
    static bool getYesNo();
    static std::string getString(const std::string& prompt);
};

#endif // INPUTVALIDATOR_HPP
