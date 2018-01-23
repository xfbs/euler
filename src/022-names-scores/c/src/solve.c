#include "solve.h"
#include <stdio.h>

static int alphabetical(const void *_a, const void *_b) {
  const char *a = *(const char **)_a;
  const char *b = *(const char **)_b;
  size_t i = 0;
  while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i])
    i++;
  if (a[i] == b[i])
    return 0;
  if (a[i] < b[i])
    return -1;
  return 1;
}

uint64_t weight(const char *str) {
  uint64_t w = 0;
  for (size_t i = 0; str[i]; i++) {
    w += str[i] - 'A' + 1;
  }

  return w;
}

uint64_t solve(vec_t *v) {
  vec_sort(v, alphabetical);

  uint64_t sum = 0;
  for (size_t i = 0; i < vec_len(v); i++) {
    sum += (i + 1) * weight(vec_get(v, i));
  }

  return sum;
}
