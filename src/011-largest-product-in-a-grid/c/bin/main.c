#include "solve.h"
#include <euler/vec.h>
#include <euler/vec8.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "no datafile specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");
  vecp_t grid = vecp_new(0, NULL);
  vec_push(&grid, (void *)vec8_alloc(0, 0));

  while (true) {
    int peek = ' ';
    unsigned int num = 0;

    while (peek == ' ' && 1 == fscanf(data_file, "%u", &num)) {
      vec8_push(vec_get(&grid, vec_len(&grid) - 1), num);
      peek = fgetc(data_file);
    }

    if (feof(data_file))
      break;
    vec_push(&grid, (void *)vec8_alloc(0, 0));
  }

  printf("%llu\n", solve(&grid, 4));

  return 0;
}
