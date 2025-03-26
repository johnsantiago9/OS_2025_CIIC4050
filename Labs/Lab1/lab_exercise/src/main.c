#include <stdio.h>

#include "../include/functions.h"

int main() {
  void* array;
  int type;

  printf("Enter the type of the array (1 - char, 2 - int, 3 - float): ");
  scanf("%d", &type);

  PrintArray(&array, type);

  return 0;
}