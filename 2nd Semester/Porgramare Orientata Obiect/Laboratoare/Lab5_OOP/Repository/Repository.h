
#ifndef REPOSITORY_H
#define REPOSITORY_H

#define MAX_CARS 64
#include "../Vector/Vector.h"
//Repository struct - contains a pointer to a CarVector
typedef struct {
    CarVector* car_vector;
} Repository;
/**
 * Initializes a repository for storing car data.
 * Allocates memory for the repository structure and initializes its car vector.
 */
void initRepository(Repository** repo);
/**
 * Frees the memory allocated for the repository.
 * It destroys the car vector and then frees the repository itself.
 */
void destroyRepository(Repository* repo);
/**
 * Adds a car to the repository if a car with the same ID does not already exist.
 * Returns -1 if the car with the same ID is already in the repository, 0 otherwise.
 * Returns:
 * -1 if the car already exists.
 * 0 if the car is added successfully.
 */
int addCar(Repository* repo, Car car);
/**
 * Returns a pointer to the array of cars in the repository.
 */
Car* getAllCars(Repository* repo);
/**
 * Updates the information of a car in the repository if the car exists.
 * Returns -1 if the car with the given ID does not exist, 0 if the update is successful.
 */
int updateCar(Repository* repo, Car car);
/**
 * Returns the number of cars currently stored in the repository.
 */
int getSize(Repository* repo);
/**
 * Marks a car as rented if it is available.
 * Returns:
 *   - -1 if the car is already rented.
 *   - 0 if the car is rented successfully.
 */
int rent(Repository* repo, char* id);
/**
 * Marks a rented car as returned.
 * Returns -1 if the car is not rented, 0 if the car is successfully returned.
 */
int returnCar(Repository* repo, char* id);


/**
 *
 * Functie care da copy la repository
 */
Repository* copyRepository(Repository* repo);
#endif // REPOSITORY_H
