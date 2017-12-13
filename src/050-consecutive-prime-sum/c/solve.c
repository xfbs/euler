#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "solve.h"

bool is_prime(prime_t *p, uint64_t num)
{
    uint64_t root = sqrt(num);
    uint64_t prim = 0;
    for(size_t i = 0; prime_nth(p, i) <= root; i++) {
        prim = prime_nth(p, i);
        if((num % prim) == 0) return false;
    }

    // we need to assume that prim is odd
    if(prim == 2) prim = 1;
    for(uint64_t i = prim+2; i <= root; i += 2) {
        if((num % i) == 0) return false;
    }

    return true;
}

uint64_t solve(uint64_t max)
{
    prime_t p = prime_new();

    // find the max len
    size_t max_len;
    uint64_t sum_pre = 0;
    for(max_len = 0; sum_pre + prime_nth(&p, max_len) < max; max_len++) {
        sum_pre += prime_nth(&p, max_len);
    }

    // sum of primes[0] ... primes[len-1]
    for(size_t len = max_len; len > 1; len--) {
        // running sum of primes[i-len] ... primes[i]
        uint64_t sum = sum_pre;

        // subtract last prime for next iteration
        sum_pre -= prime_nth(&p, len-1);

        for(size_t i = len; sum < max; i++) {
            if(is_prime(&p, sum)) {
                prime_free(&p);
                return sum;
            }

            sum -= prime_nth(&p, i-len);
            sum += prime_nth(&p, i);
        }
    }

    prime_free(&p);
    return 0;
}
