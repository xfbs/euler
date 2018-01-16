#include "solve.h"

uint64_t solve(uint8_t count)
{
    size_t max = 1024;
    prime_t primes = prime_new();

    while(true) {
        uint8_t prime_factors[max];

        // initialize prime factors
        for(size_t i = 0; i < max; i++) prime_factors[i] = 0;

        // compute prime factors counts up to max
        for(size_t i = 0; prime_nth(&primes, i) < max; i++) {
            uint64_t prime = prime_nth(&primes, i);
            uint64_t cur = prime;

            while(cur < max) {
                if(prime_factors[cur] <= count) {
                    prime_factors[cur]++;
                }

                cur += prime;
            }
        }

        // check which `count` consecutive numbers have `count` distinct prime
        // factors
        for(size_t num = 0; num < (max - count); num++) {
            size_t offset;
            for(offset = 0; offset < count; offset++) {
                if(prime_factors[num + offset] != count) break;
            }

            if(offset == count) {
                if(distinct_prime_factors(&primes, count, num)) {
                    prime_free(&primes);
                    return num;
                }
            } else {
                // we can safely skip `offset` numbers
                num += offset;
            }
        }

        max *= 2;
    }
}

bool distinct_prime_factors(prime_t *p, uint8_t count, uint64_t num) {
    for(uint64_t cur = num; cur < (num + count); cur++) {
        uint8_t factors = 0;
        uint64_t state = cur;
        for(size_t i = 0; factors < count; i++) {
            // oops, current number has less than `count` prime factors
            if(state == 1) return false;

            // current prime candidate
            uint64_t prime = prime_nth(p, i);

            if((cur % prime) == 0) {
                uint64_t factor = prime;
                while((cur % (factor*prime)) == 0) factor *= prime;
                state /= factor;
                factors += 1;

                // make sure no other numbers have this prime as a factor
                for(uint64_t other = num; other < (num + count); other++) {
                    if(cur != other) {
                        if(other % factor == 0 && other % (factor * prime) != 0) {
                            // another number has the same factor
                            return false;
                        }
                    }
                }
            }
        }

        // oops, more than `count` prime factors
        if(state != 1) return false;
    }

    return true;
}
