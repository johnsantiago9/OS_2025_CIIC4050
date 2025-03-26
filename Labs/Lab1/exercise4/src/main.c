#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
  srand(time(NULL));

  char base[100];
  char mod[100];

  UpperRand(base, mod);
  PrintArrays(base, mod);

  return 0;
}