#include <euler/common.h>
#include <euler/map.h>
#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

typedef enum {
  SHOW_HELP,
  LIST_PROBLEMS,
  SHOW_PROBLEM_HELP,
  SOLVE_PROBLEM
} actions_t;

typedef struct {
  actions_t action;
  size_t problem;
  map_t *options;
} action_t;

void show_help(void);
void show_problem_help(size_t num);
void show_usage(const char *prog);
void error(const char *mesg);
void list_problems(void);
int solve_problem(size_t num, map_t *opts);
action_t parse_args(int argc, char *argv[]);
map_t *parse_opts(int argc, char *argv[]);
void parse_opt(map_t *hm, char *opt, char *val);

static const char *helpstr =
  "  --help  show this help text\n"
  "  --list  show all available problems\n";

int main(int argc, char *argv[])
{
  action_t action = parse_args(argc, argv);

  switch(action.action) {
    case SHOW_HELP:
      show_usage(argv[0]);
      show_help();
      break;
    case LIST_PROBLEMS:
      show_usage(argv[0]);
      list_problems();
      break;
    case SOLVE_PROBLEM:
      return solve_problem(action.problem, action.options);
      break;
  }

  return 0;
}

void show_usage(const char *prog) {
  fprintf(stderr, "Usage: %s NUM [OPTIONS]\n", prog);
}

void show_help(void) {
  fprintf(stderr, "%s", helpstr);
}

void error(const char *mesg) {
  fprintf(stderr, "Error: %s\n", mesg);
}

action_t parse_args(int argc, char *argv[]) {
  if(argc < 2) {
    return (action_t){.action = SHOW_HELP};
  }

  size_t num;
  int pos;
  if(1 == sscanf(argv[1], "%3zu%n", &num, &pos)) {
    if(argv[1][pos] == '\0') {
      return (action_t){
        .action = SOLVE_PROBLEM,
        .problem = num,
        .options = parse_opts(argc, argv)
      };
    }
  }

  if(0 == strcmp("--list", argv[1])) {
    return (action_t) {
      .action = LIST_PROBLEMS
    };
  }

  return (action_t){.action = SHOW_HELP};
}

map_t *parse_opts(int argc, char *argv[]) {
  if(argc <= 2) {
    return NULL;
  }

  map_t *hm = map_alloc();

  for(int cur = 2; cur < argc; cur++) {
    parse_opt(hm, argv[cur], NULL);
  }

  return hm;
}

void parse_opt(map_t *hm, char *opt, char *val) {
  if(opt[0] == '-' && opt[1] != '\0' && opt[2] == '\0') {
    if(!map_add(hm, &opt[1], val)) {
      fprintf(stderr, "Error: duplicate arguments provided for '%s'\n", opt);
    }
  } else if(opt[0] == '-' && opt[1] == '-' && opt[2] != '\0' && opt[3] != '\0') {
    if(!map_add(hm, &opt[2], val)) {
      fprintf(stderr, "Error: duplicate arguments provided for '%s'\n", opt);
    }
  } else {
    fprintf(stderr, "Error: unrecognized argument '%s'\n", opt);
  }
}

int solve_problem(size_t num, map_t *opts) {
  if(num >= solve_max || solve[num].func == NULL) {
    error("the requested problem isn't implemented.");
    return 1;
  }

  printf("%s\n", solve[num].func(opts));

  if(opts) {
    map_free(opts);
    free(opts);
  }

  return 0;
}

void show_problem_help(size_t num) {
}

void list_problems(void) {
  fprintf(stderr, "\nAvailable problems are:\n");
  for(size_t num = 0; num < solve_max; num++) {
    if(solve[num].func != NULL) {
      fprintf(stderr, "  %03u: %s\n", num, solve[num].name);
    }
  }
}

