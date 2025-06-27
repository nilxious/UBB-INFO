#include <cstdio>

void printMenu();
void option1();
double binary_sqrt(double num, double precision);
void run();

int main() {
    run();
    printf("Program terminat.\n");
    return 0;
}

/**
 * Functie pentru rularea meniului si gestionarea optiunilor utilizatorului
 * @return: -
 */
void run() {
    int choice;
    do {
        printMenu();
        scanf_s("%d", &choice);

        if (choice == 1) {
            option1();
        }
    } while (choice != 0);
}

/**
 * Functie pentru afisarea meniului
 * @return: -
 */
void printMenu() {
    printf("\nMeniu:\n");
    printf("1. Calculeaza radacina patrata\n");
    printf("0. Iesire\n");
    printf("Alegeti o optiune: ");
}

/**
 * Functie care proceseaza optiunea 1: citeste datele si afiseaza rezultatul
 * @return: -
 */
void option1() {
    double num, precision;
    printf("Introduceti un numar pozitiv: ");
    scanf_s("%lf", &num);
    printf("Introduceti precizia dorita: ");
    scanf_s("%lf", &precision);

    if (num > 0 && precision > 0) {
        double result = binary_sqrt(num, precision);
        printf("Aproximarea radacinii patrate a lui %.6lf cu precizia %.6lf este: %.6lf\n", num, precision, result);
    } else {
        printf("Date invalide! Introduceti un numar pozitiv si o precizie mai mare ca 0.\n");
    }
}

/**
 * Functie pentru calcularea radacinii patrate a unui numar folosind metoda cautarii binare.
 *
 * @param num Numarul real pozitiv pentru care se doreste calculul radacinii patrate.
 * @param precision Precizia dorita pentru rezultat.
 * @return Aproximarea radacinii patrate a numarului dat.
 *
 * Preconditii: num > 0, precision > 0
 * Postconditii: Rezultatul este o aproximare a radacinii patrate a lui num, cu o eroare mai mica decat precision.
 */
double binary_sqrt(double num, double precision) {
    double low = 0, high = num, mid;
    while (high - low > precision) {
        mid = (low + high) / 2;
        if (mid * mid > num)
            high = mid;
        else
            low = mid;
    }
    return (low + high) / 2;
}

