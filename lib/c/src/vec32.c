#include "euler/vec32.h"
#include <stdlib.h>

vec32_t vec32_new(size_t len, uint32_t fill) {
  vec32_t v = {.data = NULL, .cap = 256, .len = len};

  while (v.cap < len)
    v.cap *= 2;
  v.data = calloc(v.cap, sizeof(uint32_t));
  for (size_t i = 0; i < len; i++)
    v.data[i] = fill;

  return v;
}

vec32_t *vec32_alloc(size_t len, uint32_t fill) {
  vec32_t *v = malloc(sizeof(vec32_t));
  *v = vec32_new(len, fill);
  return v;
}

uint32_t vec32_get(vec32_t *v, size_t pos) { return v->data[pos]; }

void vec32_set(vec32_t *v, size_t pos, uint32_t data) { v->data[pos] = data; }

size_t vec32_push(vec32_t *v, uint32_t data) {
  if (v->len == v->cap) {
    v->cap *= 2;
    v->data = realloc(v->data, v->cap * sizeof(uint32_t));
  }

  v->data[v->len] = data;
  return v->len++;
}

size_t vec32_len(vec32_t *v) { return v->len; }

void vec32_free(vec32_t *v) {
  free(v->data);
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

void vec32_clear(vec32_t *v) { v->len = 0; }

size_t vec32_index(vec32_t *v, uint32_t data) {
  for (size_t pos = 0; pos < vec32_len(v); pos++) {
    if (vec32_get(v, pos) == data) {
      return pos;
    }
  }

  return SIZE_MAX;
}

uint64_t vec32_sum(vec32_t *v) {
  uint64_t sum = 0;

  for (size_t pos = 0; pos < vec32_len(v); pos++) {
    sum += vec32_get(v, pos);
  }

  return sum;
}
