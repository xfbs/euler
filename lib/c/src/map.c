#include <euler/map.h>
#include <stdlib.h>
#include <string.h>

static const size_t THRESHOLD = 5;

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
    .bin_count  = 1,
    .free_key   = NULL,
    .free_val   = NULL,
    .hash       = NULL,
    .cmp        = NULL,
    .bins       = calloc(1, sizeof(map_item_t))
  };

  return hm;
}

void map_free(map_t *hm) {
  if(hm->free_key) {
    // map_each_key(hm->key_free);
  }

  if(hm->free_val) {
    // map_each_key(hm->val_free);
  }

  if(hm->bins) {
    // delete bins
  }
}

void map_set_free(map_t *hm, map_free_fun *key_free, map_free_fun *val_free) {
  hm->free_key = key_free;
  hm->free_key = val_free;
}

void map_set_hash(map_t *hm, map_hash_fun *hash_fun) {
  hm->hash = hash_fun;
}

map_hash_t map_hash_str(const char *str) {
  // FIXME TODO
  uint64_t hash = str[0];
  return hash;
}

void *map_get(map_t *m, const char *str) {
  // compute hash of string
  map_hash_t hash = map_hash_str(str);

  // map the hash to a bin
  size_t bin = hash % m->bin_count;

  // get relevant map item
  map_item_t *item = &m->bins[bin];

  // iterate through all items
  for(map_item_t *item = &m->bins[bin]; item != NULL; item = item->next) {
    if(item->hash == hash && 0 == strcmp(str, item->key)) {
      return item->val;
    }
  }

  return NULL;
}

bool map_set(map_t *m, const char *str, void *val) {
  // compute hash of string
  map_hash_t hash = map_hash_str(str);

  // map the hash to a bin
  size_t bin = hash % m->bin_count;

  // get relevant map item
  map_item_t *item;

  // iterate through all items
  for(item = &m->bins[bin]; item != NULL; item = item->next) {
    if(item->hash == hash && 0 == strcmp(str, item->key)) {
      break;
    }
  }

  if(!item) {
    return false;
  }

  // TODO free old key
  item->key = str;
  item->val = val;

  return true;
}

bool map_has(map_t *m, const char *str) {
  // compute hash of string
  map_hash_t hash = map_hash_str(str);

  // map the hash to a bin
  size_t bin = hash % m->bin_count;

  // get relevant map item
  map_item_t *item = &m->bins[bin];

  // iterate through all items
  for(map_item_t *item = &m->bins[bin]; item != NULL; item = item->next) {
    if(item->hash == hash && 0 == strcmp(str, item->key)) {
      return true;
    }
  }

  return false;
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

  return true;
}
