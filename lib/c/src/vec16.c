#include "euler/vec16.h"
#include <stdlib.h>
#define CAPSIZE 256

uint16_t vec16_get(const vec16_t *v, size_t pos) { return v->data[pos]; }

uint16_t vec16_set(vec16_t *v, size_t pos, uint16_t data) {
  uint16_t prev = v->data[pos];
  v->data[pos] = data;
  return prev;
}

size_t vec16_len(const vec16_t *v) { return v->len; }

void vec16_clear(vec16_t *v) { v->len = 0; }

vec16_t vec16_new(size_t len, uint16_t fill) {
  vec16_t v = {.data = NULL, .cap = CAPSIZE, .len = len};

  // make sure capacity is bigger than initial length
  while (v.cap < len) {
    v.cap *= 2;
  }

  // allocate data of given capacity, calloc ensures that the data is
  // zero-initialized.
  v.data = calloc(v.cap, sizeof(uint16_t));

  // we don't need to initialize the array if it should be filled with zeroes.
  if (fill != 0) {
    for (size_t i = 0; i < len; i++) {
      v.data[i] = fill;
    }
  }

  return v;
}

vec16_t *vec16_alloc(size_t len, uint16_t fill) {
  vec16_t *v = malloc(sizeof(vec16_t));
  *v = vec16_new(len, fill);
  return v;
}

void vec16_reserve(vec16_t *v, size_t size) {
  if ((v->cap - v->len) < size) {
    while ((v->cap - v->len) < size) {
      v->cap *= 2;
    }

    v->data = realloc(v->data, v->cap * sizeof(uint16_t));
  }
}

size_t vec16_push(vec16_t *v, uint16_t data) {
  // grow the length of the vector
  vec16_reserve(v, 1);
  v->len++;

  // set the data of the new element
  vec16_set(v, vec16_len(v) - 1, data);
  return vec16_len(v);
}

void vec16_free(vec16_t *v) {
  // release data
  free(v->data);

  // reset everything to trigger segfault if vec is used by accident
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

size_t vec16_index(const vec16_t *v, uint16_t data) {
  for (size_t pos = 0; pos < vec16_len(v); pos++) {
    if (vec16_get(v, pos) == data) {
      return pos;
    }
  }

  return SIZE_MAX;
}

uint64_t vec16_sum(const vec16_t *v) {
  uint64_t sum = 0;

  for (size_t pos = 0; pos < vec16_len(v); pos++) {
    sum += vec16_get(v, pos);
  }

  return sum;
}
