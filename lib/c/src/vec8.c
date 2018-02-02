#include <euler/vec8.h>
#include <stdlib.h>

#define element_equal uint8_cmp
#define vec_get vec8_get
#define vec_set vec8_set
#define vec_len vec8_len
#define vec_clear vec8_clear
#define vec_new vec8_new
#define vec_alloc vec8_alloc
#define vec_reserve vec8_reserve
#define vec_push vec8_push
#define vec_free vec8_free
#define vec_index vec8_index
#define vec_lsearch vec8_lsearch
#define vec_bsearch vec8_bsearch
#define vec_sort vec8_sort
#define vec_sum vec8_sum

#define IS_INTEGRAL

const static size_t initial_capacity = 256;
typedef uint8_t element_type;
typedef vec8_t vector_type;
typedef vec8_cmp element_cmp;
const static size_t element_size = sizeof(element_type);
const static size_t vector_size  = sizeof(vector_type);
static int element_equal(const void *, const void *);
const static element_cmp default_cmp = element_equal;

#include "vec_impl.h"
