#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include "solve.h"

static bool prime(prime_t *p, uint32_t num)
{
    for(size_t i = 0; i < p->len; i++) {
        if((num % p->primes[i]) == 0) return false;
    }

    uint32_t square_root = sqrt(num);

    for(uint32_t i = p->primes[p->len-1]; i <= square_root; i += 2) {
        if((num % i) == 0) return false;
    }

    return true;
}

uint32_t solve()
{
    prime_t p = prime_new();
    prime_nth(&p, 100000);

    uint32_t max = 2143;

    for(uint8_t n = 4; n < 10; n++) {
        for(uint32_t nth = 0; ; nth++) {
            uint32_t pan = nth_pandigital(n, nth);
            if(!pan) break;
            if(prime(&p, pan)) max = pan;
        }
    }

    return max;
}
