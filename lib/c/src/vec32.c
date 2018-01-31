#include "euler/vec32.h"
#include <stdlib.h>
#define CAPSIZE 256

uint32_t vec32_get(const vec32_t *v, size_t pos) { return v->data[pos]; }

uint32_t vec32_set(vec32_t *v, size_t pos, uint32_t data) {
  uint32_t prev = v->data[pos];
  v->data[pos] = data;
  return prev;
}

size_t vec32_len(const vec32_t *v) { return v->len; }

void vec32_clear(vec32_t *v) { v->len = 0; }

vec32_t vec32_new(size_t len, uint32_t fill) {
  vec32_t v = {.data = NULL, .cap = CAPSIZE, .len = len};

  // make sure capacity is bigger than initial length
  while (v.cap < len) {
    v.cap *= 2;
  }

  // allocate data of given capacity, calloc ensures that the data is
  // zero-initialized.
  v.data = calloc(v.cap, sizeof(uint32_t));

  // we don't need to initialize the array if it should be filled with zeroes.
  if (fill != 0) {
    for (size_t i = 0; i < len; i++) {
      v.data[i] = fill;
    }
  }

  return v;
}

vec32_t *vec32_alloc(size_t len, uint32_t fill) {
  vec32_t *v = malloc(sizeof(vec32_t));
  *v = vec32_new(len, fill);
  return v;
}

void vec32_reserve(vec32_t *v, size_t size) {
  if ((v->cap - v->len) < size) {
    while ((v->cap - v->len) < size) {
      v->cap *= 2;
    }

    v->data = realloc(v->data, v->cap * sizeof(uint32_t));
  }
}

size_t vec32_push(vec32_t *v, uint32_t data) {
  // grow the length of the vector
  vec32_reserve(v, 1);
  v->len++;

  // set the data of the new element
  vec32_set(v, vec32_len(v) - 1, data);
  return vec32_len(v);
}

void vec32_free(vec32_t *v) {
  // release data
  free(v->data);

  // reset everything to trigger segfault if vec is used by accident
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

size_t vec32_index(const vec32_t *v, uint32_t data) {
  for (size_t pos = 0; pos < vec32_len(v); pos++) {
    if (vec32_get(v, pos) == data) {
      return pos;
    }
  }

  return SIZE_MAX;
}

uint64_t vec32_sum(const vec32_t *v) {
  uint64_t sum = 0;

  for (size_t pos = 0; pos < vec32_len(v); pos++) {
    sum += vec32_get(v, pos);
  }

  return sum;
}
