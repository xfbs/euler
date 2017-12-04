#include "solve.h"

uint32_t solve(uint32_t n) {
    prime_t p = prime_new();
    size_t i = 1;
    uint32_t sum = 0;
    uint32_t prime = 2;

    while(prime < n) {
        sum += prime;
        prime = prime_nth(&p, i);
        i++;
    }

    return sum;
}
