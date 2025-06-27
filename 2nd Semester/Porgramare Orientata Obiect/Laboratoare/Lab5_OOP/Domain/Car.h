
#ifndef CAR_H
#define CAR_H
#define STRING_LENGTH 32
#include <stdbool.h>

// Enum to represent the categories of cars.
typedef enum {
    MINI,
    SPORT,
    SUV,
    SEDAN,
    HATCHBACK,
    UNKNOWN = -2
} Category;
// Structure representing a car with its ID, model, category, and rental status.
typedef struct {
    char* id;//[STRING_LENGTH];
    char* model;//[STRING_LENGTH];
    Category category;
    bool rented;
} Car;

// Function to create a car with the specified id, model, and category.
// Returns the car and sets rented status to false by default.
Car createCar(char* id, char* model, Category category);

// Function to print the details of a car in a readable format.
void toString(Car car);

// Function to convert and return the category enum to a char* representation.
// For example, MINI to "MINI"
char* categoryToString(Category category);

//functie care distruge o masina
void destroyCar(Car car);

//functie care copiaza masina
Car copyCar(Car car);

#endif