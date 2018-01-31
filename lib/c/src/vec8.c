#include "euler/vec8.h"
#include <stdlib.h>
#define CAPSIZE 256

uint8_t vec8_get(const vec8_t *v, size_t pos) { return v->data[pos]; }

uint8_t vec8_set(vec8_t *v, size_t pos, uint8_t data) {
  uint8_t prev = v->data[pos];
  v->data[pos] = data;
  return prev;
}

size_t vec8_len(const vec8_t *v) { return v->len; }

void vec8_clear(vec8_t *v) { v->len = 0; }

vec8_t vec8_new(size_t len, uint8_t fill) {
  vec8_t v = {.data = NULL, .cap = CAPSIZE, .len = len};

  // make sure capacity is bigger than initial length
  while (v.cap < len) {
    v.cap *= 2;
  }

  // allocate data of given capacity, calloc ensures that the data is
  // zero-initialized.
  v.data = calloc(v.cap, sizeof(uint8_t));

  // we don't need to initialize the array if it should be filled with zeroes.
  if(fill != 0) {
    for(size_t i = 0; i < len; i++) {
      v.data[i] = fill;
    }
  }

  return v;
}

vec8_t *vec8_alloc(size_t len, uint8_t fill) {
  vec8_t *v = malloc(sizeof(vec8_t));
  *v = vec8_new(len, fill);
  return v;
}

void vec8_reserve(vec8_t *v, size_t size) {
  if((v->cap - v->len) < size) {
    while((v->cap - v->len) < size) {
      v->cap *= 2;
    }

    v->data = realloc(v->data, v->cap * sizeof(uint8_t));
  }
}

size_t vec8_push(vec8_t *v, uint8_t data) {
  // grow the length of the vector
  vec8_reserve(v, 1);
  v->len++;

  // set the data of the new element
  vec8_set(v, vec8_len(v) - 1, data);
  return vec8_len(v);
}

void vec8_free(vec8_t *v) {
  // release data
  free(v->data);

  // reset everything to trigger segfault if vec is used by accident
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

size_t vec8_index(const vec8_t *v, uint8_t data) {
  for (size_t pos = 0; pos < vec8_len(v); pos++) {
    if (vec8_get(v, pos) == data) {
      return pos;
    }
  }

  return SIZE_MAX;
}

uint64_t vec8_sum(const vec8_t *v) {
  uint64_t sum = 0;

  for (size_t pos = 0; pos < vec8_len(v); pos++) {
    sum += vec8_get(v, pos);
  }

  return sum;
}
