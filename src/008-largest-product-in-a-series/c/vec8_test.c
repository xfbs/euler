#include "test.h"
#include "vec8.h"

void test_vec8_new()
{
    vec8_t v1 = vec8_new(0, 0);
    assert(v1.len == 0);
    assert(v1.data);
    assert(v1.cap);
    vec8_free(&v1);

    vec8_t v2 = vec8_new(100, '\n');
    assert(v2.len == 100);
    assert(v2.data);
    assert(v2.cap >= 100);
    vec8_free(&v2);

    vec8_t v3 = vec8_new(500, '\n');
    assert(v3.len == 500);
    assert(v3.data);
    assert(v3.cap >= 500);
    vec8_free(&v3);
}

void test_vec8_get()
{
    vec8_t v2 = vec8_new(100, '\n');
    for(size_t i = 0; i < 100; i++) {
        assert('\n' == vec8_get(&v2, i));
    }
    vec8_free(&v2);

    vec8_t v3 = vec8_new(500, '7');
    for(size_t i = 0; i < 500; i++) {
        assert('7' == vec8_get(&v3, i));
    }
    vec8_free(&v3);
}

void test_vec8_set()
{
    vec8_t v1 = vec8_new(10, 0);
    vec8_set(&v1, 0, '0');
    assert('0' == vec8_get(&v1, 0));
    vec8_set(&v1, 1, 'r');
    assert('r' == vec8_get(&v1, 1));
    vec8_set(&v1, 2, 'b');
    assert('b' == vec8_get(&v1, 2));
    vec8_set(&v1, 3, 'm');
    assert('m' == vec8_get(&v1, 3));
    vec8_set(&v1, 4, 'u');
    assert('u' == vec8_get(&v1, 4));
    vec8_set(&v1, 5, 122);
    assert(122 == vec8_get(&v1, 5));
    vec8_set(&v1, 6, '5');
    assert('5' == vec8_get(&v1, 6));
    vec8_set(&v1, 7, 'p');
    assert('p' == vec8_get(&v1, 7));
    vec8_set(&v1, 8, ']');
    assert(']' == vec8_get(&v1, 8));
    vec8_set(&v1, 9, '\\');
    assert('\\' == vec8_get(&v1, 9));
    vec8_free(&v1);
}

void test_vec8_push()
{
    vec8_t v = vec8_new(10, 0);

    vec8_push(&v, '0');
    assert(vec8_get(&v, 10) == '0');
    assert(vec8_len(&v) == 11);

    vec8_push(&v, '1');
    assert(vec8_get(&v, 11) == '1');
    assert(vec8_len(&v) == 12);

    vec8_push(&v, '2');
    assert(vec8_get(&v, 12) == '2');
    assert(vec8_len(&v) == 13);

    vec8_push(&v, '3');
    assert(vec8_get(&v, 13) == '3');
    assert(vec8_len(&v) == 14);

    vec8_push(&v, '4');
    assert(vec8_get(&v, 14) == '4');
    assert(vec8_len(&v) == 15);

    vec8_free(&v);
}

void test_vec8_len() {
    vec8_t v = vec8_new(5, 0);
    assert(vec8_len(&v) == 5);
    vec8_push(&v, 7);
    assert(vec8_len(&v) == 6);
    vec8_free(&v);
}

TESTS() {
    RUN(test_vec8_new);
    RUN(test_vec8_get);
    RUN(test_vec8_set);
    RUN(test_vec8_push);
    RUN(test_vec8_len);
}
