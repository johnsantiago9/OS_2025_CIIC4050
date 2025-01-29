#include "functions.h"
#include <time.h>


void FillDate(long second, int* day, int* month, int* year){
    time_t t = second;
    struct tm* time = localtime(&t);
    *day = time->tm_mday + 1;
    *month = time->tm_mon + 1;
    *year = time->tm_year + 1900;
}
