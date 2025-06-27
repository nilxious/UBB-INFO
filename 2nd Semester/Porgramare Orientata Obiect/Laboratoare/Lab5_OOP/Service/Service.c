#include "Service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initService(Service** s) {
    *s = (Service*)malloc(sizeof(Service));
    initRepository(&((*s)->repo));

    (*s)->undo_capacity = 5;
    (*s)->undo_size = 0;
    (*s)->undo_curent = -1;
    (*s)->undo_list = (Repository**)malloc((*s)->undo_capacity * sizeof(Repository*));

    add_default_cars(*s);
}

void destroyService(Service* s) {
    for (int i = 0; i <= s->undo_curent; i++) {
        destroyRepository(s->undo_list[i]);
    }
    free(s->undo_list);


    destroyRepository(s->repo);


    free(s);
}

int addCarToService(Service* service, char* id, char* model, char* category) {

    if (validateId(id) == 0) {
        return 1;
    }
    saveUndoState(service);
    Category c = getCategoryFromString(category);
    if (c == -2) {
        return 2;
    }
    Car car = createCar(id, model, c);
    return addCar(service->repo, car);
}

Car* getAllCarsFromService(Service* service) {
    return getAllCars(service->repo);
}
int updateCarService(Service* service, char* id, char* model, char* category) {
    saveUndoState(service);
    Category c = getCategoryFromString(category);
    if (c == -2) {
        return 2;
    }
    Car car = createCar(id, model, c);
    return updateCar(service->repo, car);
}

int getSizeService(Service* service) {
    return getSize(service->repo);
}
int rentService(Service* s, char* id) {
    saveUndoState(s);
    return rent(s->repo,id);
}
int returnService(Service* s, char* id) {
    return returnCar(s->repo,id);
}

Car* filterCategory(Service* s, char* category, int* count) {
    Car* filteredCars = malloc(sizeof(Car) * getSizeService(s));
    *count = 0;
    Category filterCategory = getCategoryFromString(category);
    for (int i = 0; i < getSizeService(s); i++) {
        if (getAllCarsFromService(s)[i].category == filterCategory) {
            filteredCars[*count] = getAllCarsFromService(s)[i];
            (*count)++;
        }
    }
    return filteredCars;
}

Car* filterModel(Service* s, char* model, int* count) {
    Car* filteredCars = malloc(sizeof(Car) * getSizeService(s));
    *count = 0;
    for (int i = 0; i < getSizeService(s); i++) {
        if (strcmp(getAllCarsFromService(s)[i].model, model) == 0) {
            filteredCars[(*count)++] = getAllCarsFromService(s)[i];
        }
    }
    return filteredCars;
}
Car* filterRented(Service* s, bool rented, int* count) {
    Car* filteredCars = malloc(sizeof(Car) * getSizeService(s));
    *count = 0;
    for (int i = 0; i < getSizeService(s); i++) {
        if (getAllCarsFromService(s)[i].rented == rented) {
            filteredCars[(*count)++] = getAllCarsFromService(s)[i];
        }
    }
    return filteredCars;
}
/*
Car* sortCarsByModel(Service* s, int ascending) {
    int size = getSizeService(s);
    Car* sortedCars = malloc(sizeof(Car) * size);
    memcpy(sortedCars, getAllCarsFromService(s), size * sizeof(Car));
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int cmpResult = strcmp(sortedCars[j].model, sortedCars[j + 1].model);
            if ((ascending && cmpResult > 0) || (!ascending && cmpResult < 0)) {
                Car temp = sortedCars[j];
                sortedCars[j] = sortedCars[j + 1];
                sortedCars[j + 1] = temp;
            }
        }
    }
    return sortedCars;
}

Car* sortCarsByCategory(Service* s, int ascending) {
    int size = getSizeService(s);
    Car* sortedCars = malloc(sizeof(Car) * size);
    memcpy(sortedCars, getAllCarsFromService(s), size * sizeof(Car));
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && sortedCars[j].category > sortedCars[j + 1].category) ||(!ascending && sortedCars[j].category < sortedCars[j + 1].category)) {
                Car temp = sortedCars[j];
                sortedCars[j] = sortedCars[j + 1];
                sortedCars[j + 1] = temp;
                }
        }
    }
    return sortedCars;
}*/
//FUNCTIA DATA PRIN VALOARE, NU REFERINTA
//functie de bubble sort indirect iterativ
Car* sortCars(Service* s, int (*cmp)(const Car*, const Car*), int ascending) {
    int size = getSizeService(s);
    Car* sortedCars = malloc(sizeof(Car) * size);
    memcpy(sortedCars, getAllCarsFromService(s), size * sizeof(Car));
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (cmp(&sortedCars[j], &sortedCars[j + 1]) > 0) {
                Car temp = sortedCars[j];
                sortedCars[j] = sortedCars[j + 1];
                sortedCars[j + 1] = temp;
            }
        }
    }
    if (!ascending) {
        for (int i = 0; i < size / 2; i++) {
            Car temp = sortedCars[i];
            sortedCars[i] = sortedCars[size - 1 - i];
            sortedCars[size - 1 - i] = temp;
        }
    }

    return sortedCars;
}

//Selection sort
Car* sortCars3(Service* s, int (*cmp)(const Car*, const Car*), int ascending) {
    int size = getSizeService(s);
    Car* sortedCars = malloc(sizeof(Car) * size);
    memcpy(sortedCars, getAllCarsFromService(s), size * sizeof(Car));

    for (int i = 0; i < size - 1; i++) {
        int bestIndex = i;
        for (int j = i + 1; j < size; j++) {
            if ((ascending && cmp(&sortedCars[j], &sortedCars[bestIndex]) < 0) ||
                (!ascending && cmp(&sortedCars[j], &sortedCars[bestIndex]) > 0)) {
                bestIndex = j;
                }
        }
        if (bestIndex != i) {
            Car temp = sortedCars[i];
            sortedCars[i] = sortedCars[bestIndex];
            sortedCars[bestIndex] = temp;
        }
    }

    return sortedCars;
}


int compareByModel(const Car* a, const Car* b) {
    return strcmp(a->model, b->model);
}

int compareByCategory(const Car* a, const Car* b) {
    //return (a->category > b->category) - (a->category < b->category);
    return (int)b->category - (int)a->category;
}

void add_default_cars(Service* service) {
    Car car1 = createCar("SV24SIZ", "Fiat", SUV);
    Car car2 = createCar("SV25SIZ", "BMW", SPORT);
    Car car3 = createCar("SV26SIZ", "Toyota", SEDAN);
    Car car4 = createCar("SV27SIZ", "Honda", HATCHBACK);
    Car car5 = createCar("SV28SIZ", "Mercedes", SUV);
    Car car6 = createCar("SV29SIZ", "Ford", MINI);
    Car car7 = createCar("SV30SIZ", "Audi", SPORT);
    Car car8 = createCar("SV31SIZ", "Renault", SEDAN);
    Car car9 = createCar("SV32SIZ", "Volkswagen", HATCHBACK);
    Car car10 = createCar("SV33SIZ", "Peugeot", SUV);
    Car car11 = createCar("SV34SIZ", "Nissan", MINI);
    Car car12 = createCar("SV35SIZ", "Mazda", SPORT);
    Car car13 = createCar("SV36SIZ", "Opel", SEDAN);
    Car car14 = createCar("SV37SIZ", "Chevrolet", HATCHBACK);
    Car car15 = createCar("SV38SIZ", "Fiat", SUV);
    Car car16 = createCar("SV39SIZ", "Bentley", HATCHBACK);
    addCar(service->repo, car1);
    addCar(service->repo, car2);
    addCar(service->repo, car3);
    addCar(service->repo, car4);
    addCar(service->repo, car5);
    addCar(service->repo, car6);
    addCar(service->repo, car7);
    addCar(service->repo, car8);
    addCar(service->repo, car9);
    addCar(service->repo, car10);
    addCar(service->repo, car11);
    addCar(service->repo, car12);
    addCar(service->repo, car13);
    addCar(service->repo, car14);
    addCar(service->repo, car15);
    addCar(service->repo, car16);
}

void saveUndoState(Service* service) {
    if (service->undo_size >= service->undo_capacity) {
        service->undo_capacity *= 2;
        service->undo_list = realloc(service->undo_list, service->undo_capacity * sizeof(Repository*));
    }

    service->undo_list[++(service->undo_curent)] = copyRepository(service->repo);
    service->undo_size = service->undo_curent + 1;
}

int undoService(Service* service) {
    if (service->undo_curent < 0) {
        return 0;
    }

    destroyRepository(service->repo);

    service->repo = copyRepository(service->undo_list[service->undo_curent]);

    destroyRepository(service->undo_list[service->undo_curent]);
    service->undo_curent--;
    return 1;
}