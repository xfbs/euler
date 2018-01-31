#include "euler/vecp.h"
#include <stdlib.h>
#define CAPSIZE 256

void *vecp_get(const vecp_t *v, size_t pos) { return v->data[pos]; }

void *vecp_set(vecp_t *v, size_t pos, void *data) {
  void *prev = v->data[pos];
  v->data[pos] = data;
  return prev;
}

size_t vecp_len(const vecp_t *v) { return v->len; }

void vecp_clear(vecp_t *v) { v->len = 0; }

vecp_t vecp_new(size_t len, void *fill) {
  vecp_t v = {.data = NULL, .cap = CAPSIZE, .len = len};

  // make sure capacity is bigger than initial length
  while (v.cap < len) {
    v.cap *= 2;
  }

  // allocate data of given capacity, calloc ensures that the data is
  // zero-initialized.
  v.data = calloc(v.cap, sizeof(void *));

  // we don't need to initialize the array if it should be filled with zeroes.
  if (fill != NULL) {
    for (size_t i = 0; i < len; i++) {
      v.data[i] = fill;
    }
  }

  return v;
}

vecp_t *vecp_alloc(size_t len, void *fill) {
  vecp_t *v = malloc(sizeof(vecp_t));
  *v = vecp_new(len, fill);
  return v;
}

void vecp_reserve(vecp_t *v, size_t size) {
  if ((v->cap - v->len) < size) {
    while ((v->cap - v->len) < size) {
      v->cap *= 2;
    }

    v->data = realloc(v->data, v->cap * sizeof(void *));
  }
}

size_t vecp_push(vecp_t *v, void *data) {
  // grow the length of the vector
  vecp_reserve(v, 1);
  v->len++;

  // set the data of the new element
  vecp_set(v, vecp_len(v) - 1, data);
  return vecp_len(v);
}

void vecp_free(vecp_t *v) {
  // release data
  free(v->data);

  // reset everything to trigger segfault if vec is used by accident
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

size_t vecp_index(const vecp_t *v, void *data) {
  for (size_t pos = 0; pos < vecp_len(v); pos++) {
    if (vecp_get(v, pos) == data) {
      return pos;
    }
  }

  return SIZE_MAX;
}

void vecp_sort(vecp_t *v, int (*comp)(const void *, const void *)) {
  qsort(v->data, v->len, sizeof(void *), comp);
}
