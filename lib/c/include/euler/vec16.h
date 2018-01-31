#include <stddef.h>
#include <stdint.h>
#pragma once

typedef struct {
  uint16_t *data;
  size_t cap;
  size_t len;
} vec16_t;

//! creates a new `vec16_t`.
//!
//! @param len the length of the vec16
//! @param fill which values the vec16 should initially be filled with
//! @return a `vec16_t` with the given length and filled with the given values.
//!
//! # Examples
//!
//! ```c
//! // creates an empty vec16
//! vec16_t vec = vec16_new(0, 0);
//! ```
vec16_t vec16_new(size_t len, uint16_t fill);

vec16_t *vec16_alloc(size_t len, uint16_t fill);
uint16_t vec16_get(const vec16_t *v, size_t pos);
uint16_t vec16_set(vec16_t *v, size_t pos, uint16_t data);
size_t vec16_push(vec16_t *v, uint16_t data);
size_t vec16_len(const vec16_t *v);
void vec16_free(vec16_t *v);
void vec16_clear(vec16_t *v);
size_t vec16_index(const vec16_t *v, uint16_t data);
uint64_t vec16_sum(const vec16_t *v);
