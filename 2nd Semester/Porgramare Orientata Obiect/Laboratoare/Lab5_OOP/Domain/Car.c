#include "Car.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* categoryToString(Category category) {
    switch (category) {
        case MINI:
            return "MINI";
        case SPORT:
            return "SPORT";
        case SUV:
            return "SUV";
        case SEDAN:
            return "SEDAN";
        case HATCHBACK:
            return "HATCHBACK";
        default:
            return "UNKNOWN";
            }
}

Car createCar(char* id, char* model, Category category) {
    Car car;
    car.id = malloc(strlen(id) + 1);
    strcpy(car.id, id);
    car.model = malloc(strlen(model) + 1);
    strcpy(car.model, model);
    car.category = category;
    car.rented = false;
    return car;
}

void destroyCar(Car car) {
    free(car.id);
    free(car.model);
}

void toString(Car car) {
    printf("id: %s, model: %s, category: %s, rented: %s\n",
       car.id,
       car.model,
       categoryToString(car.category),
       car.rented ? "true" : "false");
}

Car copyCar(Car car) {
    Car newCar;

    newCar.category = car.category;
    newCar.rented = car.rented;

    int idLength = (int)strlen(car.id) + 1;
    newCar.id = (char*)malloc(sizeof(char) * idLength);
    strcpy(newCar.id, car.id);

    int modelLength = (int)strlen(car.model) + 1;
    newCar.model = (char*)malloc(sizeof(char) * modelLength);
    strcpy(newCar.model, car.model);

    return newCar;
}

