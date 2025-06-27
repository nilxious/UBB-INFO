#include "Vector.h"

void initCarVector(CarVector** car_vector) {
    (*car_vector) = malloc(sizeof(CarVector));
    (*car_vector)->capacity = 10;
    (*car_vector)->size = 0;
    (*car_vector)->cars = malloc(((*car_vector)->capacity*(sizeof(Car))));}

void resize(CarVector* car_vector) {
    car_vector->capacity *= 2;
    car_vector->cars = realloc((car_vector)->cars, ((car_vector)->capacity*(sizeof(Car))));
}

void destroyCarVector(CarVector* car_vector) {
    for (int i = 0; i < car_vector->size; i++){
        destroyCar(car_vector->cars[i]);
    }
    if (car_vector->cars != NULL) {
        free(car_vector->cars);
    }
    if (car_vector != NULL) {
        free(car_vector);
    }

}

void add(CarVector* car_vector, Car car) {
    if (car_vector->size == car_vector->capacity) {
        resize(car_vector);
    }
    car_vector->cars[car_vector->size++] = car;
}

void update(CarVector* car_vector, Car car, int i){
        car_vector->cars[i] = car;
}

Car* getAll(CarVector* car_vector) {
    return car_vector->cars;
}

Car* getByIndex(CarVector* car_vector, int index) {
    return &(car_vector->cars[index]);
}
