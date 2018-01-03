#include "vec.h"
#pragma once

uint64_t get(vec_t *grid, int x, int y);
uint64_t solve(vec_t *v, size_t len);
uint64_t max_product(vec_t *grid, int dir_x, int dir_y, size_t len);
