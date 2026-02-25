#include <cstdio>
#include "temps.h"

int findMinimum(int ARRAY_SIZE) {
    /*
     * Finds minimal value in given array temperatures
     */
    int minimum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int current = temperatures[i];
        if (current < minimum && current != NO_VALUE) minimum = current;
    }
    return minimum;
}

void printStars(int n) {
    /*
     * Prints given amount of stars on line
     */
    for (int i = 0; i < n; i++) {
        printf("*");
    }
}

void printSpaces(int n) {
    /*
     * Prints given amount of spaces
     */
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printPositiveValue( int starCount, int spaceCount) {
    /*
     * Prints lines of positive values
     */
    printSpaces(spaceCount);
    printf("|");
    printStars(starCount);
    printf("\n");
}

void printNegativeValue(int starCount, int spaceCount) {
    /*
     * Prints lines of negavite values
     */
    printSpaces(spaceCount);
    printStars(starCount);
    printf("|");
    printf("\n");
}

void printZeroValue(int spaceCount) {
    /*
     * Prints lines of that is equal to zero
     */
    printSpaces(spaceCount);
    printf("|");
    printf("\n");
}

void printValue (int value, int minimum) {
    /*
     * Desides which temperature it is and prints given amount of stars on line
     */
    int spaceCount = 0;
    int starCount = 0;

    if (value < 0) {
        value = -value;
        spaceCount = -minimum - value;
        starCount = value;
        printNegativeValue(starCount, spaceCount);
    }
    else if (value == 0) {
        spaceCount = -minimum;
        printZeroValue(spaceCount);
    }
    else {
        spaceCount = -minimum;
        starCount = value;
        printPositiveValue(starCount, spaceCount);
    }
}

int main() {
    const int ARRAY_SIZE = sizeof(temperatures) / sizeof(temperatures[0]);

    int previousValue = 0;
    int minimum = findMinimum(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        int current = temperatures[i];
        if (current != NO_VALUE) {
            printValue(current, minimum);
            previousValue = current;
        }
        else {
            printValue(previousValue, minimum);
        }
    }
    return 0;
}