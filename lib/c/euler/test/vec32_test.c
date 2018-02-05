#include <euler/vec32.h>
#include <euler/test.h>

void test_vec32_new() {
  vec32_t v1 = vec32_new(0, 0);
  assert(v1.len == 0);
  assert(v1.data);
  assert(v1.cap);
  vec32_free(&v1);

  vec32_t v2 = vec32_new(100, 2413);
  assert(v2.len == 100);
  assert(v2.data);
  assert(v2.cap >= 100);
  vec32_free(&v2);

  vec32_t v3 = vec32_new(500, 3423);
  assert(v3.len == 500);
  assert(v3.data);
  assert(v3.cap >= 500);
  vec32_free(&v3);
}

void test_vec32_get() {
  vec32_t v2 = vec32_new(100, 2431);
  for (size_t i = 0; i < 100; i++) {
    assert(2431 == vec32_get(&v2, i));
  }
  vec32_free(&v2);

  vec32_t v3 = vec32_new(500, 3451);
  for (size_t i = 0; i < 500; i++) {
    assert(3451 == vec32_get(&v3, i));
  }
  vec32_free(&v3);
}

void test_vec32_set() {
  vec32_t v1 = vec32_new(10, 0);

  for (size_t i = 0; i < 10; i++) {
    vec32_set(&v1, i, 1000 + i);
    assert(1000 + i == vec32_get(&v1, i));
  }
  vec32_free(&v1);
}

void test_vec32_push() {
  vec32_t v = vec32_new(10, 0);

  vec32_push(&v, 123);
  assert(vec32_get(&v, 10) == 123);
  assert(vec32_len(&v) == 11);

  vec32_push(&v, 234);
  assert(vec32_get(&v, 11) == 234);
  assert(vec32_len(&v) == 12);

  vec32_push(&v, 345);
  assert(vec32_get(&v, 12) == 345);
  assert(vec32_len(&v) == 13);

  vec32_push(&v, 456);
  assert(vec32_get(&v, 13) == 456);
  assert(vec32_len(&v) == 14);

  vec32_push(&v, 567);
  assert(vec32_get(&v, 14) == 567);
  assert(vec32_len(&v) == 15);

  vec32_free(&v);
}

void test_vec32_len() {
  vec32_t v = vec32_new(5, 0);
  assert(vec32_len(&v) == 5);
  vec32_push(&v, 7);
  assert(vec32_len(&v) == 6);
  vec32_free(&v);
}
