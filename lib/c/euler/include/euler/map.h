//! Hashmap data type, see @ref map.
//!
//! @file   map.h
//! @todo   which hashing function do we use?
//! @todo   do we store things in stack (maybe start with a bin size of 1?)
//! @todo   how do we generate primes for bin sizes?
//! @todo   how do we keep the key itself? -> ownership of string!
//! @todo   can we use some kind of cache to keep map_item_t to prevent
//!         having to reallocate?
//! @todo   use primal bin lengths?
#include <euler/common.h>
#pragma once

//! A hashmap data type.
//!
//! @defgroup map map
//! @{

//! The type that hashes have.
typedef uint64_t map_hash_t;

//! Custom hashing function.
typedef map_hash_t map_hash_fn(const void *key);

//! Custom comparison function.
typedef int map_cmp_fn(const void *lkey, const void *rkey);

//! Custom `free()`ing function for keys or elements.
typedef void map_free_fn(void *data);

// forward declared here so that we can have it as recursive member.
struct map_item_t;

//! A map item descriptor.
typedef struct map_item_t {
  //! Hash of the key, cached for faster comparison.
  map_hash_t hash;

  //! Key of this item.
  void *key;

  //! Value of this item.
  void *val;

  //! Next item, or `NULL` if end.
  struct map_item_t *next;
} map_item_t;

//! Hash map type.
typedef struct {
  //! How many elements the hash map contains.
  size_t elem_count;

  //! How many bins the hash map has.
  size_t bin_count;

  //! Function to call on a key after `map_del()`.
  map_free_fn *free_key;

  //! Function to call on a value after `map_del()`.
  map_free_fn *free_val;

  //! Custom hashing function to use.
  map_hash_fn *hash;

  //! Custom comparison function to use.
  map_cmp_fn *cmp;

  //! Bins of the hashmap.
  map_item_t *bins;
} map_t;

//! Creates a new hashmap.
//!
//! @return A new, initialized hashmap.
//!
//! ## Examples
//!
//! ```c
//! // make new hashmap
//! map_t hm = map_new();
//!
//! // add something to the hashmap
//! assert(map_add(&hm, "key", "val"));
//!
//! // check if adding worked
//! assert_eq(map_get(&hm, "key"), "val");
//!
//! // release
//! map_free(&hm);
//! ```
map_t map_new();

//! Frees a hashmap's bins, and depending on the `key_free` and `val_free`
//! parameters, also its keys and values.
//!
//! @param hm The hashmap to operate on.
//!
//! ## Examples
//!
//! Freeing a normal hashmap
//!
//! ```c
//! // make new hashmap
//! map_t hm = map_new();
//!
//! // add something to the hashmap
//! assert(map_add(&hm, "key", "val"));
//!
//! // check if adding worked
//! assert_eq(map_get(&hm, "key"), "val");
//!
//! // release
//! map_free(&hm);
//! ```
//!
//! Freeing a hashmap and all of it's keys
//!
//! ```c
//! // make new hashmap
//! map_t hm = map_new();
//!
//! // set the freeing function for values to be free()
//! map_set_free(&hm, NULL, free);
//!
//! // add something to the hashmap
//! assert(map_add(&hm, "key1", malloc(50)));
//! assert(map_add(&hm, "key2", malloc(100)));
//!
//! // release, calling free() on all values
//! map_free(&hm);
//! ```
void map_free(map_t *hm);

//! Sets custom functions for freeing elements.
//!
//! Passing `NULL` as one of `free_key` or `free_val` means that the hashmap
//! not call `free()` on the respective item when overwriting or `free()`ing.
//!
//! @param hm Hashmap to modify.
//! @param free_key Function to call to free keys
//! @param free_val Function to call to free values.
//!
//! ## Examples
//!
//! Storing `vec32_t` as values:
//!
//! ```c
//! // make new hashmap
//! map_t hm = map_new();
//!
//! // set the freeing function for values to be free()
//! map_set_free(&hm, NULL, vec32_free);
//!
//! // add something to the hashmap
//! assert(map_add(&hm, "twos", vec32_alloc(12, 2)));
//! assert(map_add(&hm, "ones", vec32_alloc(10, 1)));
//!
//! // overwrite an element of the hashmap. this will call vec32_free on the
//! // previous value.
//! assert(map_set(&hm, "ones", vec32_alloc(12, 1)));
//!
//! // check that both elements are correct
//! assert(vec32_len(map_get(&hm, "ones")) == 12);
//! assert(vec32_len(map_get(&hm, "twos")) == 12);
//!
//! // release, calling vec32_free on all values
//! map_free(&hm);
//! ```
void map_set_free(map_t *hm, map_free_fn *free_key, map_free_fn *free_val);

//! Sets custom hashing function.
//!
//! @param hm   Hashmap to modify.
//! @param hash Custom hashing function to use.
//! @todo example
void map_set_hash(map_t *hm, map_hash_fn *hash);

//! Computes the hash of a string.
//!
//! Default hashing function used to hash strings.
//!
//! @param str The string to hash.
//! @return A `map_hash_t` representing the hash of the string.
//! @warning This function expects `str` to be `NULL`-terminated!
//!
//! ## Examples
//!
//! ```c
//! assert(map_hash_str("abc") == map_hash_str("abc"));
//! assert(map_hash_str("some") != map_hash_str("other"));
//! ```
map_hash_t map_hash_str(const char *str);

//! Computes the hash of a pointer.
//!
//! This hashing function can be used to hash the pointers themselves. This
//! requires one to know the exact pointer to access an element.
//!
//! @param ptr The pointer to hash.
//! @return A `map_hash_t` representing the hash of the pointer.
//!
//! ## Examples
//!
//! ```c
//! int a, b;
//! assert(map_hash_ptr(&a) == map_hash_ptr(&a));
//! assert(map_hash_ptr(&a) != map_hash_ptr(&b));
//! ```
map_hash_t map_hash_ptr(const void *ptr);

//! Sets custom comparison function.
//!
//! @param hm   Hashmap to modify.
//! @param hash Custom comparison function to use.
//! @todo example
void map_set_cmp(map_t *hm, map_cmp_fn *cmp);

//! Compares two strings.
//!
//! Default comparison function used for strings.
//!
//! @param lhs String
//! @param rhs String
//! @return 0 if `lhs` and `rhs` are equal.
//!
//! ## Examples
//! FIXME
//! ```c
//! assert(map_hash_str("abc") == map_hash_str("abc"));
//! assert(map_hash_str("some") != map_hash_str("other"));
//! ```
int map_cmp_str(const void *lhs, const void *rhs);

//! Comparers two pointers for equality.
//!
//!
//! ## Examples
//!
//! FIXME
//! ```c
//! assert(map_hash_str("abc") == map_hash_str("abc"));
//! assert(map_hash_str("some") != map_hash_str("other"));
//! ```
int map_cmp_ptr(const void *lhs, const void *rhs);

//! Look up a string in the hashmap.
//!
//! @param m Hashmap to look string up in.
//! @param str String to look up in hashmap.
//! @return The element that the string points to, or `NULL` if not found.
//!
//! ## Examples
//!
//! ```c
//! // new hash map
//! map_t hm = map_new();
//!
//! // check that get will return NULL because the key doesn't exist.
//! assert(map_get(&hm, "key") == NULL);
//!
//! // add key to hashmap
//! assert(map_add(&hm, "key", (void *) 0x5656));
//! assert(map_get(&hm, "key") == (void *) 0x5656);
//!
//! // release
//! map_free(&hm);
//! ```
void *map_get(const map_t *m, const char *str);

//! Adds a mapping to the hashmap.
//!
//! @param m Hashmap to modify.
//! @param str Key
//! @param val Value
//! @return false if `str` is already a key in the Hashmap, true otherwise.
//!
//! ## Example
//!
//! ```c
//! // new hashmap
//! map_t hm = map_new();
//!
//! // adds an element
//! assert(map_add(&hm, "key", "value"));
//!
//! // checks that we can't add anything under the same key
//! assert(!map_add(&hm, "key", "other"));
//!
//! // checks that our mapping exists
//! assert_eq(map_get(&hm, "key"), "value");
//!
//! // release hashmap
//! map_free(&hm);
//! ```
bool map_add(map_t *m, const char *str, void *val);

//! Overwrites a value in the hashmap.
//!
//! If the hashmap has a `free_val` method, as set by `map_set_free()`, then
//! this method is called on the previous key.
//!
//! @param m Hashmap to modify
//! @param key Key to overwrite
//! @param val New value at the key
//!
//! ## Examples
//!
//! ```c
//! // new hashmap
//! map_t hm = map_new();
//!
//! // adds an element
//! assert(true == map_add(&hm, "key", "value"));
//!
//! // checks that the mapping exists
//! assert_eq("value", map_get(&hm, "key"));
//!
//! // overwrites mapping
//! assert(map_set(&hm, "key", "other"));
//!
//! // checks if overwriting worked
//! assert_eq("other", map_get(&hm, "key"));
//!
//! // release hashmap
//! map_free(&hm);
//! ```
bool map_set(map_t *m, const char *key, void *val);

//! Checks if a key exists in the hashmap.
//!
//! @param m The Hashmap to check
//! @param key The key to look for in the Hashmap.
//! @return `true` if the key exists, `false` otherwise.
//!
//! ## Examples
//!
//! ```c
//! // new hashmap
//! map_t hm = map_new();
//!
//! // nothing in there - yet
//! assert(!map_has(&hm, "key"));
//!
//! // add something
//! assert(map_add(&hm, "key", "value"));
//!
//! // now it exists
//! assert(map_has(&hm, "key"));
//!
//! // release
//! map_free(&hm);
//! ```
bool map_has(const map_t *m, const char *key);

//! Determines the amount of elements in the hashmap.
//!
//! @param m Hashmap to return the count of elements from.
//! @return The amount of elements in `m`.
//!
//! ## Examples
//!
//! ```c
//! // new hashmap
//! map_t hm = map_new();
//!
//! // initially empty
//! assert(map_len(&hm) == 0);
//!
//! // add elements and check len
//! assert(map_add(&hm, "key1", "val1"));
//! assert(map_len(&hm) == 1);
//! assert(map_add(&hm, "key2", "val2"));
//! assert(map_len(&hm) == 2);
//! assert(map_add(&hm, "key3", "val3"));
//! assert(map_len(&hm) == 3);
//!
//! // release
//! map_free(&hm);
//! ```
size_t map_len(const map_t *m);

//! Removes an element from the Hashmap.
//!
//! Looks up `key` in the hash map. When found, deletes it and the associated
//! element from the hashmap, returning `true`. When not found, returns `false`.
//!
//! @param m Hashmap to mutate
//! @param key Key to look up and delete.
//! @return `true` if `key` is a valid key and it was deleted, `false`
//!   otherwise.
//!
//! ## Examples
//!
//! ```c
//! // new hashmap
//! map_t hm = map_new();
//!
//! // try to delete nonexisting element
//! assert(!map_del(&hm, "key"));
//!
//! // add element
//! assert(map_add(&hm, "key", "value"));
//!
//! // delete element
//! assert(map_del(&hm, "key"));
//!
//! // show that element is gone
//! assert(!map_has(&hm, "key"));
//!
//! // release
//! map_free(&hm);
//! ```
bool map_del(map_t *m, const void *key);

//! For loop over a hashmap.
//!
//! Using this macro, it is easy to loop over the items (keys and values) in a
//! hashmap.
//!
//! @param m The hashmap to iterate over.
//! @param item The name of the variable to hold a `map_item_t *`.
//!
//! ## Examples
//!
//! ```c
//! // new hashmap
//! map_t hm = map_new();
//!
//! // add some data to hashmap
//! assert(map_add(&hm, "one", (void *) 1));
//! assert(map_add(&hm, "two", (void *) 2));
//! assert(map_add(&hm, "three", (void *) 3));
//!
//! // count and sum up values
//! size_t count = 0;
//! size_t sum = 0;
//! map_foreach(&hm, item) {
//!   count += 1;
//!   sum += (size_t) item->val;
//! }
//!
//! // check results
//! assert(count == 3);
//! assert(sum == 6);
//!
//! // release
//! map_free(&hm);
//! ```
#define map_foreach(m, item)                                                   \
  for(size_t _bin_pos = 0; _bin_pos < (m)->bin_count; _bin_pos++)                \
    for(map_item_t *item = &(m)->bins[_bin_pos]; item != NULL; item = item->next)

//! @}
