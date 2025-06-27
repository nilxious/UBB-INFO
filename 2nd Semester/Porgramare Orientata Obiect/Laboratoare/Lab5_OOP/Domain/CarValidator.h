
#ifndef CARVALIDATOR_H
#define CARVALIDATOR_H

#include "Car.h"

// Function that validates if the given car ID is in the correct format.
// Returns 1 if valid, 0 if invalid.
int validateId(char* id);

// Function that converts a char* to a Category type.
// Returns the corresponding Category enum value, or -2 if the string is not valid.
Category getCategoryFromString(char* str);

#endif // CARVALIDATOR_H