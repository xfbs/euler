#include "vec.h"

vec_t vec_new(size_t len, void *fill)
{
    vec_t v = {
        .data = NULL,
        .cap = 256,
        .len = len
    };

    while(v.cap < len) v.cap *= 2;
    v.data = calloc(v.cap, sizeof(void *));
    if(fill) for(size_t i = 0; i < len; i++) v.data[i] = fill;

    return v;
}

void *vec_get(vec_t *v, size_t pos)
{
    return v->data[pos];
}

void vec_set(vec_t *v, size_t pos, void *data)
{
    v->data[pos] = data;
}

size_t vec_push(vec_t *v, void *data)
{
    if(v->len == v->cap) {
        v->cap *= 2;
        v->data = realloc(v->data, v->cap * sizeof(void *));
    }

    v->data[v->len] = data;
    return v->len++;
}

size_t vec_len(vec_t *v)
{
    return v->len;
}

void vec_free(vec_t *v)
{
    free(v->data);
    v->data = NULL;
    v->cap = 0;
    v->len = 0;
}

void vec_sort(vec_t *v, int (*comp)(const void *, const void *))
{
    qsort(v->data, v->len, sizeof(void *), comp);
}
