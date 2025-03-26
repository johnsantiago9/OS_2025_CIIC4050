#include <stdio.h>
#include <time.h>
#include "functions.h"

int main() {
  int day, month, year;
  long second;
  const char* month_name[] = {"January",   "February", "March",    "April",
                              "May",       "June",     "July",     "August",
                              "September", "October",  "November", "December"};
  printf("Enter the number of seconds since 1970: ");
  scanf("%ld", &second);

  FillDate(second, &day, &month, &year);  // FillDate is defined in functions.c

  printf("The date is: %s %d, %d\n", month_name[month - 1], day, year);

  return 0;
}