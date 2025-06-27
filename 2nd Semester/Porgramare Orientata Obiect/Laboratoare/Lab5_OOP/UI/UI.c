#include <stdio.h>
#include "UI.h"
#include <stdlib.h>
#include <string.h>

void initUI(UI** ui) {
    *ui = (UI*)malloc(sizeof(UI));
    initService(&((*ui)->service));
}
void destroyUI(UI* ui) {
    destroyService((ui->service));
    free(ui);
}
void menu() {
    printf("\nCar Management System\n");
    printf("1. Add a car\n");
    printf("2. Get all cars\n");
    printf("3. Update car\n");
    printf("4. Rent a car\n");
    printf("5. Return a car\n");
    printf("6.Filter by model/category\n");
    printf("7.Sort by model/category\n");
    printf("8.Undo multiplu\n");
    printf("9. Exit\n");
}

void addCarUI(UI* ui) {
    char id[STRING_LENGTH], model[STRING_LENGTH], category[STRING_LENGTH];
    printf("Enter car ID: ");
    scanf("%s", id);
    getchar();
    printf("Enter car model: ");
    scanf("%s", model);
    getchar();
    printf("Enter category: ");
    scanf("%s", category);
    getchar();
    int result = addCarToService(ui->service, id, model, category);
    switch (result){
        case 1:
            printf("Id not valid (CCNNCCC)\n");
            break;
        case 2:
            printf("Category must be one from: MINI, SPORT, SUV, SEDAN, HATCHBACK\n");
            break;
        case -1:
            printf("Error: Car with same Id already exists!\n");
        default:
            break;
    }
}

void showAll(UI* ui) {
    for (int i = 0; i < getSizeService(ui->service); i++) {
        toString(getAllCarsFromService(ui->service)[i]);
    }
}

void updateCarUI(UI* ui) {
    char id[STRING_LENGTH], model[STRING_LENGTH], category[STRING_LENGTH];
    printf("Enter car ID: ");
    scanf("%s", id);
    getchar();
    printf("Enter new car model: ");
    scanf("%s", model);
    getchar();
    printf("Enter new category: ");
    scanf("%s", category);
    getchar();
    int result = updateCarService(ui->service, id, model, category);
    switch (result) {
        case -1:
            printf("Error: Car with given Id doesn't exists (nothing to update)!\n");
            break;
        case 2:
            printf("Category must be one from: MINI, SPORT, SUV, SEDAN, HATCHBACK\n");
        default:
            break;

    }
}

void rentUI(UI* ui) {
    char id[STRING_LENGTH];
    printf("Enter car ID: ");
    scanf("%s", id);
    getchar();
    if (rentService(ui->service, id) == -1)
        printf("Already rented!");
    else
        printf("Masina cu id %s a fost inchiriata!",id);
}

void returnUI(UI* ui) {
    char id[STRING_LENGTH];
    printf("Enter car ID: ");
    scanf("%s", id);
    getchar();
    if (returnService(ui->service, id) == -1)
        printf("It was not rented");
}

void filterUI(UI* ui) {
    char option[10];
    printf("model/category/rented: ");
    scanf("%s", option);
    getchar();

    int count;
    if (strcmp(option, "category") == 0) {
        char category[STRING_LENGTH];
        printf("Enter category: ");
        scanf("%s", category);
        getchar();
        Car* filteredCars = filterCategory(ui->service, category, &count);
        for (int i = 0; i < count; i++) {
            toString(filteredCars[i]);
        }
        if (filteredCars != NULL) {
            free(filteredCars);
        }
    }
    else if (strcmp(option, "model") == 0) {
        char model[STRING_LENGTH];
        printf("Enter model: ");
        scanf("%s", model);
        getchar();
        Car* filteredCars = filterModel(ui->service, model, &count);
        for (int i = 0; i < count; i++) {
            toString(filteredCars[i]);
        }
        if (filteredCars != NULL) {
            free(filteredCars);
        }
    }
    else if (strcmp(option, "rented") == 0) {
        bool rented;
        printf("Enter rented (0 for available, 1 for rented): ");
        scanf("%d", &rented);
        getchar();  // Consuma caracterul de newline
        if (rented != 0 && rented != 1) {
            printf("Invalid input for rented\n");
            return;
        }
        Car* filteredCars = filterRented(ui->service, rented, &count);
        for (int i = 0; i < count; i++) {
            toString(filteredCars[i]);
        }
        if (filteredCars != NULL) {
            free(filteredCars);
        }
    }
    else {
        printf("Invalid option\n");
    }
}

void sortUI(UI* ui) {
    char option[10], order[15];
    printf("model/category: ");
    scanf("%s", option);
    getchar();
    printf("ascending/descending: ");
    scanf("%s", order);
    getchar();

    int ascending = (strcmp(order, "ascending") == 0);
    Car* sortedCars;
    if (strcmp(option, "model") == 0) {
        sortedCars = sortCars(ui->service, compareByModel, ascending);//sortCarsByModel(ui->service, ascending);
    } else if (strcmp(option, "category") == 0) {
        sortedCars = sortCars(ui->service, compareByCategory, ascending);//sortCarsByCategory(ui->service, ascending);
    }
    else
        return;
    for (int i = 0; i < getSizeService(ui->service); i++) {
        toString(sortedCars[i]);
    }
    if (sortedCars != NULL) {
        free(sortedCars);
    }
}

void undoUI(UI* ui) {
    if (undoService(ui->service)) {
        printf("Undo successful!\n");
    } else {
        printf("No previous state to undo!\n");
    }
}

void startUI(UI* ui) {
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice)!=1) {
            printf("Invalid choice\n");
            while (getchar()!='\n');
            continue;
        }
        while (getchar() != '\n');
        switch (choice) {
            case 1:
                addCarUI(ui);
            break;
            case 2:
                showAll(ui);
            break;
            case 3:
                updateCarUI(ui);
            break;
            case 4:
                rentUI(ui);
            break;
            case 5:
                returnUI(ui);
                break;
            case 6:
                filterUI(ui);
                break;
            case 7:
                sortUI(ui);
                break;
            case 8:
                undoUI(ui);
                break;
            case 9:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}