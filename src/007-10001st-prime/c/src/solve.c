#include <euler/simple_prime.h>
#include "solve.h"

uint64_t solve(uint32_t pos)
{
    prime_t p = prime_new();
    uint64_t prime = prime_nth(&p, pos-1);
    prime_free(&p);

    return prime;
}
