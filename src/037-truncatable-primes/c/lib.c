#include "lib.h"
#include <assert.h>

uint32_t solve(size_t max)
{
    prime_t p = prime_new();

    size_t sum = 0;
    size_t amount = 0;

    while(amount < 11) {
        uint32_t prime = prime_next(&p);
        if(truncatable(&p, prime)) {
            sum += prime;
            amount++;
        }
    }

    return sum;
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
    uint32_t candidate_check = 1.0 + sqrt(candidate);
    for(size_t i = 1; i < p->len && p->primes[i] <= candidate_check; i++) {
        if((candidate % p->primes[i]) == 0) {
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

int equal(const void *_a, const void *_b)
{
    const uint32_t *a = _a;
    const uint32_t *b = _b;
    if(*a < *b) return -1;
    if(*a == *b) return 0;
    return 1;
}

size_t prime_which(prime_t *p, uint32_t pr)
{
    uint32_t *r = bsearch(&pr, p->primes, p->len, sizeof(uint32_t), equal);
    if(r) return r - p->primes;
    return SIZE_MAX;
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
