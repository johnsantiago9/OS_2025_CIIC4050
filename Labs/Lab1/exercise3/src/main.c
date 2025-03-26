#include <stdio.h>
#include <time.h>
#include "functions.h"

int main() {
  long seconds[3];
  Date dates[3];
  const char* month_name[] = {"January",   "February", "March",    "April",
                              "May",       "June",     "July",     "August",
                              "September", "October",  "November", "December"};

  for (int i = 0; i < 3; i++) {
    printf("Enter the number of seconds since 1970 for input %d: ", i + 1);
    scanf("%ld", &seconds[i]);
    dates[i] = FillDate(seconds[i]);  // FillDate is defined in functions.c
  }

  for (int i = 0; i < 3; i++) {
    printf("The date for input %d is: %s %d, %d\n", i + 1,
           month_name[dates[i].month - 1], dates[i].day, dates[i].year);
  }

  return 0;
}