#include "bitvec.h"
#include <limits.h>
#include <stdlib.h>

bitvec_t bitvec_new(size_t l)
{
    size_t bits = sizeof(uint64_t) * CHAR_BIT;
    bitvec_t b;
    b.len = (l+bits-1)/bits;
    b.field = calloc(b.len, sizeof(uint64_t));
    return b;
}

bool bitvec_get(bitvec_t *b, size_t n) {
    size_t bits = sizeof(uint64_t) * CHAR_BIT;
    return (b->field[n / bits] & (1 << (n % bits))) ? 1 : 0;
}

void bitvec_set(bitvec_t *b, size_t n)
{
    size_t bits = sizeof(uint64_t) * CHAR_BIT;
    b->field[n / bits] |= 1 << (n % bits);
}

uint32_t bitvec_count(bitvec_t *b)
{
    uint32_t sum = 0;

    for(size_t i = 0; i < b->len; i++) {
        sum += __builtin_popcountll(b->field[i]);
    }

    return sum;
}
