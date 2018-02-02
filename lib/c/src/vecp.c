#include <euler/vecp.h>
#include <stdlib.h>
#include <string.h>

#define element_equal ptr_cmp
#define vec_get vecp_get
#define vec_set vecp_set
#define vec_len vecp_len
#define vec_clear vecp_clear
#define vec_new vecp_new
#define vec_alloc vecp_alloc
#define vec_reserve vecp_reserve
#define vec_push vecp_push
#define vec_free vecp_free
#define vec_index vecp_index
#define vec_lsearch vecp_lsearch
#define vec_bsearch vecp_bsearch
#define vec_sort vecp_sort
#define vec_sum vecp_sum

static int element_equal(const void *, const void *);

const static size_t initial_capacity = 256;
typedef void *element_type;
typedef vecp_t vector_type;
typedef vecp_cmp element_cmp;
const static size_t element_size = sizeof(element_type);
const static size_t vector_size  = sizeof(vector_type);
const static element_cmp default_cmp = element_equal;

#include "vec_impl.h"
