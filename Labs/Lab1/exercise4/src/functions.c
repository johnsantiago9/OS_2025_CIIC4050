#include "functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Randomly converts characters in the input string to uppercase.
 *
 * This function prompts the user to enter a string, then randomly converts
 * characters in the input string to uppercase and stores the result in the
 * `mod` array.
 *
 * @param base The original input string.
 * @param mod The modified string with random uppercase characters.
 */
void UpperRand(char* base, char* mod) {
  printf("Enter a string: ");
  fgets(base, 100, stdin);

  for (int i = 0; base[i] != '\0'; i++) {
    if (rand() % 2 == 0) {
      mod[i] = toupper(base[i]);
    } else {
      mod[i] = base[i];
    }
  }
}

/**
 * @brief Prints the original and modified strings.
 *
 * This function prints the original input string and the modified string
 * with random uppercase characters.
 *
 * @param base The original input string.
 * @param mod The modified string with random uppercase characters.
 */
void PrintArrays(char* base, char* mod) {
  printf("Original array: %s", base);
  printf("Modified array: %s", mod);
}
