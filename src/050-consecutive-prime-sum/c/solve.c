#include <stddef.h>
#include <stdio.h>
#include "solve.h"

uint64_t solve(uint64_t max)
{
    // gen all primes up to max
    prime_t p = prime_new();
    for(size_t i = 0; prime_nth(&p, i) < max; i++);

    // save the result
    uint64_t prime = 0;

    // sum of primes[0] ... primes[len-1]
    uint64_t sum_pre = 5;
    for(size_t len = 2; len < max; len++) {
        // running sum of primes[i-len] ... primes[i]
        uint64_t sum = sum_pre;

        // add latest prime for next iteration
        sum_pre += prime_nth(&p, len);

        // if primes[0] ... primes[len-1] is already over the max, then we're
        // done because future iterations with a higher len will only be larger
        // than this.
        if(sum > max) break;

        for(size_t i = len; i < max && sum < max; i++) {
            if(SIZE_MAX != prime_which(&p, sum)) {
                prime = sum;
            }

            sum -= prime_nth(&p, i-len);
            sum += prime_nth(&p, i);
        }
    }

    prime_free(&p);
    return prime;
}
