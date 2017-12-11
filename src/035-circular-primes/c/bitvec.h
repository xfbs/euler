#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#pragma once

typedef struct {
    uint64_t *field;
    size_t len;
} bitvec_t;

bitvec_t bitvec_new(size_t l);
bool bitvec_get(bitvec_t *b, size_t n);
void bitvec_set(bitvec_t *b, size_t n);
uint32_t bitvec_count(bitvec_t *b);
void bitvec_free(bitvec_t *b);
