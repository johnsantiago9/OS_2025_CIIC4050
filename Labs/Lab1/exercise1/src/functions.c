#include "functions.h"

#include <math.h>
#include <stdio.h>

/**
 * @brief Computes the sum of the cosine of integers in a given range.
 *
 * This function calculates the sum of the cosine values of all integers
 * from `init_number` to `end_number` (inclusive). It returns 1 if the sum
 * is non-negative and -1 if the sum is negative.
 *
 * @param init_number The starting integer of the range.
 * @param end_number The ending integer of the range.
 * @return int Returns 1 if the sum is non-negative, otherwise returns -1.
 */
int CosineSeries(int init_number, int end_number) {
  double sum = 0;
  for (int i = init_number; i <= end_number; i++) {
    sum += cos(i);
  }
  return (sum >= 0) ? 1 : -1;
}
