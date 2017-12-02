#include "lib.h"
#include <assert.h>

uint32_t solve(size_t max)
{
    uint32_t triangle = 1;
    uint32_t index = 1;
    prime_t p = prime_new();

    while(factor_count(&p, triangle) < max) {
        index++;
        triangle += index;
    }

    return triangle;
}

prime_t prime_new()
{
    prime_t p;
    p.cap = 256;
    p.primes = calloc(p.cap, sizeof(uint32_t));
    p.cur = 0;
    p.len = 2;
    p.primes[0] = 2;
    p.primes[1] = 3;

    return p;
}

uint32_t prime_next(prime_t *p)
{
    if(p->cur < p->len) {
        p->cur++;
        return p->primes[p->cur-1];
    }

    if(p->len == p->cap) {
        p->cap *= 2;
        p->primes = realloc(p->primes, p->cap * 2 * sizeof(uint32_t));
    }

    uint32_t candidate = p->primes[p->len-1] + 2;
    for(size_t i = 1; i < p->len; i++) {
        assert(candidate != 0);
        assert(p->primes[i] != 0);
        if((candidate % p->primes[i]) == 0) {
            // restart search with new candidate when this one fails
            candidate += 2;
            i = 0;
            continue;
        }
    }

    p->primes[p->len] = candidate;
    p->len++;
    p->cur++;

    return candidate;
}

void prime_reset(prime_t *p)
{
    p->cur = 0;
}

uint32_t factor_count(prime_t *p, uint32_t num)
{
    uint32_t count = 1;

    prime_reset(p);

    for(size_t i = 0; num != 1; i++) {
        uint32_t factors = 1;
        uint32_t prime = prime_next(p);

        while((num % prime) == 0) {
            factors++;
            num /= prime;
        }

        count *= factors;
    }

    return count;
}
