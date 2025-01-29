#include <stdio.h>
#include <time.h>
#include "functions.h"



int main(){

    int day, month, year;
    long second;

    printf("Enter the number of seconds since 1970: ");
    scanf("%ld", &second);

    FillDate(second, &day, &month, &year);   // FillDate is defined in functions.c

    printf("The date is: %d/%d/%d\n", month, day, year);
    return 0;
}