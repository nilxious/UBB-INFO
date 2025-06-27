#include "Tests2.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Repository.h"

void test_initRepository() {
    Repository* repo;
    initRepository(&repo);
    assert(getSize(repo) == 0);
    destroyRepository(repo);
}

void test_addCar() {
    Repository* repo;
    initRepository(&repo);
    Car car1 = createCar("SV24SIZ", "FIAT", SUV);
    Car car2 = createCar("SV25SIZ", "BMW", SPORT);
    assert(addCar(repo, car1) == 0);
    assert(addCar(repo, car2) == 0);
    Car car3 = createCar("SV24SIZ", "BMW", SPORT);
    assert(addCar(repo, car3) == -1);
    destroyRepository(repo);
}

void test_updateCar() {
    Repository* repo;
    initRepository(&repo);
    Car car1 = createCar("SV24SIZ","Fiat", SUV);
    addCar(repo, car1);
    Car car2 = createCar("SV24SIZ","BMW", SPORT);
    assert(updateCar(repo, car2) == 0);
    Car car3 = createCar("SV25SIZ","BMW", SPORT);
    assert(updateCar(repo, car3) == -1);
    destroyRepository(repo);
}

void test_getAllCars() {
    Repository* repo = NULL;
    initRepository(&repo);
    Car car1 = createCar("SV24SIZ", "FIAT", SUV);
    addCar(repo, car1);
    Car* cars = getAllCars(repo);
    assert(cars != NULL);
    assert(strcmp(cars[0].id, "SV24SIZ") == 0);
    destroyRepository(repo);
}

void test_getSize() {
    Repository* repo = NULL;
    initRepository(&repo);
    assert(getSize(repo) == 0);
    Car car1 = createCar("SV24SIZ", "FIAT", SUV);
    addCar(repo, car1);
    assert(getSize(repo) == 1);
    destroyRepository(repo);
}

void test_rent() {
    Repository* repo = NULL;
    initRepository(&repo);
    Car car1 = createCar("SV24SIZ", "FIAT", SUV);
    addCar(repo, car1);
    rent(repo, "SV24SIZ");
    assert(getAllCars(repo)[0].rented == true);
    assert(rent(repo,"SV24SIZ") == -1);
    destroyRepository(repo);
}

void test_returnCar() {
    Repository* repo = NULL;
    initRepository(&repo);
    Car car1 = createCar("SV24SIZ", "FIAT", SUV);
    addCar(repo, car1);
    rent(repo, "SV24SIZ");
    returnCar(repo, "SV24SIZ");
    assert(getAllCars(repo)[0].rented == false);
    assert(returnCar(repo,"SV24SIZ") == -1);
    assert(returnCar(repo,"SV33SIZ") == 0);
    assert(rent(repo,"SV33SIZ") == 0);
    destroyRepository(repo);
}

void repositoryTests() {
    test_initRepository();
    test_addCar();
    test_updateCar();
    test_getAllCars();
    test_getSize();
    test_rent();
    test_returnCar();
    printf("repository tests passed!\n");
}
