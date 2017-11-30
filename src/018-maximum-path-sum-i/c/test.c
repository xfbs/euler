#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_triangle_get();
void test_triangle_set();
void test_triangle_simplify();
void test_solve();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_triangle_get();
    test_triangle_set();
    test_triangle_simplify();
    test_solve();
    printf("done.\n");

    return 0;
}

void test_triangle_get()
{
    uint32_t sample[] = {
        1,
        2, 3,
        4, 5, 6,
        7, 8, 9, 10};

    triangle_t t = {&sample[0], 4};

    assert(triangle_get(t, 0, 0) == 1);
    assert(triangle_get(t, 1, 0) == 2);
    assert(triangle_get(t, 1, 1) == 3);
    assert(triangle_get(t, 2, 0) == 4);
    assert(triangle_get(t, 2, 1) == 5);
    assert(triangle_get(t, 2, 2) == 6);
    assert(triangle_get(t, 3, 0) == 7);
    assert(triangle_get(t, 3, 1) == 8);
    assert(triangle_get(t, 3, 2) == 9);
    assert(triangle_get(t, 3, 3) == 10);
}

void test_triangle_set()
{
    uint32_t sample[] = {
        0,
        0, 0,
        0, 0, 0,
        0, 0, 0, 0};

    triangle_t t = {&sample[0], 4};

    assert(triangle_set(t, 0, 0, 4) == 4);
    assert(triangle_get(t, 0, 0) == 4);

    assert(triangle_set(t, 1, 0, 5) == 5);
    assert(triangle_get(t, 1, 0) == 5);

    assert(triangle_set(t, 1, 1, 6) == 6);
    assert(triangle_get(t, 1, 1) == 6);

    assert(triangle_set(t, 2, 0, 7) == 7);
    assert(triangle_get(t, 2, 0) == 7);

    assert(triangle_set(t, 2, 1, 3) == 3);
    assert(triangle_get(t, 2, 1) == 3);

    assert(triangle_set(t, 2, 2, 2) == 2);
    assert(triangle_get(t, 2, 2) == 2);

    assert(triangle_set(t, 3, 0, 1) == 1);
    assert(triangle_get(t, 3, 0) == 1);

    assert(triangle_set(t, 3, 1, 9) == 9);
    assert(triangle_get(t, 3, 1) == 9);

    assert(triangle_set(t, 3, 2, 1) == 1);
    assert(triangle_get(t, 3, 2) == 1);

    assert(triangle_set(t, 3, 3, 0) == 0);
    assert(triangle_get(t, 3, 3) == 0);
}

void test_triangle_simplify()
{
    uint32_t sample[] = {
        3,
        7, 4,
        2, 4, 6,
        8, 5, 9, 3};

    triangle_t t = {&sample[0], 4};
    assert(t.rows == 4);

    triangle_simplify(&t);
    assert(t.rows == 3);
    assert(triangle_get(t, 2, 0) == 10);
    assert(triangle_get(t, 2, 1) == 13);
    assert(triangle_get(t, 2, 2) == 15);

    triangle_simplify(&t);
    assert(t.rows == 2);
    assert(triangle_get(t, 1, 0) == 20);
    assert(triangle_get(t, 1, 1) == 19);

    triangle_simplify(&t);
    assert(t.rows == 1);
    assert(triangle_get(t, 0, 0) == 23);
}

void test_solve()
{
    uint32_t sample[] = {
        3,
        7, 4,
        2, 4, 6,
        8, 5, 9, 3};

    triangle_t t = {&sample[0], 4};
    assert(solve(&t) == 23);
}

