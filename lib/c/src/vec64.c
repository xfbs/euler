#include <euler/vec64.h>
#include <stdlib.h>

#define default_cmp uint16_cmp
#define vec_get vec64_get
#define vec_set vec64_set
#define vec_len vec64_len
#define vec_clear vec64_clear
#define vec_new vec64_new
#define vec_alloc vec64_alloc
#define vec_reserve vec64_reserve
#define vec_push vec64_push
#define vec_free vec64_free
#define vec_index vec64_index
#define vec_lsearch vec64_lsearch
#define vec_bsearch vec64_bsearch
#define vec_sort vec64_sort
#define vec_sum vec64_sum

typedef uint64_t element_type;
typedef vec64_t vector_type;
typedef vec64_cmp element_cmp;

#include "vec_impl.h"
