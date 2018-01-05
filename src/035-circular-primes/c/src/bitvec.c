#include "euler/bitvec.h"
#include <limits.h>
#include <stdlib.h>

static const size_t bits = sizeof(uint64_t) * CHAR_BIT;

bitvec_t bitvec_new(size_t l)
{
    bitvec_t b;
    b.len = (l+bits-1)/bits;
    b.field = calloc(b.len, sizeof(uint64_t));
    for(size_t i = 0; i < b.len; i++) {
    }
    return b;
}

bool bitvec_get(bitvec_t *b, size_t n) {
    return (b->field[n / bits] & (1LL << (n % bits))) != 0;
}

void bitvec_set(bitvec_t *b, size_t n)
{
    b->field[n / bits] |= 1LL << (n % bits);
}

uint32_t bitvec_count(bitvec_t *b)
{
    uint32_t sum = 0;

    for(size_t i = 0; i < b->len; i++) {
        sum += __builtin_popcountll(b->field[i]);
    }

    return sum;
}

void bitvec_free(bitvec_t *b)
{
    free(b->field);
}
