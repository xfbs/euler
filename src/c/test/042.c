
#include "solve.h"
#include <euler/test.h>
#include <euler/vec.h>

void test_weight() {
  assert(weight("COLIN") == 53);
  assert(weight("A") == 1);
  assert(weight("Z") == 26);
  assert(weight("AY") == 26);
}

void test_solve_042() {
  vecp_t v = vecp_new(0, NULL);
  vec_push(&v, "A");
  vec_push(&v, "Z");
  vec_push(&v, "COLIN");

  assert(solve_042(&v) == (1 * 1 + 2 * 53 + 3 * 26));
  vec_free(&v);
}

void test_is_triangle_number() {
  assert(is_triangle_number(1));
  assert(is_triangle_number(3));
  assert(is_triangle_number(6));
  assert(is_triangle_number(10));
  assert(is_triangle_number(15));
  assert(is_triangle_number(21));
  assert(is_triangle_number(28));
  assert(is_triangle_number(36));
  assert(is_triangle_number(45));
  assert(is_triangle_number(55));

  assert(!is_triangle_number(2));
  assert(!is_triangle_number(4));
  assert(!is_triangle_number(5));
  assert(!is_triangle_number(7));
  assert(!is_triangle_number(8));
  assert(!is_triangle_number(9));
  assert(!is_triangle_number(11));
  assert(!is_triangle_number(14));
  assert(!is_triangle_number(16));
  assert(!is_triangle_number(22));
}

