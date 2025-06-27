#include "Tests1.h"
#include "Car.h"
#include "CarValidator.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_createCar() {
    Car car = createCar("SV24SIZ", "Fiat", SUV);
    assert(strcmp(car.id, "SV24SIZ") == 0);
    assert(strcmp(car.model, "Fiat") == 0);
    assert(car.category == SUV);
    assert(car.rented == false);
    destroyCar(car);
}

void test_categoryToString() {
    assert(strcmp(categoryToString(MINI), "MINI") == 0);
    assert(strcmp(categoryToString(SPORT), "SPORT") == 0);
    assert(strcmp(categoryToString(HATCHBACK), "HATCHBACK") == 0);
    assert(strcmp(categoryToString(SUV), "SUV") == 0);
    assert(strcmp(categoryToString(SEDAN), "SEDAN") == 0);
    assert(strcmp(categoryToString(UNKNOWN), "UNKNOWN") == 0);
}

void test_validateId() {
    assert(validateId("AB12CDE") == 1);

    assert(validateId("AB12CD") == 0);
    assert(validateId("AB12CDEF") == 0);
    assert(validateId("aB12CDE") == 0);
    assert(validateId("ABcdCDE") == 0);
    assert(validateId("AB12CdE") == 0);
    assert(validateId("1234567") == 0);
}

void test_getCategoryFromString() {
    assert(getCategoryFromString("MINI") == MINI);
    assert(getCategoryFromString("SEDAN") == SEDAN);
    assert(getCategoryFromString("HATCHBACK") == HATCHBACK);
    assert(getCategoryFromString("SPORT") == SPORT);
    assert(getCategoryFromString("SUV") == SUV);
    assert(getCategoryFromString("TRUCK") == -2);
}
void domainTests() {
    test_createCar();
    test_categoryToString();
    test_validateId();
    test_getCategoryFromString();
    printf("domain tests passed!\n");
}




