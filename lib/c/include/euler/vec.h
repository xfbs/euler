#include <stdlib.h>
#include <string.h>
#pragma once

typedef struct {
    void **data;
    size_t cap;
    size_t len;
} vec_t;

vec_t vec_new(size_t len, void *fill);
void *vec_get(vec_t *v, size_t pos);
void vec_set(vec_t *v, size_t pos, void *data);
size_t vec_push(vec_t *v, void *data);
size_t vec_len(vec_t *v);
void vec_sort(vec_t *v, int (*comp)(const void *, const void *));
void vec_free(vec_t *v);
