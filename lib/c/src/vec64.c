#include "euler/vec64.h"
#include <stdlib.h>
#define CAPSIZE 256

uint64_t vec64_get(const vec64_t *v, size_t pos) { return v->data[pos]; }

uint64_t vec64_set(vec64_t *v, size_t pos, uint64_t data) {
  uint64_t prev = v->data[pos];
  v->data[pos] = data;
  return prev;
}

size_t vec64_len(const vec64_t *v) { return v->len; }

void vec64_clear(vec64_t *v) { v->len = 0; }

vec64_t vec64_new(size_t len, uint64_t fill) {
  vec64_t v = {.data = NULL, .cap = CAPSIZE, .len = len};

  // make sure capacity is bigger than initial length
  while (v.cap < len) {
    v.cap *= 2;
  }

  // allocate data of given capacity, calloc ensures that the data is
  // zero-initialized.
  v.data = calloc(v.cap, sizeof(uint64_t));

  // we don't need to initialize the array if it should be filled with zeroes.
  if (fill != 0) {
    for (size_t i = 0; i < len; i++) {
      v.data[i] = fill;
    }
  }

  return v;
}

vec64_t *vec64_alloc(size_t len, uint64_t fill) {
  vec64_t *v = malloc(sizeof(vec64_t));
  *v = vec64_new(len, fill);
  return v;
}

void vec64_reserve(vec64_t *v, size_t size) {
  if ((v->cap - v->len) < size) {
    while ((v->cap - v->len) < size) {
      v->cap *= 2;
    }

    v->data = realloc(v->data, v->cap * sizeof(uint64_t));
  }
}

size_t vec64_push(vec64_t *v, uint64_t data) {
  // grow the length of the vector
  vec64_reserve(v, 1);
  v->len++;

  // set the data of the new element
  vec64_set(v, vec64_len(v) - 1, data);
  return vec64_len(v);
}

void vec64_free(vec64_t *v) {
  // release data
  free(v->data);

  // reset everything to trigger segfault if vec is used by accident
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

size_t vec64_index(const vec64_t *v, uint64_t data) {
  for (size_t pos = 0; pos < vec64_len(v); pos++) {
    if (vec64_get(v, pos) == data) {
      return pos;
    }
  }

  return SIZE_MAX;
}

uint64_t vec64_sum(const vec64_t *v) {
  uint64_t sum = 0;

  for (size_t pos = 0; pos < vec64_len(v); pos++) {
    sum += vec64_get(v, pos);
  }

  return sum;
}
