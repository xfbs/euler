#include "solve.h"
#include <euler/vec.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "no datafile specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");
  vecp_t v = vecp_new(0, NULL);
  char *str;

  while (!feof(data_file)) {
    str = malloc(256);

    if (1 == fscanf(data_file, "%*[^A-Z]%255[A-Z]", str)) {
      vec_push(&v, str);
    } else {
      break;
    }
  }

  printf("%llu\n", solve(&v));
  vec_free(&v);

  return 0;
}
