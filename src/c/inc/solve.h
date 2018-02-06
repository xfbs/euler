#include <euler/common.h>
#include <euler/map.h>

typedef const char *solve_func(map_t *data);

struct solve_s {
  solve_func *func;
  const char *name;
  const char *help;
};

extern struct solve_s solve[];
size_t solve_max;
