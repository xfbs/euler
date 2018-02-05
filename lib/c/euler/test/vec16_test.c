#include "euler/vec16.h"
#include <euler/test.h>

void test_vec16_new() {
  vec16_t v1 = vec16_new(0, 0);
  assert(v1.len == 0);
  assert(v1.data);
  assert(v1.cap);
  vec16_free(&v1);

  vec16_t v2 = vec16_new(100, 2413);
  assert(v2.len == 100);
  assert(v2.data);
  assert(v2.cap >= 100);
  vec16_free(&v2);

  vec16_t v3 = vec16_new(500, 3423);
  assert(v3.len == 500);
  assert(v3.data);
  assert(v3.cap >= 500);
  vec16_free(&v3);
}

void test_vec16_get() {
  vec16_t v2 = vec16_new(100, 2431);
  for (size_t i = 0; i < 100; i++) {
    assert(2431 == vec16_get(&v2, i));
  }
  vec16_free(&v2);

  vec16_t v3 = vec16_new(500, 3451);
  for (size_t i = 0; i < 500; i++) {
    assert(3451 == vec16_get(&v3, i));
  }
  vec16_free(&v3);
}

void test_vec16_set() {
  vec16_t v1 = vec16_new(10, 0);

  for (size_t i = 0; i < 10; i++) {
    vec16_set(&v1, i, 1000 + i);
    assert(1000 + i == vec16_get(&v1, i));
  }
  vec16_free(&v1);
}

void test_vec16_push() {
  vec16_t v = vec16_new(10, 0);

  vec16_push(&v, 123);
  assert(vec16_get(&v, 10) == 123);
  assert(vec16_len(&v) == 11);

  vec16_push(&v, 234);
  assert(vec16_get(&v, 11) == 234);
  assert(vec16_len(&v) == 12);

  vec16_push(&v, 345);
  assert(vec16_get(&v, 12) == 345);
  assert(vec16_len(&v) == 13);

  vec16_push(&v, 456);
  assert(vec16_get(&v, 13) == 456);
  assert(vec16_len(&v) == 14);

  vec16_push(&v, 567);
  assert(vec16_get(&v, 14) == 567);
  assert(vec16_len(&v) == 15);

  vec16_free(&v);
}

void test_vec16_len() {
  vec16_t v = vec16_new(5, 0);
  assert(vec16_len(&v) == 5);
  vec16_push(&v, 7);
  assert(vec16_len(&v) == 6);
  vec16_free(&v);
}
