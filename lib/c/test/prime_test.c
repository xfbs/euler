#include <euler/prime.h>
#include <euler/test.h>

void test_prime_new() {
  prime_t p = prime_new();

  assert(vec32_get(&p.primes, 0) == 2);
  assert(vec32_get(&p.primes, 1) == 3);

  prime_free(&p);
}

void test_prime_free() {
  prime_t p = prime_new();
  prime_free(&p);
}

void test_prime_nth() {
  prime_t p = prime_new();

  assert(prime_nth(&p, 0) == 2);
  assert(prime_nth(&p, 1) == 3);
  assert(prime_nth(&p, 2) == 5);
  assert(prime_nth(&p, 3) == 7);
  assert(prime_nth(&p, 4) == 11);
  assert(prime_nth(&p, 5) == 13);
  assert(prime_nth(&p, 6) == 17);
  assert(prime_nth(&p, 7) == 19);
  assert(prime_nth(&p, 8) == 23);
  assert(prime_nth(&p, 9) == 29);
  assert(prime_nth(&p, 10) == 31);
  assert(prime_nth(&p, 11) == 37);
  assert(prime_nth(&p, 21) == 79);
  assert(prime_nth(&p, 31) == 131);
  assert(prime_nth(&p, 41) == 181);

  prime_free(&p);
}

void test_prime_which() {
  prime_t p = prime_new();

  // gen primes
  prime_nth(&p, 100);

  assert(prime_which(&p, 2) == 0);
  assert(prime_which(&p, 3) == 1);
  assert(prime_which(&p, 5) == 2);
  assert(prime_which(&p, 7) == 3);
  assert(prime_which(&p, 11) == 4);
  assert(prime_which(&p, 13) == 5);
  assert(prime_which(&p, 17) == 6);
  assert(prime_which(&p, 19) == 7);
  assert(prime_which(&p, 23) == 8);
  assert(prime_which(&p, 29) == 9);
  assert(prime_which(&p, 31) == 10);
  assert(prime_which(&p, 37) == 11);
  assert(prime_which(&p, 79) == 21);
  assert(prime_which(&p, 131) == 31);
  assert(prime_which(&p, 181) == 41);
  assert(prime_which(&p, 199) == 45);

  prime_free(&p);
}

void test_prime_check() {
  prime_t p = prime_new();

  assert(prime_check(&p, 2));
  assert(prime_check(&p, 3));
  assert(prime_check(&p, 5));
  assert(prime_check(&p, 7));
  assert(prime_check(&p, 11));
  assert(prime_check(&p, 13));
  assert(prime_check(&p, 17));
  assert(prime_check(&p, 19));
  assert(prime_check(&p, 23));

  assert(!prime_check(&p, 0));
  assert(!prime_check(&p, 1));
  assert(!prime_check(&p, 4));
  assert(!prime_check(&p, 6));
  assert(!prime_check(&p, 8));
  assert(!prime_check(&p, 9));
  assert(!prime_check(&p, 10));
  assert(!prime_check(&p, 15));

  prime_free(&p);
}

void test_prime_below() {
  prime_t p = prime_new();

  assert(prime_below(&p, 10) == 4);
  assert(prime_below(&p, 20) == 8);
  assert(prime_below(&p, 100) == 25);

  prime_free(&p);
}
