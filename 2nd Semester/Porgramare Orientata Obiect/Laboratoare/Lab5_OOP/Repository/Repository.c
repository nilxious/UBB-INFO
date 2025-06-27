#include "Repository.h"
#include <stdlib.h>
#include <string.h>

void initRepository(Repository** repo) {
    *repo = (Repository*)malloc(sizeof(Repository));
    initCarVector(&((*repo)->car_vector));
}

void destroyRepository(Repository* repo) {
    destroyCarVector((repo)->car_vector);
        free(repo);
}

int addCar(Repository* repo, Car car) {
    for (int i = 0; i < repo->car_vector->size; i++) {
        if (strcmp(car.id, repo->car_vector->cars[i].id) == 0) {
            destroyCar(car);
            return -1;
        }
    }
    add((repo->car_vector), car);
    return 0;
}

int updateCar(Repository* repo, Car car) {
    for (int i = 0; i < repo->car_vector->size; i++)
        if (strcmp(car.id, repo->car_vector->cars[i].id) == 0){
            destroyCar(repo->car_vector->cars[i]);
            update((repo->car_vector), car, i);
            return 0;
        }
    destroyCar(car);
    return -1;
}

Car* getAllCars(Repository* repo) {
    return repo->car_vector->cars;
}

int getSize(Repository* repo) {
    return repo->car_vector->size;
}

int rent(Repository* repo, char* id) {
    for (int i = 0; i < repo->car_vector->size; i++)
        if (strcmp(repo->car_vector->cars[i].id, id) == 0) {
            if (getByIndex(repo->car_vector, i)->rented == true)
                return -1;
            else {
                getByIndex(repo->car_vector, i)->rented = true;
                return 0;}}
return 0;}

int returnCar(Repository* repo, char* id) {
    for (int i = 0; i < repo->car_vector->size; i++)
        if (strcmp(repo->car_vector->cars[i].id, id) == 0) {
            if (getByIndex(repo->car_vector, i)->rented == false)
                return -1;
            else {
                getByIndex(repo->car_vector, i)->rented = false;
                return 0;}}
return 0;}

Repository* copyRepository(Repository* repo) {
    Repository* newRepo = malloc(sizeof(Repository));

    newRepo->car_vector = malloc(sizeof(CarVector));

    newRepo->car_vector->size = repo->car_vector->size;
    newRepo->car_vector->capacity = repo->car_vector->capacity;

    newRepo->car_vector->cars = malloc(sizeof(Car) * newRepo->car_vector->capacity);

    for (int i = 0; i < repo->car_vector->size; i++) {
        newRepo->car_vector->cars[i] = copyCar(repo->car_vector->cars[i]);
    }

    return newRepo;
}