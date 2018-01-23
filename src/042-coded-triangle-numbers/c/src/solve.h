#include <stdint.h>
#include <stdbool.h>
#include <euler/vec.h>
#pragma once

uint64_t solve(vec_t *v);
uint64_t weight(const char *str);
bool is_triangle_word(const char *word);
bool is_triangle_number(uint64_t num);
