#include <euler/prime.h>
#include <euler/vec.h>
#include <math.h>
#define prime_get(p, nth) vec_get(&(p)->primes, nth)
#define prime_len(p) vec_len(&(p)->primes)
#define prime_push(p, elem) vec_push(&(p)->primes, elem)
#define prime_last(p) prime_get(p, prime_len(p) - 1)

prime_t prime_new() {
  prime_t p;
  p.primes = vec32_new(0, 0);
  prime_push(&p, 2);
  prime_push(&p, 3);

  return p;
}

void prime_free(prime_t *p) { vec_free(&p->primes); }

uint32_t prime_nth(prime_t *p, size_t n) {
  while (n >= vec_len(&p->primes)) {
    size_t primes_count = prime_len(p);
    uint32_t candidate = prime_get(p, primes_count - 1) + 2;
    uint32_t candidate_check = 1.0 + sqrt(candidate);
    for (size_t i = 1; i < prime_len(p) && prime_get(p, i) <= candidate_check; i++) {
      if ((candidate % prime_get(p, i)) == 0) {
        // restart search with new candidate when this one fails
        candidate += 2;
        i = 0;
        continue;
      }
    }

    prime_push(p, candidate);
  }

  return prime_get(p, n);
}

size_t prime_which(prime_t *p, uint32_t pr) {
  // generate all primes up to `pr`
  while (pr > prime_nth(p, prime_len(p)));
  return vec32_bsearch(&p->primes, &pr, NULL);
}

bool prime_check(prime_t *p, uint32_t num) {
  uint32_t root = sqrt(num);

  for (size_t i = 0; prime_nth(p, i) <= root; i++) {
    if ((num % prime_nth(p, i)) == 0) {
      return false;
    }
  }

  return (num > 1);
}

size_t prime_below(prime_t *p, uint32_t n) {
  size_t i = 10;
  while (prime_nth(p, i) < n)
    i += 10;
  while (prime_nth(p, i) > n)
    i--;
  return i + 1;
}
