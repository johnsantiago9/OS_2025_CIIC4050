#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
  int day;
  int month;
  int year;

} Date;

Date FillDate(long second);

#endif  // FUNCTIONS_H