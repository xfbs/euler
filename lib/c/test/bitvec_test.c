#include <euler/test.h>
#include <euler/bitvec.h>

void test_bitvec_new() {
    for(size_t max = 1; max < 1000; max++) {
        bitvec_t b = bitvec_new(max);
        assert(b.field);
        assert((b.len * 64) >= max);

        bitvec_free(&b);
    }
}

void test_bitvec_get() {
    size_t max = 100;
    bitvec_t b = bitvec_new(max);

    for(size_t cur = 0; cur < max; cur++) {
        assert(bitvec_get(&b, cur) == false);
    }

    bitvec_free(&b);
}

void test_bitvec_set() {
    size_t max = 100;
    bitvec_t b = bitvec_new(max);
    for(size_t cur = 0; cur < max; cur++) {
        assert(bitvec_get(&b, cur) == false);
        bitvec_set(&b, cur);
        assert(bitvec_get(&b, cur) == true);
    }

    bitvec_free(&b);
}

void test_bitvec_count() {
    for(size_t max = 10; max < 1000; max++) {
        bitvec_t b = bitvec_new(max);
        for(size_t cur = 0; cur < max; cur++) {
            assert(bitvec_count(&b) == cur);
            bitvec_set(&b, cur);
        }

        bitvec_free(&b);
    }
}

void test_bitvec_free() {
    bitvec_t b = bitvec_new(100);
    bitvec_free(&b);
}

TESTS() {
    RUN(test_bitvec_new);
    RUN(test_bitvec_get);
    RUN(test_bitvec_set);
    RUN(test_bitvec_count);
    RUN(test_bitvec_free);
}
