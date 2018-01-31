#include <euler/sieve.h>
#include <euler/test.h>

void test_sieve_new() {
  sieve_t p = sieve_new(100);
  assert(p.len == 100);
  assert(p.state != NULL);
  sieve_free(&p);
}

void test_sieve_nth() {
  sieve_t p = sieve_new(200);

  assert(sieve_nth(&p, 0) == 2);
  assert(sieve_nth(&p, 1) == 3);
  assert(sieve_nth(&p, 2) == 5);
  assert(sieve_nth(&p, 3) == 7);
  assert(sieve_nth(&p, 4) == 11);
  assert(sieve_nth(&p, 5) == 13);
  assert(sieve_nth(&p, 6) == 17);
  assert(sieve_nth(&p, 7) == 19);
  assert(sieve_nth(&p, 8) == 23);
  assert(sieve_nth(&p, 9) == 29);
  assert(sieve_nth(&p, 10) == 31);
  assert(sieve_nth(&p, 11) == 37);
  assert(sieve_nth(&p, 21) == 79);
  assert(sieve_nth(&p, 31) == 131);
  assert(sieve_nth(&p, 41) == 181);

  sieve_free(&p);
}

void test_sieve_which() {
  sieve_t p = sieve_new(200);

  assert(sieve_which(&p, 2) == 0);
  assert(sieve_which(&p, 3) == 1);
  assert(sieve_which(&p, 5) == 2);
  assert(sieve_which(&p, 7) == 3);
  assert(sieve_which(&p, 11) == 4);
  assert(sieve_which(&p, 13) == 5);
  assert(sieve_which(&p, 17) == 6);
  assert(sieve_which(&p, 19) == 7);
  assert(sieve_which(&p, 23) == 8);
  assert(sieve_which(&p, 29) == 9);
  assert(sieve_which(&p, 31) == 10);
  assert(sieve_which(&p, 37) == 11);
  assert(sieve_which(&p, 79) == 21);
  assert(sieve_which(&p, 131) == 31);
  assert(sieve_which(&p, 181) == 41);
  assert(sieve_which(&p, 199) == 45);

  assert(sieve_which(&p, 6) == SIZE_MAX);
  assert(sieve_which(&p, 9) == SIZE_MAX);
  assert(sieve_which(&p, 14) == SIZE_MAX);
  assert(sieve_which(&p, 21) == SIZE_MAX);
  assert(sieve_which(&p, 42) == SIZE_MAX);
  assert(sieve_which(&p, 99) == SIZE_MAX);

  sieve_free(&p);
}

void test_sieve_check() {
  sieve_t p = sieve_new(24);

  assert(sieve_check(&p, 2));
  assert(sieve_check(&p, 3));
  assert(sieve_check(&p, 5));
  assert(sieve_check(&p, 7));
  assert(sieve_check(&p, 11));
  assert(sieve_check(&p, 13));
  assert(sieve_check(&p, 17));
  assert(sieve_check(&p, 19));
  assert(sieve_check(&p, 23));

  assert(!sieve_check(&p, 0));
  assert(!sieve_check(&p, 1));
  assert(!sieve_check(&p, 4));
  assert(!sieve_check(&p, 6));
  assert(!sieve_check(&p, 8));
  assert(!sieve_check(&p, 9));
  assert(!sieve_check(&p, 10));
  assert(!sieve_check(&p, 12));
  assert(!sieve_check(&p, 14));
  assert(!sieve_check(&p, 15));
  assert(!sieve_check(&p, 16));
  assert(!sieve_check(&p, 18));
  assert(!sieve_check(&p, 20));
  assert(!sieve_check(&p, 21));
  assert(!sieve_check(&p, 22));

  sieve_free(&p);
}

void test_sieve_below() {
  sieve_t p = sieve_new(100);

  assert(sieve_below(&p, 10) == 4);
  assert(sieve_below(&p, 20) == 8);
  assert(sieve_below(&p, 100) == 25);

  sieve_free(&p);
}

TESTS() {
  RUN(test_sieve_new);
  RUN(test_sieve_nth);
  RUN(test_sieve_which);
  RUN(test_sieve_check);
  RUN(test_sieve_below);
}
