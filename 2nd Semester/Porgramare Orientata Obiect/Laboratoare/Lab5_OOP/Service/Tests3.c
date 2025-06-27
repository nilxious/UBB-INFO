//
// Created by hp on 14/03/2025.
//

#include "Tests3.h"
#include "Service.h"
#include "../Domain/CarValidator.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_initService() {
    Service* service = NULL;
    initService(&service);
    assert(getSizeService(service) == 16);
    destroyService(service);
}

void test_addCarToService() {
    Service* service = NULL;
    initService(&service);
    assert(addCarToService(service, "SV23SIZ", "FIAT", "HATCHBACK") == 0);
    assert(addCarToService(service, "123", "BMW", "Sport") == 1);
    assert(addCarToService(service, "SV99XUU", "BMW", "InvalidCategory") == 2);
    assert(addCarToService(service, "SV24SIZ", "Audi", "SUV") == -1);
    destroyService(service);
}
void test_getAllCarsFromService() {
    Service* service = NULL;
    initService(&service);
    Car* cars = getAllCarsFromService(service);
    assert(cars != NULL);
    assert(getSizeService(service) == 16);
    assert(strcmp(cars[0].id, "SV24SIZ") == 0);
    assert(strcmp(cars[1].model, "BMW") == 0);
    destroyService(service);
}

void test_updateCarService() {
    Service* service = NULL;
    initService(&service);
    assert(updateCarService(service, "SV24SIZ", "Audi", "SUV") == 0);
    assert(updateCarService(service, "SV24SIZ", "Audi", "InvalidCategory") == 2);
    assert(updateCarService(service, "IS24SIZ", "BMW", "SUV") == -1);
    destroyService(service);
}

void test_getSizeService() {
    Service* service = NULL;
    initService(&service);
    assert(getSizeService(service) == 16);
    addCarToService(service, "SV24SIZ", "Honda", "SUV");
    assert(getSizeService(service) == 16);
    destroyService(service);
}

void test_rentService() {
    Service* service = NULL;
    initService(&service);
    rentService(service, "SV24SIZ");
    assert(getAllCarsFromService(service)[0].rented == true);
    destroyService(service);
}
void test_returnService() {
    Service* service = NULL;
    initService(&service);
    rentService(service, "SV24SIZ");
    returnService(service, "SV24SIZ");
    assert(getAllCarsFromService(service)[0].rented == false);
    destroyService(service);
}

void test_filterCategory() {
    Service* service = NULL;
    initService(&service);
    int count = 0;
    Car* filteredCars = filterCategory(service, "SUV", &count);
    assert(count == 4);
    assert(filteredCars != NULL);
    free(filteredCars);
    destroyService(service);
}

void test_filterModel() {
    Service* service = NULL;
    initService(&service);
    int count = 0;
    Car* filteredCars = filterModel(service, "Fiat", &count);
    assert(count == 2);
    assert(filteredCars != NULL);
    free(filteredCars);
    filteredCars = filterModel(service, "Seat", &count);
    assert(count == 0);
    free(filteredCars);
    destroyService(service);
}
void test_filterRented() {
    Service* service = NULL;
    initService(&service);
    int count = 0;

    Car* filteredCars = filterRented(service, 1, &count);
    assert(count == 0);
    assert(filteredCars != NULL);
    free(filteredCars);

    filteredCars = filterRented(service, 0, &count);
    assert(count == 16);
    assert(filteredCars != NULL);
    free(filteredCars);

    filteredCars = filterRented(service, 2, &count);
    assert(count == 0);
    free(filteredCars);

    destroyService(service);
}

void test_sortCarsByModel() {
    Service* service = NULL;
    initService(&service);
    Car* sortedCars = sortCars(service,compareByModel,1);//sortCarsByModel(service, 1);
    assert(strcmp(sortedCars[0].model, "Audi") == 0);
    assert(strcmp(sortedCars[1].model, "BMW") == 0);
    free(sortedCars);
    destroyService(service);
}

void test_sortCarsByCategory() {
    Service* service = NULL;
    initService(&service);
    Car* sortedCars = sortCars(service,compareByCategory,1);//sortCarsByCategory(service, 1);
    assert(sortedCars[0].category <= sortedCars[1].category);
    assert(sortedCars[1].category <= sortedCars[2].category);
    Car* desc = sortCars(service,compareByModel,0);
    assert(desc[0].category >= desc[1].category);
    assert(desc[4].category >= desc[5].category);
    free(desc);
    free(sortedCars);
    destroyService(service);
}
// void test_sortCarsByModel2() {
//     Service* service = NULL;
//     initService(&service);
//     Car* sortedCars = sortCars2(service,compareByModel,1);//sortCarsByModel(service, 1);
//     assert(strcmp(sortedCars[0].model, "Audi") == 0);
//     assert(strcmp(sortedCars[1].model, "BMW") == 0);
//     free(sortedCars);
//     destroyService(service);
// }
//
// void test_sortCarsByCategory2() {
//     Service* service = NULL;
//     initService(&service);
//     Car* sortedCars = sortCars2(service,compareByCategory,1);//sortCarsByCategory(service, 1);
//     assert(sortedCars[0].category <= sortedCars[1].category);
//     assert(sortedCars[1].category <= sortedCars[2].category);
//     Car* desc = sortCars2(service,compareByModel,0);
//     assert(desc[0].category >= desc[1].category);
//     assert(desc[4].category >= desc[5].category);
//     free(desc);
//     free(sortedCars);
//     destroyService(service);
// }
void test_saveUndoState() {
    Service* service;
    initService(&service);

    int initialUndoSize = service->undo_size;
    int initialUndoIndex = service->undo_curent;
    addCarToService(service, "ABCDEFG", "Ceva", "SUV");

    assert(service->undo_size == initialUndoSize + 1);
    assert(service->undo_curent == initialUndoIndex + 1);

    addCarToService(service, "ABCDEFH", "Ceva2", "SUV");

    assert(service->undo_size == initialUndoSize + 2);
    assert(service->undo_curent == initialUndoIndex + 2);

    destroyService(service);
}

void test_undoService() {
    Service* service;
    initService(&service);

    int undoResultEmpty = undoService(service);
    assert(undoResultEmpty == 0);

    int initialSize = getSizeService(service);

    addCarToService(service, "AB12CDE", "Ceva", "SUV");
    assert(getSizeService(service) == initialSize + 1);

    int undoResult = undoService(service);
    assert(undoResult == 1);
    assert(getSizeService(service) == initialSize);

    destroyService(service);
}
void test_saveUndoState_resize() {
    Service* service;
    initService(&service);

    int initialUndoSize = service->undo_size;
    int initialUndoCapacity = service->undo_capacity;

    for (int i = 0; i <= initialUndoCapacity; i++) {
        addCarToService(service, "ABCDEFG", "Ceva", "SUV");
    }


    assert(service->undo_size == initialUndoSize + initialUndoCapacity+1);
    assert(service->undo_capacity ==initialUndoCapacity*2);

    assert(service->undo_curent == initialUndoSize + initialUndoCapacity);

    destroyService(service);
}
void serviceTests() {
    test_initService();
    test_addCarToService();
    test_getAllCarsFromService();
    test_updateCarService();
    test_getSizeService();
    test_rentService();
    test_returnService();
    test_filterCategory();
    test_filterModel();
    test_filterRented();
    test_sortCarsByModel();
    test_sortCarsByCategory();
    test_undoService();
    test_saveUndoState();
    test_saveUndoState_resize();
    // test_sortCarsByModel2();
    // test_sortCarsByCategory2();
    printf("service tests passed\n");
}