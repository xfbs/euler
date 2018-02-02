#include <euler/vec32.h>
#include <stdlib.h>

#define element_equal uint32_cmp
#define vec_get vec32_get
#define vec_set vec32_set
#define vec_len vec32_len
#define vec_clear vec32_clear
#define vec_new vec32_new
#define vec_alloc vec32_alloc
#define vec_reserve vec32_reserve
#define vec_push vec32_push
#define vec_free vec32_free
#define vec_index vec32_index
#define vec_lsearch vec32_lsearch
#define vec_bsearch vec32_bsearch
#define vec_sort vec32_sort
#define vec_sum vec32_sum

#define IS_INTEGRAL

const static size_t initial_capacity = 256;
typedef uint32_t element_type;
typedef vec32_t vector_type;
typedef vec32_cmp element_cmp;
const static size_t element_size = sizeof(element_type);
const static size_t vector_size  = sizeof(vector_type);
static int element_equal(const void *, const void *);
const static element_cmp default_cmp = element_equal;

#include "vec_impl.h"
