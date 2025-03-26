#include "../include/functions.h"

#include <stdio.h>
#include <string.h>

/**
 * @brief Prints the elements of an array based on the specified type.
 *
 * This function prints the elements of an array. The type of the array is
 * specified by the `type` parameter:
 * - 1: char array
 * - 2: int array
 * - 3: float array
 *
 * @param array A pointer to the array to be printed.
 * @param type An integer specifying the type of the array (1 for char, 2 for
 * int, 3 for float).
 */
void PrintArray(void* array, int type) {
  // Convert void array into char array and put info inside array
  if (type == 1) {
    printf("Enter the elements of the array: ");
    char array[100];
    getchar();
    fgets((char*)array, 100, stdin);  // Assuming the buffer size is 100
    puts((char*)array);
  } else if (type == 2) {
    int* intArray = (int*)array;
    int i = 0;
    while (1) {
      printf(
          "Enter the elements of the array, to stop enter a negative number: ");
      int num;
      scanf("%d", &num);
      if (num < 0) {
        break;
      }
      intArray[i++] = num;
    }
    // Print the array
    printf("Array elements: ");
    for (int j = 0; j < i; j++) {
      printf("%d ", intArray[j]);
    }
    printf("\n");
  } else if (type == 3) {
    float* floatArray = (float*)array;
    int i = 0;
    while (1) {
      printf(
          "Enter the elements of the array, to stop enter a negative number: ");
      float num;
      scanf("%f", &num);
      if (num < 0) {
        break;
      }
      floatArray[i++] = num;
    }
    // Print the array
    printf("Array elements: ");
    for (int j = 0; j < i; j++) {
      printf("%.2f ", floatArray[j]);
    }
    printf("\n");
  } else {
    printf("Invalid type\n");
  }
}