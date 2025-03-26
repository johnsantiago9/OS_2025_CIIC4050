#include "functions.h"
#include <time.h>

/**
 * @brief Fills the date components (day, month, year) from a given number of
 * seconds since 1970.
 *
 * This function converts the given number of seconds since 1970 (Unix epoch) to
 * a date and fills the provided day, month, and year pointers with the
 * corresponding values.
 *
 * @param second The number of seconds since 1970.
 * @param day Pointer to an integer where the day will be stored.
 * @param month Pointer to an integer where the month will be stored.
 * @param year Pointer to an integer where the year will be stored.
 */
void FillDate(long second, int* day, int* month, int* year) {
  time_t t = second;
  struct tm* time = localtime(&t);
  *day = time->tm_mday + 1;
  *month = time->tm_mon + 1;
  *year = time->tm_year + 1900;
}
