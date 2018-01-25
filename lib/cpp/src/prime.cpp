#include "euler/prime.hpp"
#include <cmath>

using namespace euler;

Prime::Prime() {
    primes = {2, 3};
}

uint64_t Prime::nth(size_t pos) {
    while(primes.size() <= pos) next();
    return primes[pos];
}

uint64_t Prime::next() {
    uint64_t next = primes[primes.size() - 1] + 2;
    while(!check(next)) next += 2;
    primes.push_back(next);
    return next;
}

bool Prime::check(uint64_t prime) {
    uint64_t sqrt = std::sqrt(prime);

    for(size_t i = 0; primes[i] <= sqrt; i++) {
        if(prime % primes[i] == 0) {
            return false;
        }
    }

    return true;
}
