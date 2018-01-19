#include <stdint.h>
#include <stddef.h>
#pragma once

typedef struct {
    uint16_t *data;
    size_t cap;
    size_t len;
} vec16_t;

vec16_t vec16_new(size_t len, uint16_t fill);
vec16_t *vec16_alloc(size_t len, uint16_t fill);
uint16_t vec16_get(vec16_t *v, size_t pos);
void vec16_set(vec16_t *v, size_t pos, uint16_t data);
size_t vec16_push(vec16_t *v, uint16_t data);
size_t vec16_len(vec16_t *v);
void vec16_free(vec16_t *v);
void vec16_clear(vec16_t *v);
size_t vec16_index(vec16_t *v, uint16_t data);
uint64_t vec16_sum(vec16_t *v);
