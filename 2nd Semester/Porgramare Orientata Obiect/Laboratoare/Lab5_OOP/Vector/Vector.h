
#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include "../Domain/Car.h"

// Structure to represent a collection of cars
typedef struct {
    Car* cars;
    int size;
    int capacity;
} CarVector;

/**
 * Initializes a CarVector structure by allocating memory for it.
 * The caller is responsible for freeing the allocated memory using destroyCarVector function.
 * @param car_vector pointer to a CarVector pointer that will be initialized.
 */
void initCarVector(CarVector** car_vector);
/**
 * Resizes the array of cars in the CarVector by doubling its capacity.
 * @param car_vector Pointer to the CarVector whose cars array will be resized.
 */
void resize(CarVector* car_vector);
/**
 * Frees the memory allocated for a CarVector and its cars array.
 * This function assumes that the CarVector was previously allocated using initCarVector function.
 * @param car_vector Pointer to the CarVector that will be freed.
 */
void destroyCarVector(CarVector* car_vector);
/**
 * Adds a new Car to the CarVector.
 * @param car_vector Pointer to the CarVector where the Car will be added.
 * @param car The Car object to be added to the CarVector.
 */
void add(CarVector* car_vector, Car car);
/**
 * Updates the Car at the specified index in the CarVector.
 * The Car at index i in the cars array is replaced with the new car object.
 */
void update(CarVector* car_vector, Car car, int i);
/**
 * Returns a pointer to the array of Cars in the CarVector.
 */
Car* getAll(CarVector* car_vector);
/**
 * Returns a pointer to the Car at the specified index in the CarVector.
 */
Car* getByIndex(CarVector* car_vector, int index);

#endif //VECTOR_H
