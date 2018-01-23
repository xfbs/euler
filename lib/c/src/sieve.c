#include "euler/sieve.h"
#include <stdlib.h>

sieve_t sieve_new(size_t size) {
  sieve_t sieve;
  sieve.state = calloc(size, sizeof(bool));
  sieve.len = size;

  for (size_t pos = 0; pos < size; pos++)
    sieve.state[pos] = true;
  sieve.state[0] = false;
  sieve.state[1] = false;

  uint64_t p = 2;
  while ((p * p) < size) {
    for (uint64_t f = p; f <= (size / p); f++) {
      sieve.state[p * f] = false;
    }

    p++;
    while (!sieve.state[p])
      p++;
  }

  return sieve;
}

void sieve_free(sieve_t *sieve) { free(sieve->state); }

uint32_t sieve_nth(sieve_t *sieve, size_t n) {
  size_t pos = 2;

  for (; n > 0; n--) {
    while (!sieve->state[pos++])
      ;
  }

  while (!sieve->state[pos])
    pos++;
  return pos;
}

size_t sieve_which(sieve_t *sieve, uint32_t num) {
  if (sieve->state[num]) {
    return sieve_below(sieve, num);
  } else {
    return SIZE_MAX;
  }
}

bool sieve_check(sieve_t *sieve, uint32_t num) { return sieve->state[num]; }

size_t sieve_below(sieve_t *sieve, uint32_t n) {
  size_t count = 0;
  size_t pos;

  for (pos = 0; pos < n; pos++) {
    if (sieve->state[pos]) {
      count++;
    }
  }

  return count;
}
