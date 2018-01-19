#include <stdint.h>
#include <stddef.h>
#include "euler/vec.h"
#pragma once

uint64_t get(vec_t *grid, int64_t x, int64_t y);
uint64_t solve(vec_t *v, size_t len);
uint64_t max_product(vec_t *grid, int8_t dir_x, int8_t dir_y, size_t len);
