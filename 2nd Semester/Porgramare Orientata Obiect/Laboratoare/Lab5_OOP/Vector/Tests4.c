//
// Created by hp on 14/03/2025.
//

#include "Tests4.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void testAdd() {
    CarVector* carVector;
    initCarVector(&carVector);
    Car car1 = createCar("AB12GHJ", "Model1", MINI);
    add(carVector, car1);
    assert(carVector->size == 1);
    assert(strcmp(carVector->cars[0].id, "AB12GHJ") == 0);
    assert(strcmp(carVector->cars[0].model, "Model1") == 0);
    assert(carVector->cars[0].category == MINI);
    destroyCarVector(carVector);
}

void testUpdate() {
    CarVector* carVector;
    initCarVector(&carVector);
    Car car1 = createCar("ABC1234", "Model1", MINI);
    add(carVector, car1);
    Car car2 = createCar("ABC1234", "UpdatedModel", SUV);
    update(carVector, car2, 0);
    assert(strcmp(carVector->cars[0].model, "UpdatedModel") == 0);
    assert(carVector->cars[0].category == SUV);
    destroyCar(car1);
    destroyCarVector(carVector);
}

void testGetAll() {
    CarVector* carVector;
    initCarVector(&carVector);
    Car car1 = createCar("ABC1234", "Model1", MINI);
    add(carVector, car1);
    Car car2 = createCar("DEF5678", "Model2", SUV);
    add(carVector, car2);
    Car* cars = getAll(carVector);
    assert(carVector->size == 2);
    assert(strcmp(cars[0].id, "ABC1234") == 0);
    assert(strcmp(cars[1].id, "DEF5678") == 0);
    destroyCarVector(carVector);
}

void testGetByIndex() {
    CarVector* carVector;
    initCarVector(&carVector);
    Car car1 = createCar("ABC1234", "Model1", MINI);
    add(carVector, car1);
    Car car2 = createCar("DEF5678", "Model2", SUV);
    add(carVector, car2);
    Car* carAtIndex0 = getByIndex(carVector, 0);
    Car* carAtIndex1 = getByIndex(carVector, 1);
    assert(strcmp(carAtIndex0->id, "ABC1234") == 0);
    assert(strcmp(carAtIndex1->id, "DEF5678") == 0);
    destroyCarVector(carVector);
}

void vectorTests() {
    testAdd();
    testUpdate();
    testGetAll();
    testGetByIndex();
    printf("vector tests passed\n");
}
