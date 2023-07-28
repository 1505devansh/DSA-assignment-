#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculateHighestBase(long long int num) {
    int highest_base = 0;
    
    while (num > 0) {
        int digit = num % 10;
        if (digit > highest_base) {
            highest_base = digit;
        }
        num /= 10;
    }

    return highest_base + 1;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    
    printf("Generating 50 random integers with 10 digits...\n");
    int i;
    for (i = 0; i < 50; i++) {
        // Generate a random 10-digit integer with the last digit at least 5
        long long int random_num = 5000000000 + rand() % 5000000000;;

        // Calculate the highest base of the generated integer
        int highest_base = calculateHighestBase(random_num);

        printf("The Highest Base of %lld is %d.\n", random_num, highest_base);
    }

    return 0;
}

