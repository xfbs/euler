#include "euler/vec16.h"

vec16_t vec16_new(size_t len, uint16_t fill)
{
    vec16_t v = {
        .data = NULL,
        .cap = 256,
        .len = len
    };

    while(v.cap < len) v.cap *= 2;
    v.data = calloc(v.cap, sizeof(uint16_t));
    for(size_t i = 0; i < len; i++) v.data[i] = fill;

    return v;
}

vec16_t *vec16_alloc(size_t len, uint16_t fill)
{
    vec16_t *v = malloc(sizeof(vec16_t));
    *v = vec16_new(len, fill);
    return v;
}

uint16_t vec16_get(vec16_t *v, size_t pos)
{
    return v->data[pos];
}

void vec16_set(vec16_t *v, size_t pos, uint16_t data)
{
    v->data[pos] = data;
}

size_t vec16_push(vec16_t *v, uint16_t data)
{
    if(v->len == v->cap) {
        v->cap *= 2;
        v->data = realloc(v->data, v->cap * sizeof(uint16_t));
    }

    v->data[v->len] = data;
    return v->len++;
}

size_t vec16_len(vec16_t *v)
{
    return v->len;
}

void vec16_free(vec16_t *v)
{
    free(v->data);
    v->data = NULL;
    v->cap = 0;
    v->len = 0;
}

void vec16_clear(vec16_t *v)
{
    v->len = 0;
}
