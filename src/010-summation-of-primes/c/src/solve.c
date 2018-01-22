#include <euler/prime.h>
#include "solve.h"

uint64_t solve(uint64_t n) {
    prime_t p = prime_new();
    size_t i = 1;
    uint64_t sum = 0;
    uint64_t prime = 2;

    while(prime < n) {
        sum += prime;
        prime = prime_nth(&p, i);
        i++;
    }

    return sum;
}
