#include <euler/vecp.h>
#include <stdlib.h>

// which method to autogenerate and their names
#define default_cmp ptr_cmp
#define vec_get     vecp_get
#define vec_set     vecp_set
#define vec_len     vecp_len
#define vec_clear   vecp_clear
#define vec_new     vecp_new
#define vec_alloc   vecp_alloc
#define vec_reserve vecp_reserve
#define vec_push    vecp_push
#define vec_free    vecp_free

// define types for autogeneration to work
typedef vecp_t      vec_t;
typedef void *      elem_t;
typedef vecp_cmp    elem_cmp;

// autogenerate methods
#include "vec_impl.h"

// which methods we will manually implement
#define vec_index   vecp_index
#define vec_lsearch vecp_lsearch
#define vec_bsearch vecp_bsearch
#define vec_sort    vecp_sort

static int search_cmp(const void *_a, const void *_b) {
  const elem_t *b = _b;
  if (_a < *b)
    return -1;
  if (_a == *b)
    return 0;
  return 1;
}

static _Thread_local elem_cmp custom_sort_cmp;
static int sort_cmp(const void *_a, const void *_b) {
  const void * const * a = _a;
  const void * const *b = _b;
  return custom_sort_cmp(*a, *b);
}

typedef struct {
  elem_cmp cmp;
  void *data;
} custom_cmp_info;

static int custom_cmp(const void *_a, const void *_b) {
  const custom_cmp_info *info = _a;
  const elem_t *b = _b;

  return info->cmp(info->data, *b);
}

size_t vec_index(const vec_t *v, elem_t data) {
  // perform a linear search with a simple comparison
  return vec_lsearch(v, data, NULL);
}

size_t vec_lsearch(const vec_t *v, void *data, const elem_cmp cmp) {
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

size_t vec_bsearch(const vec_t *v, void *_data, elem_cmp _cmp) {
  custom_cmp_info cmp_data = {.cmp = _cmp, .data = _data};
  const elem_cmp cmp = _cmp ? custom_cmp : search_cmp;
  void *data = _cmp ? &cmp_data : _data;

  // use built-in bsearch
  elem_t *elem = bsearch(data, v->data, vec_len(v), sizeof(elem_t), cmp);

  // return SIZE_MAX if we didn't find anything
  return elem ? elem - v->data : SIZE_MAX;
}

void vec_sort(vec_t *v, elem_cmp cmp) {
  if(cmp) {
    // FIXME: this would be nicer with qsort_s, but I don't have it on my
    // system.
    custom_sort_cmp = cmp;
    qsort(v->data, v->len, sizeof(elem_t), sort_cmp);
  } else {
    qsort(v->data, v->len, sizeof(elem_t), default_cmp);
  }
}
