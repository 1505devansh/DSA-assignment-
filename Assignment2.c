#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A function to check if a string is palindrome
int isPalindrome(char *str)
{
    // Pointers pointing to the beginning and the end of the string
    char *start = str;
    char *end = str + strlen(str) - 1;

    // While there are characters to compare
    while (start < end)
    {
        // If characters are different, then return false
        if (*start != *end)
            return 0;

        // Increment first pointer and decrement the other
        start++;
        end--;
    }

    // Return true if the string is palindrome
    return 1;
}

// A function to swap two characters
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// A recursive function to generate all possible palindromes from a given string
void generatePalindromes(char *str, int start, int end, int *count)
{
    // Base case: if start index is equal or greater than end index
    if (start >= end)
    {
        // Check if the current permutation is palindrome
        if (isPalindrome(str))
        {
            // Increment the count of palindromes
            (*count)++;

            // Print the palindrome string
            printf("%s\n", str);
        }
        return;
    }

    // Loop through all characters from start to end index
    int i;
    for (i = start; i <= end; i++)
    {
        // Swap the current character with the start character
        swap(str + start, str + i);

        // Recursively generate palindromes for the remaining substring
        generatePalindromes(str, start + 1, end, count);

        // Backtrack and restore the original string
        swap(str + start, str + i);
    }
}

// A function to generate a random alphanumeric palindrome string of a given length
char *generateRandomPalindrome(int length)
{
    // Allocate memory for the string
    char *str = (char *)malloc((length + 1) * sizeof(char));

    // Define the possible characters in an alphanumeric string
    char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // Initialize a random seed
    srand(time(NULL));

    // Loop through half of the length
    int i;
    for (i = 0; i < length / 2; i++)
    {
        // Pick a random character from the array of chars
        int index = rand() % strlen(chars);

        // Assign the character to both ends of the string symmetrically
        str[i] = chars[index];
        str[length - i - 1] = chars[index];
    }

    // If the length is odd, assign a random character to the middle of the string
    if (length % 2 == 1)
    {
        int index = rand() % strlen(chars);
        str[length / 2] = chars[index];
    }

    // Terminate the string with a null character
    str[length] = '\0';

    // Return the string
    return str;
}

// The main function
int main()
{
    // Generate a random length between 5 to 11
    int length = rand() % 7 + 5;

    // Generate a random alphanumeric palindrome string of that length
    char *str = generateRandomPalindrome(length);

    // Initialize a count variable to store the number of palindromes
    int count = 0;

    // Print a beautiful message with the randomly generated palindrome string
    printf("The Randomly Generated Alphanumeric Palindrome String is %s\n", str);

    // Generate and print all possible palindromes from that string and update the count variable
    printf("The other Palindrome Strings that can be generated from this String are:\n");
    generatePalindromes(str, 0, length - 1, &count);

    // Print another beautiful message with the total number of palindromes (including the original one)
    printf("Total %d Palindrome Strings can be generated from this String\n", count);

    // Free the memory allocated for the string
    free(str);

    return 0;
}
