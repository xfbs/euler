#include "solve.h"

uint32_t solve(size_t max)
{
    // generate all primes below max
    prime_t p = prime_new();
    size_t primes = primes_below(&p, max);

    // bitvec to store the cyclic primes we found
    bitvec_t b = bitvec_new(primes);

    for(size_t i = 0; i < primes; i++) {
        check_prime_cycle(&p, &b, i);
    }

    return bitvec_count(&b);
}

size_t primes_below(prime_t *p, uint32_t n)
{
    size_t i = 10;
    while(prime_nth(p, i) < n) i += 10;
    while(prime_nth(p, i) > n) i--;
    return i+1;
}

void check_prime_cycle(prime_t *p, bitvec_t *b, size_t cur)
{
    uint32_t num = prime_nth(p, cur);
    uint32_t max = 1;
    size_t mag = 0;
    while(max <= num) {
        max *= 10;
        mag += 1;
    }
    max /= 10;

    size_t index[mag];
    index[0] = cur;

    // cycle num and check if all cycles are prime
    for(size_t i = 1; i < mag; i++) {
        uint8_t leading = num / max;
        num -= leading * max;
        num *= 10;
        num += leading;

        index[i] = prime_which(p, num);
        if(index[i] == SIZE_MAX) return;
    }

    // flag all cyclic primes
    for(size_t i = 0; i < mag; i++) {
        bitvec_set(b, index[i]);
    }
}
