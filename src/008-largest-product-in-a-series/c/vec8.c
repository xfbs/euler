#include "vec8.h"

vec8_t vec8_new(size_t len, uint8_t fill)
{
    vec8_t v = {
        .data = NULL,
        .cap = 256,
        .len = len
    };

    while(v.cap < len) v.cap *= 2;
    v.data = calloc(v.cap, sizeof(uint8_t));
    if(fill) memset(v.data, fill, len);

    return v;
}

vec8_t *vec8_alloc(size_t len, uint8_t fill)
{
    vec8_t *v = malloc(sizeof(vec8_t));
    *v = vec8_new(len, fill);
    return v;
}

uint8_t vec8_get(vec8_t *v, size_t pos)
{
    return v->data[pos];
}

void vec8_set(vec8_t *v, size_t pos, uint8_t data)
{
    v->data[pos] = data;
}

size_t vec8_push(vec8_t *v, uint8_t data)
{
    if(v->len == v->cap) {
        v->cap *= 2;
        v->data = realloc(v->data, v->cap * sizeof(uint8_t));
    }

    v->data[v->len] = data;
    return v->len++;
}

size_t vec8_len(vec8_t *v)
{
    return v->len;
}

void vec8_free(vec8_t *v)
{
    free(v->data);
    v->data = NULL;
    v->cap = 0;
    v->len = 0;
}
