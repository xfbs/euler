#include <euler/vecp.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> // FIXME

#define element_equal uint8_cmp
#define vec_get vecp_get
#define vec_set vecp_set
#define vec_len vecp_len
#define vec_clear vecp_clear
#define vec_new vecp_new
#define vec_alloc vecp_alloc
#define vec_reserve vecp_reserve
#define vec_push vecp_push
#define vec_free vecp_free

static int element_equal(const void *, const void *);

const static size_t initial_capacity = 256;
typedef void *element_type;
typedef vecp_t vector_type;
typedef vecp_cmp element_cmp;
const static size_t element_size = sizeof(element_type);
const static size_t vector_size  = sizeof(vector_type);
const static element_cmp default_cmp = element_equal;

#include "vec_impl.h"

#define vec_index vecp_index
#define vec_lsearch vecp_lsearch
#define vec_bsearch vecp_bsearch
#define vec_sort vecp_sort

static int search_cmp(const void *_a, const void *_b) {
  const element_type *b = _b;
  if (_a < *b)
    return -1;
  if (_a == *b)
    return 0;
  return 1;
}

typedef struct {
  element_cmp cmp;
  void *data;
} custom_cmp_info;

static int custom_cmp(const void *_a, const void *_b) {
  const custom_cmp_info *info = _a;
  const element_type *b = _b;

  return info->cmp(info->data, *b);
}

size_t vec_index(const vector_type *v, element_type data) {
  // perform a linear search with a simple comparison
  return vec_lsearch(v, data, NULL);
}

size_t vec_lsearch(const vector_type *v, void *data, const element_cmp cmp) {
  if(cmp) {
    for(size_t pos = 0; pos < vec_len(v); pos++) {
      if(0 == cmp(data, vec_get(v, pos))) {
        return pos;
      }
    }
  } else {
    for(size_t pos = 0; pos < vec_len(v); pos++) {
      if(data == vec_get(v, pos)) {
        return pos;
      }
    }
  }

  return SIZE_MAX;
}

size_t vec_bsearch(const vector_type *v, void *_data, element_cmp _cmp) {
  custom_cmp_info cmp_data = {.cmp = _cmp, .data = _data};
  const element_cmp cmp = _cmp ? custom_cmp : search_cmp;
  void *data = _cmp ? &cmp_data : _data;

  // use built-in bsearch
  element_type *elem = bsearch(data, v->data, vec_len(v), element_size, cmp);

  // return SIZE_MAX if we didn't find anything
  return elem ? elem - v->data : SIZE_MAX;
}

void vec_sort(vector_type *v, element_cmp _cmp) {
  // use default cmp if user passes NULL
  const element_cmp cmp = _cmp ? _cmp : default_cmp;

  // use built-in (quick?) sort
  qsort(v->data, v->len, element_size, cmp);
}
