#include "euler/simple_prime.h"
#include <math.h>

prime_t prime_new()
{
    prime_t p;
    p.cap = 256;
    p.primes = calloc(p.cap, sizeof(uint32_t));
    p.len = 2;
    p.primes[0] = 2;
    p.primes[1] = 3;

    return p;
}

void prime_free(prime_t *p) {
    free(p->primes);
}

uint32_t prime_nth(prime_t *p, size_t n) {
    while(n >= p->len) {
        if(p->len == p->cap) {
            p->cap *= 2;
            p->primes = realloc(p->primes, p->cap * 2 * sizeof(uint32_t));
        }

        uint32_t candidate = p->primes[p->len-1] + 2;
        uint32_t candidate_check = 1.0 + sqrt(candidate);
        for(size_t i = 1; i < p->len && p->primes[i] <= candidate_check; i++) {
            if((candidate % p->primes[i]) == 0) {
                // restart search with new candidate when this one fails
                candidate += 2;
                i = 0;
                continue;
            }
        }

        p->primes[p->len] = candidate;
        p->len++;
    }

    return p->primes[n];
}

static int equal(const void *_a, const void *_b)
{
    const uint32_t *a = _a;
    const uint32_t *b = _b;
    if(*a < *b) return -1;
    if(*a == *b) return 0;
    return 1;
}

size_t prime_which(prime_t *p, uint32_t pr)
{
    while(pr > p->primes[p->len-1]) prime_nth(p, p->len);
    uint32_t *r = bsearch(&pr, p->primes, p->len, sizeof(uint32_t), equal);
    if(r) return r - p->primes;
    return SIZE_MAX;
}

bool prime_check(prime_t *p, uint32_t num)
{
    uint32_t root = sqrt(num);

    for(size_t i = 0; prime_nth(p, i) < root; i++) {
        if((num % prime_nth(p, i)) == 0) {
            return false;
        }
    }

    return true;
}

size_t primes_below(prime_t *p, uint32_t n)
{
    size_t i = 10;
    while(prime_nth(p, i) < n) i += 10;
    while(prime_nth(p, i) > n) i--;
    return i+1;
}
