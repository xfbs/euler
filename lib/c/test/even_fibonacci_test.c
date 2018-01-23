#include <euler/even_fibonacci.h>
#include <euler/test.h>

void test_fibos() {
  assert(next_even_fibonacci(2) == 8);
  assert(next_even_fibonacci(8) == 34);
  assert(next_even_fibonacci(34) == 144);
  assert(next_even_fibonacci(144) == 610);

  for (uint64_t cur = 2; cur < 1000000; cur = next_even_fibonacci(cur)) {
    // make sure it's even
    assert((cur & 1) == 0);
  }
}

TESTS() { RUN(test_fibos); }
