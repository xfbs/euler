// generic vector implementation

const static size_t initial_capacity = 256;
const static size_t element_size = sizeof(element_type);
const static size_t vector_size  = sizeof(vector_type);


#ifdef element_equal
static int element_equal(const void *_a, const void *_b) {
  const element_type *a = _a;
  const element_type *b = _b;
  if (*a < *b)
    return -1;
  if (*a == *b)
    return 0;
  return 1;
}

const static element_cmp default_cmp = element_equal;
#endif

#ifdef vec_get
element_type vec_get(const vector_type *v, size_t pos) { return v->data[pos]; }
#endif

#ifdef vec_set
element_type vec_set(vector_type *v, size_t pos, element_type data) {
  element_type prev = v->data[pos];
  v->data[pos] = data;
  return prev;
}
#endif

#ifdef vec_len
size_t vec_len(const vector_type *v) { return v->len; }
#endif

#ifdef vec_clear
void vec_clear(vector_type *v) { v->len = 0; }
#endif

#ifdef vec_new
vector_type vec_new(size_t len, element_type fill) {
  vector_type v = {.data = NULL, .cap = initial_capacity, .len = len};

  // make sure capacity is bigger than initial length
  while (v.cap < len) {
    v.cap *= 2;
  }

  // allocate data of given capacity, calloc ensures that the data is
  // zero-initialized.
  v.data = calloc(v.cap, element_size);

  // we don't need to initialize the array if it should be filled with zeroes.
  if (fill != 0) {
    for (size_t i = 0; i < len; i++) {
      v.data[i] = fill;
    }
  }

  return v;
}
#endif

#ifdef vec_alloc
vector_type *vec_alloc(size_t len, element_type fill) {
  vector_type *v = malloc(vector_size);
  *v = vec_new(len, fill);
  return v;
}
#endif

#ifdef vec_reserve
void vec_reserve(vector_type *v, size_t size) {
  if ((v->cap - v->len) < size) {
    while ((v->cap - v->len) < size) {
      v->cap *= 2;
    }

    v->data = realloc(v->data, v->cap * element_size);
  }
}
#endif

#ifdef vec_push
size_t vec_push(vector_type *v, element_type data) {
  // grow the length of the vector
  vec_reserve(v, 1);
  v->len++;

  // set the data of the new element
  vec_set(v, vec_len(v) - 1, data);
  return vec_len(v);
}
#endif

#ifdef vec_free
void vec_free(vector_type *v) {
  // release data
  free(v->data);

  // reset everything to trigger segfault if vec is used by accident
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}
#endif

#ifdef vec_index
size_t vec_index(const vector_type *v, element_type data) {
  // perform a linear search with a simple comparison
  return vec_lsearch(v, &data, NULL);
}
#endif

#ifdef vec_lsearch
size_t vec_lsearch(const vector_type *v, void *data, element_cmp _cmp) {
  // use default cmp if uses passes NULL
  const element_cmp cmp = _cmp ? _cmp : default_cmp;

  for(size_t pos = 0; pos < vec_len(v); pos++) {
    if(0 == cmp(data, &v->data[pos])) {
      return pos;
    }
  }

  return SIZE_MAX;
}
#endif

#ifdef vec_bsearch
size_t vec_bsearch(const vector_type *v, void *data, element_cmp _cmp) {
  // use default cmp if user passes NULL
  const element_cmp cmp = _cmp ? _cmp : default_cmp;

  // use built-in bsearch
  element_type *elem = bsearch(data, v->data, vec_len(v), element_size, cmp);

  // return SIZE_MAX if we didn't find anything
  return elem ? elem - v->data : SIZE_MAX;
}
#endif

#ifdef vec_sort
void vec_sort(vector_type *v, element_cmp _cmp) {
  // use default cmp if user passes NULL
  const element_cmp cmp = _cmp ? _cmp : default_cmp;

  // use built-in (quick?) sort
  qsort(v->data, v->len, element_size, cmp);
}
#endif

#ifdef vec_sum
uint64_t vec_sum(const vector_type *v) {
  uint64_t sum = 0;

  for (size_t pos = 0; pos < vec_len(v); pos++) {
    sum += vec_get(v, pos);
  }

  return sum;
}
#endif
