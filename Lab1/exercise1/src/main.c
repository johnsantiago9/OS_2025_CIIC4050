#include <math.h>
#include <stdio.h>
#include "functions.h"

int main() {
  int lower_limit, upper_limit;

  // Prompt user for the lower and upper limits
  printf("Enter the lower limit: ");
  scanf("%d", &lower_limit);

  printf("Enter the upper limit: ");
  scanf("%d", &upper_limit);

  // Call the CosineSeries function
  int result = CosineSeries(lower_limit, upper_limit);

  // Output the result
  if (result == 1) {

    printf("The sum of the cosine series is positive or zero.\n");
  } else {

    printf("The sum of the cosine series is negative.\n");
  }

  return 0;
}
