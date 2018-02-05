#include <euler/common.h>
#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

void show_help(const char *prog);

int main(int argc, char *argv[])
{
  if(argc <= 1 || atoi(argv[1]) < 0) {
    show_help(argv[0]);
    return 1;
  }

  size_t problem = atoi(argv[1]);

  const char *res = solve[problem].func(NULL);

  // keep function pointers and pointers to help text together in an array?

  printf("%s\n", res);

  return 0;
}

void show_help(const char *prog) {
  fprintf(stderr, "Usage: %s NUM [OPTIONS]\n", prog);
}
