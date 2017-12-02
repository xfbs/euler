#include "lib.h"

int32_t solve(int32_t max)
{
    int32_t product = 1;
    uint32_t run = 0;

    prime_t p = prime_new();
    for(int32_t a = (-max + 5); a < max; a+=2) {
        // b must be odd, so we start at an odd number (this assumes that max
        // is even) and increase by two each iteration.
        // b must be positive, because when n=0, n^2+na+b shortens to just b.
        // a+b+1 >= 5 must be true
        for(int32_t b = -a+4; b < max; b+=2) {

            uint32_t cur = quadratic_prime_run(&p, a, b);
            if(cur > run) {
                run = cur;
                product = a * b;
            }
        }
    }

    return product;
}

uint32_t quadratic_prime_run(prime_t *p, int32_t a, int32_t b)
{
    prime_reset(p);
    uint32_t prime, run = 0;
    int32_t num = run*run + run*a + b;

    do {
        prime = prime_next(p);

        if(num == prime) {
            run++;
            num = run*run + run*a + b;

            while(num <= prime && prime > 2) {
                prime = prime_prev(p);
            }
        }
    } while(num > 2 && prime < num);

    return run;
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

uint32_t prime_prev(prime_t *p)
{
    if(p->cur > 0) {
        p->cur--;
    }

    return p->primes[p->cur];
}

void prime_reset(prime_t *p)
{
    p->cur = 0;
}
