#include <euler/test.h>
#include <euler/vec.h>

void test_vec_new() {
  int a, b, c;

  vec_t v1 = vec_new(0, &a);
  assert(v1.len == 0);
  assert(v1.data);
  assert(v1.cap);
  vec_free(&v1);

  vec_t v2 = vec_new(100, &b);
  assert(v2.len == 100);
  assert(v2.data);
  assert(v2.cap >= 100);
  vec_free(&v2);

  vec_t v3 = vec_new(500, &c);
  assert(v3.len == 500);
  assert(v3.data);
  assert(v3.cap >= 500);
  vec_free(&v3);
}

void test_vec_get() {
  int a, b;

  vec_t v2 = vec_new(100, &a);
  for (size_t i = 0; i < 100; i++) {
    assert(&a == vec_get(&v2, i));
  }
  vec_free(&v2);

  vec_t v3 = vec_new(500, &b);
  for (size_t i = 0; i < 500; i++) {
    assert(&b == vec_get(&v3, i));
  }
  vec_free(&v3);
}

void test_vec_set() {
  int a, b, c, d, e, f, g, h, i, j;
  vec_t v1 = vec_new(10, 0);
  vec_set(&v1, 0, &a);
  assert(&a == vec_get(&v1, 0));
  vec_set(&v1, 1, &b);
  assert(&b == vec_get(&v1, 1));
  vec_set(&v1, 2, &c);
  assert(&c == vec_get(&v1, 2));
  vec_set(&v1, 3, &d);
  assert(&d == vec_get(&v1, 3));
  vec_set(&v1, 4, &e);
  assert(&e == vec_get(&v1, 4));
  vec_set(&v1, 5, &f);
  assert(&f == vec_get(&v1, 5));
  vec_set(&v1, 6, &g);
  assert(&g == vec_get(&v1, 6));
  vec_set(&v1, 7, &h);
  assert(&h == vec_get(&v1, 7));
  vec_set(&v1, 8, &i);
  assert(&i == vec_get(&v1, 8));
  vec_set(&v1, 9, &j);
  assert(&j == vec_get(&v1, 9));
  vec_free(&v1);
}

void test_vec_push() {
  int a, b, c, d, e;
  vec_t v = vec_new(10, NULL);

  vec_push(&v, &a);
  assert(vec_get(&v, 10) == &a);
  assert(vec_len(&v) == 11);

  vec_push(&v, &b);
  assert(vec_get(&v, 11) == &b);
  assert(vec_len(&v) == 12);

  vec_push(&v, &c);
  assert(vec_get(&v, 12) == &c);
  assert(vec_len(&v) == 13);

  vec_push(&v, &d);
  assert(vec_get(&v, 13) == &d);
  assert(vec_len(&v) == 14);

  vec_push(&v, &e);
  assert(vec_get(&v, 14) == &e);
  assert(vec_len(&v) == 15);

  vec_free(&v);
}

void test_vec_len() {
  vec_t v = vec_new(5, NULL);
  assert(vec_len(&v) == 5);
  vec_push(&v, NULL);
  assert(vec_len(&v) == 6);
  vec_free(&v);
}

TESTS() {
  RUN(test_vec_new);
  RUN(test_vec_get);
  RUN(test_vec_set);
  RUN(test_vec_push);
  RUN(test_vec_len);
}
