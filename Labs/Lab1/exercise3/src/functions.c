#include "functions.h"
#include <time.h>

/**
 * @brief Converts seconds since 1970 to a Date structure.
 *
 * This function converts the given number of seconds since 1970 (Unix epoch) to
 * a Date structure containing the day, month, and year.
 *
 * @param second The number of seconds since 1970.
 * @return Date A structure containing the day, month, and year.
 */
Date FillDate(long second) {
  Date result;
  time_t t = (time_t)second;
  struct tm* tm_info = localtime(&t);

  result.day = tm_info->tm_mday;
  result.month = tm_info->tm_mon + 1;
  result.year = tm_info->tm_year + 1900;

  return result;
}