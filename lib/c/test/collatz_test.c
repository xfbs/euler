#include <euler/collatz.h>
#include <euler/test.h>

void test_collatz() {
  collatz_cache_t cache = collatz_cache(1000);
  assert(1 == collatz_length(1, cache));
  assert(2 == collatz_length(2, cache));
  assert(10 == collatz_length(12, cache));
  assert(6 == collatz_length(32, cache));
  assert(17 == collatz_length(7, cache));
  free(cache.table);
}

TESTS() { RUN(test_collatz); }
