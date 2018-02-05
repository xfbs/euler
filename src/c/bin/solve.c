#include <euler/common.h>
#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

void show_help(const char *prog);
void error(const char *mesg);

int main(int argc, char *argv[])
{
  if(argc <= 1 || atoi(argv[1]) < 0) {
    show_help(argv[0]);
    return 1;
  }

  size_t problem = atoi(argv[1]);
  if(problem >= solve_max || solve[problem].func == NULL) {
    error("the requested problem isn't implemented.");
    return 1;
  }

  printf("%s\n", solve[problem].func(NULL));

  return 0;
}

void show_help(const char *prog) {
  fprintf(stderr, "Usage: %s NUM [OPTIONS]\n", prog);
}

void error(const char *mesg) {
  fprintf(stderr, "Error: %s\n", mesg);
}
