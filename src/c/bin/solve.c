#include <euler/common.h>
#include "001.h"
#include <stdio.h>
#include <stdlib.h>

void show_help(const char *prog);

int main(int argc, char *argv[])
{
  if(argc <= 1 || atoi(argv[1]) < 0) {
    show_help(argv[0]);
    return 1;
  }

  size_t problem = atoi(argv[1]);

  // TODO: parse additional options given
  const char *res = solve001(NULL);

  printf("%s\n", res);

  return 0;
}

void show_help(const char *prog) {
  fprintf(stderr, "Usage: %s NUM [OPTIONS]\n", prog);
}
