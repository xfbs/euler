#include <stddef.h>
#include <stdint.h>
#pragma once

typedef struct {
  uint32_t *data;
  size_t cap;
  size_t len;
} vec32_t;

vec32_t vec32_new(size_t len, uint32_t fill);
vec32_t *vec32_alloc(size_t len, uint32_t fill);
uint32_t vec32_get(vec32_t *v, size_t pos);
void vec32_set(vec32_t *v, size_t pos, uint32_t data);
size_t vec32_push(vec32_t *v, uint32_t data);
size_t vec32_len(vec32_t *v);
void vec32_free(vec32_t *v);
void vec32_clear(vec32_t *v);
size_t vec32_index(vec32_t *v, uint32_t data);
uint64_t vec32_sum(vec32_t *v);
