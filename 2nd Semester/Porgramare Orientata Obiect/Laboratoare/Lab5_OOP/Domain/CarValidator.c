#include "CarValidator.h"
#include <ctype.h>
#include <string.h>

int validateId(char* id) {
    if (strlen(id) != 7) {
        return 0;
    }
    if (!isupper(id[0]) || !isupper(id[1])) {
        return 0;
    }
    if (!isdigit(id[2]) || !isdigit(id[3])){
        return 0;
    }
    if (!isupper(id[4]) || !isupper(id[5]) || !isupper(id[6])) {
        return 0;
    }
    return 1;
}

Category getCategoryFromString(char* str) {
    if (strcmp(str, "MINI") == 0) {
        return MINI;
    }
    if (strcmp(str, "SPORT") == 0) {
        return SPORT;
    }
    if (strcmp(str, "SUV") == 0) {
        return SUV;
    }
    if (strcmp(str, "SEDAN") == 0) {
        return SEDAN;
    }
    if (strcmp(str, "HATCHBACK") == 0) {
        return HATCHBACK;
    }
    return UNKNOWN;
}