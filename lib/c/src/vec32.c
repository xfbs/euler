#include <euler/vec32.h>
#include <stdlib.h>

// which method to autogenerate and their names (all)
#define default_cmp uint32_cmp
#define vec_get     vec32_get
#define vec_set     vec32_set
#define vec_len     vec32_len
#define vec_clear   vec32_clear
#define vec_new     vec32_new
#define vec_alloc   vec32_alloc
#define vec_reserve vec32_reserve
#define vec_push    vec32_push
#define vec_free    vec32_free
#define vec_index   vec32_index
#define vec_lsearch vec32_lsearch
#define vec_bsearch vec32_bsearch
#define vec_sort    vec32_sort
#define vec_sum     vec32_sum

// define types for autogeneration to work
typedef uint32_t    elem_t;
typedef vec32_t     vec_t;
typedef vec32_cmp   elem_cmp;

// autogenerate methods
#include "vec_impl.h"
