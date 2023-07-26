#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMaxDigit(int number) {
    int maxDigit = 0;
    while (number > 0) {
        int digit = number % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        number /= 10;
    }
    return maxDigit;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer with 10 digits and the last place digit is at least 5
    int randomInteger = 5000000000 + rand() % 5000000000;

    // Calculate the highest base of the integer
    int highestBase = getMaxDigit(randomInteger) + 1;

    // Print the random integer and its highest base
    printf("The random integer is: %d\n", randomInteger);
    printf("The Highest Base of the random integer is: %d\n", highestBase);

    return 0;
}
