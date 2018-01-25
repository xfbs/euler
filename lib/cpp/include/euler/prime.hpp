#include <vector>
#include <cstdint>
#pragma once

namespace euler {
struct Prime {
    std::vector<uint64_t> primes;

    Prime();
    uint64_t next();
    uint64_t nth(size_t pos);
    size_t which(uint64_t prime);
    bool check(uint64_t prime);
    size_t below(uint64_t num);
};
}
