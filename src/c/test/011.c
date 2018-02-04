
#include <euler/vec.h>
#include "011.h"
#include <euler/test.h>

vecp_t setup() {
  uint8_t nums[4][4] = {{1, 2, 3, 4}, {2, 4, 6, 7}, {4, 5, 8, 9}, {1, 4, 2, 3}};

  vecp_t v = vecp_new(0, NULL);

  for (size_t x = 0; x < 4; x++) {
    vec8_t *row = vec8_alloc(0, 0);
    vec_push(&v, row);

    for (size_t y = 0; y < 4; y++) {
      vec_push(row, nums[x][y]);
    }
  }

  return v;
}

void test_get() {
  vecp_t v = setup();

  assert(get(&v, 0, 0) == 1);
  assert(get(&v, 0, 1) == 2);
  assert(get(&v, 0, 2) == 3);
  assert(get(&v, 0, 3) == 4);
  assert(get(&v, 1, 0) == 2);
  assert(get(&v, 1, 1) == 4);
  assert(get(&v, 1, 2) == 6);
  assert(get(&v, 1, 3) == 7);
  assert(get(&v, 3, 0) == 1);
  assert(get(&v, 3, 1) == 4);
  assert(get(&v, 3, 2) == 2);
  assert(get(&v, 3, 3) == 3);

  assert(get(&v, 4, 0) == 0);
  assert(get(&v, 3, 4) == 0);
  assert(get(&v, 4, 4) == 0);
  assert(get(&v, -1, 3) == 0);
  assert(get(&v, 1, -3) == 0);
  assert(get(&v, -1, -3) == 0);
  assert(get(&v, 4, -3) == 0);
}

void test_max_product() {
  vecp_t v = setup();

  assert(max_product(&v, 0, 1, 0) == 1);
  assert(max_product(&v, 1, 0, 0) == 1);
  assert(max_product(&v, 1, 1, 0) == 1);
  assert(max_product(&v, 1, -1, 0) == 1);
  assert(max_product(&v, -1, 1, 0) == 1);

  assert(max_product(&v, 0, 1, 1) == 9);
  assert(max_product(&v, 1, 0, 1) == 9);
  assert(max_product(&v, 1, 1, 1) == 9);
  assert(max_product(&v, 1, -1, 1) == 9);
  assert(max_product(&v, -1, 1, 1) == 9);

  assert(max_product(&v, 0, 1, 2) == 8 * 9);
  assert(max_product(&v, 1, 0, 2) == 7 * 9);
  assert(max_product(&v, 1, 1, 2) == 6 * 9);
  assert(max_product(&v, 1, -1, 2) == 7 * 8);
  assert(max_product(&v, -1, 1, 2) == 7 * 8);

  assert(max_product(&v, 0, 1, 3) == 5 * 8 * 9);
  assert(max_product(&v, 1, 0, 3) == 4 * 7 * 9);
  assert(max_product(&v, 1, 1, 3) == 2 * 6 * 9);
  assert(max_product(&v, 1, -1, 3) == 7 * 8 * 4);
  assert(max_product(&v, -1, 1, 3) == 7 * 8 * 4);

  assert(max_product(&v, 0, 1, 4) == 4 * 5 * 8 * 9);
  assert(max_product(&v, 1, 0, 4) == 4 * 7 * 9 * 3);
  assert(max_product(&v, 1, 1, 4) == 1 * 4 * 8 * 3);
  assert(max_product(&v, 1, -1, 4) == 1 * 5 * 6 * 4);
  assert(max_product(&v, -1, 1, 4) == 1 * 5 * 6 * 4);

  assert(max_product(&v, 0, 1, 5) == 0);
  assert(max_product(&v, 1, 0, 5) == 0);
  assert(max_product(&v, 1, 1, 5) == 0);
  assert(max_product(&v, 1, -1, 5) == 0);
  assert(max_product(&v, -1, 1, 5) == 0);
}

void test_solve_011() {
  vecp_t v = setup();

  assert(solve_011(&v, 0) == 1);
  assert(solve_011(&v, 1) == 9);
  assert(solve_011(&v, 2) == 8 * 9);
  assert(solve_011(&v, 3) == 5 * 8 * 9);
  assert(solve_011(&v, 4) == 4 * 5 * 8 * 9);
  assert(solve_011(&v, 5) == 0);
}

