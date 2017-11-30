#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma once

typedef struct {
    uint32_t *data;
    size_t rows;
} triangle_t;

uint32_t solve(triangle_t *t);
uint32_t triangle_get(triangle_t t, size_t row, size_t index);
uint32_t triangle_set(triangle_t t, size_t row, size_t index, uint32_t num);
void triangle_simplify(triangle_t *t);
