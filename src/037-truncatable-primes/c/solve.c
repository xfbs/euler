#include "solve.h"
#include <assert.h>

uint32_t solve(size_t max)
{
    prime_t p = prime_new();

    size_t sum = 0;
    size_t amount = 0;

    for(size_t i = 0; amount < 11; i++) {
        uint32_t prime = prime_nth(&p, i);
        if(truncatable(&p, prime)) {
            sum += prime;
            amount++;
        }
    }

    return sum;
}

bool truncatable(prime_t *p, uint32_t prime)
{
    uint32_t truncated = prime;
    uint32_t exp = 1;

    while(truncated / 10) {
        truncated /= 10;
        exp *= 10;
        if(prime_which(p, truncated) == SIZE_MAX) return false;
    }

    truncated = prime;
    assert(exp <= prime);
    assert((exp*10) > prime);

    do {
        uint8_t high = truncated / exp;
        truncated -= high * exp;
        exp /= 10;
        if(prime_which(p, truncated) == SIZE_MAX) return false;
    } while(truncated > 9);

    return true;
}
