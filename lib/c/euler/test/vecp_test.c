#include <euler/test.h>
#include <euler/vec.h>
#include <euler/vecp.h>

void test_vecp_new() {
  int a, b, c;

  vecp_t v1 = vecp_new(0, &a);
  assert(v1.len == 0);
  assert(v1.data != NULL);
  assert(v1.cap > 0);

  vecp_t v2 = vecp_new(100, &b);
  assert(v2.len == 100);
  assert(v2.data != NULL);
  assert(v2.cap >= 100);

  vecp_t v3 = vecp_new(500, &c);
  assert(v3.len == 500);
  assert(v3.data != NULL);
  assert(v3.cap >= 500);

  vecp_free(&v1);
  vecp_free(&v2);
  vecp_free(&v3);
}

void test_vecp_get() {
  int a, b;

  vecp_t v1 = vecp_new(100, &a);
  for (size_t i = 0; i < 100; i++) {
    assert(&a == vecp_get(&v1, i));
  }

  vecp_t v2 = vecp_new(500, &b);
  for (size_t i = 0; i < 500; i++) {
    assert(&b == vecp_get(&v2, i));
  }

  vecp_free(&v1);
  vecp_free(&v2);
}

void test_vecp_get_generic() {
  int a, b;

  vecp_t v1 = vecp_new(100, &a);
  for (size_t i = 0; i < 100; i++) {
    assert(&a == vec_get(&v1, i));
  }

  vecp_t v2 = vecp_new(500, &b);
  for (size_t i = 0; i < 500; i++) {
    assert(&b == vec_get(&v2, i));
  }

  vec_free(&v1);
  vec_free(&v2);
}

void test_vecp_set() {
  int a, b, c, d, e;
  vecp_t v = vecp_new(6, NULL);

  vecp_set(&v, 0, &a);
  assert(&a == vecp_get(&v, 0));

  vecp_set(&v, 1, &b);
  assert(&b == vecp_get(&v, 1));

  vecp_set(&v, 2, &c);
  assert(&c == vecp_get(&v, 2));

  vecp_set(&v, 3, &d);
  assert(&d == vecp_get(&v, 3));

  vecp_set(&v, 4, &e);
  assert(&e == vecp_get(&v, 4));
  assert(NULL == vecp_get(&v, 5));

  vecp_free(&v);
}

void test_vecp_set_generic() {
  int a, b, c, d, e;
  vecp_t v = vecp_new(6, NULL);

  vec_set(&v, 0, &a);
  assert(&a == vec_get(&v, 0));

  vec_set(&v, 1, &b);
  assert(&b == vec_get(&v, 1));

  vec_set(&v, 2, &c);
  assert(&c == vec_get(&v, 2));

  vec_set(&v, 3, &d);
  assert(&d == vec_get(&v, 3));

  vec_set(&v, 4, &e);
  assert(&e == vec_get(&v, 4));
  assert(NULL == vec_get(&v, 5));

  vec_free(&v);
}

void test_vecp_push() {
  int a, b, c, d, e;
  vecp_t v = vecp_new(10, NULL);

  vecp_push(&v, &a);
  assert(vecp_get(&v, 10) == &a);
  assert(vecp_len(&v) == 11);

  vecp_push(&v, &b);
  assert(vecp_get(&v, 11) == &b);
  assert(vecp_len(&v) == 12);

  vecp_push(&v, &c);
  assert(vecp_get(&v, 12) == &c);
  assert(vecp_len(&v) == 13);

  vecp_push(&v, &d);
  assert(vecp_get(&v, 13) == &d);
  assert(vecp_len(&v) == 14);

  vecp_push(&v, &e);
  assert(vecp_get(&v, 14) == &e);
  assert(vecp_len(&v) == 15);

  vecp_free(&v);
}

void test_vecp_push_generic() {
  int a, b, c, d, e;
  vecp_t v = vecp_new(10, NULL);

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

void test_vecp_len() {
  vecp_t v = vecp_new(5, NULL);
  assert(vecp_len(&v) == 5);
  vecp_push(&v, NULL);
  assert(vecp_len(&v) == 6);
  vecp_free(&v);
}

void test_vecp_len_generic() {
  vecp_t v = vecp_new(5, NULL);
  assert(vec_len(&v) == 5);
  vec_push(&v, NULL);
  assert(vec_len(&v) == 6);
  vec_free(&v);
}
