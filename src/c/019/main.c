#include "solve.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  date_t start = {MONDAY, 1, JANUARY, 1900};

  // find 1st Jan 1901
  for (size_t i = 0; i < 12; i++) {
    start = next_month(start);
  }

  // i guessed the weekday here, but it shouldn't matter anyways.
  date_t end = {MONDAY, 31, DECEMBER, 2000};

  printf("%i\n", solve_019(start, end));

  return 0;
}
