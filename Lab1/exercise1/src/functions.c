#include "functions.h"
#include <stdio.h>
#include <math.h>

int CosineSeries(int init_number, int end_number) {
    double sum = 0;
    for (int i = init_number; i <= end_number; i++) {
        sum += cos(i);
    }
    return (sum >= 0) ? 1 : -1;
}

