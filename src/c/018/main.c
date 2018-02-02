#include "solve.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "no data file specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");

  size_t buffer_len = 256;
  uint32_t *buffer = calloc(buffer_len, sizeof(uint32_t));

  size_t rows = 0;
  size_t elements = 0;

  do {
    size_t prev_elements = elements;
    for (size_t e = 0; e <= rows; e++) {
      // always make sure buffer is big enough
      if (elements == buffer_len) {
        buffer_len *= 2;
        buffer = realloc(buffer, buffer_len * sizeof(uint32_t));
      }

      // read next element, break out of loop if we get junk
      if (1 != fscanf(data_file, "%4d", &buffer[elements])) {
        break;
      }

      elements++;
    }

    // only if we got a complete row do we signal this, otherwise we stop
    // here because there is junk in the data.
    if ((elements - prev_elements) == (rows + 1)) {
      rows++;
    } else {
      break;
    }
  } while (!feof(data_file));

  triangle_t t = {buffer, rows};
  printf("%i\n", solve(&t));

  return 0;
}
