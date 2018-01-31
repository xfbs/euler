#include <stddef.h>
#include <stdint.h>
#pragma once

typedef struct {
  uint8_t *data;
  size_t cap;
  size_t len;
} vec8_t;

vec8_t vec8_new(size_t len, uint8_t fill);
vec8_t *vec8_alloc(size_t len, uint8_t fill);
uint8_t vec8_get(vec8_t *v, size_t pos);
void vec8_set(vec8_t *v, size_t pos, uint8_t data);
size_t vec8_push(vec8_t *v, uint8_t data);
size_t vec8_len(vec8_t *v);
void vec8_free(vec8_t *v);
