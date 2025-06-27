
#ifndef SERVICE_H
#define SERVICE_H

#include "../Repository/Repository.h"
#include "../Domain/CarValidator.h"
//Service struct
typedef struct {
    Repository* repo;
    Repository** undo_list;
    int undo_size;
    int undo_capacity;
    int undo_curent;
} Service;

/**
 * Initializes a service, setting up its repository and adding default cars.
 */
void initService(Service** s);
/**
 * Frees the memory allocated for the service and its repository.
 */
void destroyService(Service* s);
/**
 * Adds a new car to the service.
 * Validates the car's ID and category before adding it.
 * Returns:
 *   - 1 if the ID is invalid.
 *   - 2 if the category is invalid.
 *   - 0 if the car is added successfully.
 *   - -1 if the car already exists.
 */
int addCarToService(Service* service, char* id, char* model, char* category);
/**
 * Retrieves all cars stored in the service.
 * Returns:
 *   - A pointer to the array of cars.
 */
Car* getAllCarsFromService(Service* service);
/**
 * Updates a car's details in the service.
 * Validates the category before updating.
 * Returns:
 *   - 2 if the category is invalid.
 *   - 0 if the car is updated successfully.
 *   - -1 if the car does not exist.
 */
int updateCarService(Service* service, char* id, char* model, char* category);
/**
 * Gets the number of cars (integer) in the service.
 */
int getSizeService(Service* service);
/**
 * Marks a car as rented.
 * Returns:
 *   - -1 if the car is already rented
 *   - 0 if the car is rented successfully.
 */
int rentService(Service* service, char* id);
/**
 * Marks a rented car as returned.
 * Returns:
 *   - -1 if the car is not rented
 *   - 0 if the car is returned successfully.
 */
int returnService(Service* s, char* id);

/**
 * Filters cars by category.
 * Allocates memory for a new array of filtered cars.
 * Parameters:
 *   - category: The category to filter
 *   - count: A pointer to store the number of filtered cars.
 * Returns:
 *   - A dynamically allocated array of cars matching the category.
 */
Car* filterCategory(Service* s, char* category, int* count);
/**
 * Filters cars by model.
 * Parameters:
 *   - model: The model to filter by (as a char*)
 *   - count: A pointer to store the number of filtered cars.
 * Returns:
 *   - A dynamically allocated array of cars matching the model.
 */
Car* filterModel(Service* s, char* model, int* count);

/**
 * Filters cars by rented.
 * Parameters:
 *   - rented: The model to filter by (as a bool)
 *   - count: A pointer to store the number of filtered cars.
 * Returns:
 *   - A dynamically allocated array of cars matching the model.
 */
Car* filterRented(Service* s, bool rented, int* count);
/**
 * Sorts cars in the service by their category.
 @return Car* A pointer to an array of cars sorted by category. (to be freed after use)
 */
Car* sortCarsByCategory(Service* s, int);
/**
 * Sorts cars by their model name.
 * Parameters:
 *   - ascending: If 1, sorts in ascending order; if 0, sorts in descending order.
 * Returns:
 *   - A dynamically allocated sorted array of cars.
 */
Car* sortCarsByModel(Service* s, int);

/**
 * Adds default cars to the service.
 */
void add_default_cars(Service* service);

/**
 *
 * Functie  de sortare in functie de moodel sau categorie
 */
Car* sortCars(Service*, int(*cmp)(const Car*, const Car*), int);

/**
 *
 * 2 functii care ne ajuta la compararea in functie de model sau categorie
 */
int compareByModel(const Car*,const Car*);
int compareByCategory(const Car*,const Car*);
Car* sortCars3(Service* s, int (*cmp)(const Car*, const Car*), int);


int undoService(Service* service);

/**
 * Functie care asigura capacitatea undo_listului si adauga elemente in el
 *
 */

/**
 * Functie de undo
 * Return:1 daca undo ul a fost realizat cu succes
 * 0 altfel
 */

void saveUndoState(Service* service);

#endif // SERVICE_H