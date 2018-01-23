#include "solve.h"

uint64_t solve(uint8_t count)
{
    // prime_factors is a `window` of numbers from `window_offset` to 
    // `window_offset + window_size`. it keeps a list of how many prime factors
    // each number has (up to `count + 1`, anything above we don't care about).
    size_t window_size = 10240;
    size_t window_offset = 0;
    uint8_t prime_factors[window_size];

    prime_t primes = prime_new();

    while(true) {
        size_t window_max = window_offset + window_size;

        // reset window to all-zeroes.
        for(size_t i = 0; i < window_size; i++) prime_factors[i] = 0;

        // iterate through the prime numbers, and for every number in the
        // `prime_factors` window, set how many prime factors it has
        for(size_t i = 0; prime_nth(&primes, i) < window_max; i++) {
            uint64_t prime = prime_nth(&primes, i);
            uint64_t cur = prime;

            while(cur < window_offset) cur += prime;
            while(cur < window_max) {
                // if the prime factors are already bigger than count, we
                // ignore - we don't want overflow errors and we only care if
                // the prime factors are equal to count or not anyways.
                if(prime_factors[cur - window_offset] <= count) {
                    prime_factors[cur - window_offset]++;
                }

                cur += prime;
            }
        }

        // check which `count` consecutive numbers have `count` distinct prime
        // factors
        for(size_t num = window_offset; num < (window_max - count); num++) {
            size_t offset;
            for(offset = 0; offset < count; offset++) {
                if(prime_factors[num + offset - window_offset] != count) break;
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

        window_offset += window_size - count;
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
