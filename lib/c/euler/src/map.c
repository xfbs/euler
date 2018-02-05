#include <euler/map.h>
#include <stdlib.h>
#include <string.h>

// How many items must be in a bin to force an expansion?
static const size_t THRESHOLD = 5;

// How many bins should the hashmap have initially?
static const size_t INITIAL_BIN_COUNT = 1;

// Which seed should the murmur hash use as seed?
static const uint64_t SEED = 0x23948AB42905FF0A;

// source: https://primes.utm.edu/lists/2small/0bit.html
// Below, for each consecutive value of n we give the ten least positive
// integers k such that 2n-k is a prime.  In each case these are proven primes
// (proven using UBASIC's  APRT-CL). Note that 2n-k will be an n bit number (for
// these k's).
const static size_t bits_prime[] = {
  [ 0] = 0,  [ 1] = 0,   [ 2] = 1,  [ 3] = 1,
  [ 4] = 3,  [ 5] = 3,   [ 6] = 0,  [ 7] = 0,
  [ 8] = 5,  [ 9] = 3,   [10] = 3,  [11] = 9,
  [12] = 3,  [13] = 1,   [14] = 3,  [15] = 19,
  [16] = 15, [17] = 1,   [18] = 5,  [19] = 1,
  [20] = 3,  [21] = 9,   [22] = 3,  [23] = 15,
  [24] = 3,  [25] = 39,  [26] = 5,  [27] = 39,
  [28] = 57, [29] = 3,   [30] = 35, [31] = 1,
  [32] = 5,  [33] = 9,   [34] = 41, [35] = 31,
  [36] = 5,  [37] = 25,  [38] = 45, [39] = 7,
  [40] = 87, [41] = 21,  [42] = 11, [43] = 57,
  [44] = 17, [45] = 55,  [46] = 21, [47] = 115,
  [48] = 59, [49] = 81,  [50] = 27, [51] = 129,
  [52] = 47, [53] = 111, [54] = 33, [55] = 55,
  [56] = 5,  [57] = 13,  [58] = 27, [59] = 55,
  [60] = 93, [61] = 1,   [62] = 57, [63] = 25,
};

map_t map_new() {
  map_t hm = {
    .elem_count = 0,
    .bin_count  = INITIAL_BIN_COUNT,
    .free_key   = NULL,
    .free_val   = NULL,
    .hash       = NULL,
    .cmp        = NULL,
    .bins       = calloc(INITIAL_BIN_COUNT, sizeof(map_item_t))
  };

  return hm;
}

// check if a uint64_t contains a zero byte, taken from
// https://jameshfisher.com/2017/01/24/bitwise-check-for-zero-byte.html
bool contains_zero_byte(uint64_t v) {
  return (v - UINT64_C(0x0101010101010101)) & ~(v) & UINT64_C(0x8080808080808080);
}

// Austin Appleby's MurmurHash, adapted from
// https://github.com/aappleby/smhasher
static uint64_t murmur_hash_64a(const void * key, int len, uint64_t seed) {
  const uint64_t m = 0xc6a4a7935bd1e995LLU;
  const int r = 47;

  uint64_t h = seed ^ (len * m);

  const uint64_t * data = (const uint64_t *)key;
  const uint64_t * end = data + (len/8);

  // FIXME use contains_zero_byte
  while(data != end)
  {
    uint64_t k = *data++;

    k *= m;
    k ^= k >> r;
    k *= m;

    h ^= k;
    h *= m;
  }

  const uint8_t * data2 = (const uint8_t *) data;

  switch(len & 7)
  {
  case 7: h ^= (uint64_t) data2[6] << 48;
  case 6: h ^= (uint64_t) data2[5] << 40;
  case 5: h ^= (uint64_t) data2[4] << 32;
  case 4: h ^= (uint64_t) data2[3] << 24;
  case 3: h ^= (uint64_t) data2[2] << 16;
  case 2: h ^= (uint64_t) data2[1] << 8;
  case 1: h ^= (uint64_t) data2[0];
          h *= m;
  };

  h ^= h >> r;
  h *= m;
  h ^= h >> r;

  return h;
}

void map_free(map_t *hm) {
  for(size_t bin = 0; bin < hm->bin_count; bin++) {
    map_item_t *items[THRESHOLD];
    size_t items_len = 0;
    for(map_item_t *item = &hm->bins[bin]; item != NULL; item = item->next) {
      // keep pointer to item so we can free it later
      items[items_len++] = item;

      // call custom free_key
      if(hm->free_key) {
        hm->free_key(item->key);
      }

      // call custom free_val
      if(hm->free_val) {
        hm->free_val(item->val);
      }

      // reset key and val
      item->key = NULL;
      item->val = NULL;
    }

    // don't free the first item — that wasn't individually malloc'ed
    for(size_t item = 1; item < items_len; item++) {
      free(items[item]);
    }
  }

  // free the bins array itself
  free(hm->bins);
}

void map_set_free(map_t *hm, map_free_fn *free_key, map_free_fn *free_val) {
  hm->free_key = free_key;
  hm->free_val = free_val;
}

void map_set_hash(map_t *hm, map_hash_fn *hash) {
  hm->hash = hash;
}

map_hash_t map_hash_str(const char *str) {
  // FIXME: check data length directly in the hashing function?
  return murmur_hash_64a(str, strlen(str), SEED);
}

map_hash_t map_hash_ptr(const void *ptr) {
  // FIXME adapt hashing function for pointer?
  return murmur_hash_64a(&ptr, sizeof(void *), SEED);
}

map_item_t *map_get_item(const map_t *m, const char *str) {
  // compute hash of string
  map_hash_t hash = map_hash_str(str);

  // map the hash to a bin
  size_t bin = hash % m->bin_count;

  // iterate through all items
  for(map_item_t *item = &m->bins[bin]; item != NULL; item = item->next) {
    if(item->hash == hash && 0 == strcmp(str, item->key)) {
      return item;
    }
  }

  return NULL;
}

void *map_get(const map_t *m, const char *str) {
  map_item_t *item = map_get_item(m, str);
  return item ? item->val : NULL;
}

bool map_has(const map_t *m, const char *str) {
  map_item_t *item = map_get_item(m, str);
  return item ? true : false;
}

bool map_set(map_t *m, const char *str, void *val) {
  map_item_t *item = map_get_item(m, str);

  if(!item) {
    return false;
  }

  // TODO free old key
  item->key = (void *) str;
  item->val = val;

  return true;
}


map_item_t *map_item_new(void *key, map_hash_t hash, void *val) {
  map_item_t *item = malloc(sizeof(map_item_t));

  item->next = NULL;
  item->hash = hash;
  item->val  = val;
  item->key  = key;

  return item;
}

// expands the number of bins
void map_bin_expand(map_t *m) {
  // TODO FIXME
}

bool map_add(map_t *m, const char *str, void *val) {
  // compute hash of string
  map_hash_t hash = map_hash_str(str);

  // map the hash to a bin
  size_t bin = hash % m->bin_count;

  // get relevant map item
  map_item_t *item = &m->bins[bin];

  if(item->next == NULL) {
    // when there are no items in the bin, the current can be overwritten.
    if(item->key == NULL) {
      item->hash = hash;
      item->key = (void *) str;
      item->val = val;
    } else {
      // when the key already exists in the map, return false.
      if(item->hash == hash && 0 == strcmp(str, item->key)) {
        return false;
      }

      // add item to the map_item list
      item->next = map_item_new((void *) str, hash, val);
    }
  } else {
    // okay, we have a map_item list that we need to traverse to find out the
    // size and if the key already exists.
    size_t item_list_len = 1;
    for(map_item_t *cur = item; cur != NULL; cur = cur->next) {
      item_list_len += 1;

      // when the key already exists, return false.
      if(cur->hash == hash && 0 == strcmp(str, cur->key)) {
        return false;
      }
    }

    // when the size is too big, expand
    if(item_list_len >= THRESHOLD) {
      map_bin_expand(m);
      return map_add(m, str, val);
    }

    // insert element at second position
    map_item_t *added = map_item_new((void *) str, hash, val);
    added->next = item->next;
    item->next = added;
  }

  m->elem_count += 1;
  return true;
}

size_t map_len(const map_t *hm) {
  return hm->elem_count;
}

bool map_del(map_t *m, const void *key) {
  map_item_t *item = map_get_item(m, key);

  if(!item) {
    return false;
  }

  // TODO: free key and val
  if(item->next) {
    map_item_t *next = item->next;
    *item = *next;
    free(next);
  } else {
    item->hash = 0;
    item->key = NULL;
    item->val = NULL;
  }

  return true;
}
