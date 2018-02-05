//! @file       map.h
//! @author     Patrick M. Elsen
//! @date       2018
//! @copyright  MIT license
//! @brief      hashmap data type
//! @detail     implements a hashmap in C.
//! @todo       which hashing function do we use?
//! @todo       do we store things in stack (maybe start with a bin size of 1?)
//! @todo       how do we generate primes for bin sizes?
//! @todo       how do we keep the key itself? -> ownership of string!
//! @todo       can we use some kind of cache to keep map_item_t to prevent
//!             having to reallocate?
//! @todo       use primal bin lengths?
#include <euler/common.h>
#pragma once

//! @defgroup map map Hashmap
//! @{

//! The type that hashes have.
typedef uint64_t map_hash_t;

//! Type of integers that can be stored as values in a hash.
typedef ptrdiff_t map_int_t;

//! Custom hashing function to use.
//!
//! Hash functions should be implemented in a way to not return 0.
typedef map_hash_t map_hash_fun(void *key);

//! Custom comparison function to use.
typedef int map_cmp_fun(void *lkey, void *rkey);

//! Custom `free()`ing function for keys or elements.
typedef void map_free_fun(void *data);

// forward declared here so that we can have it as recursive member.
struct map_item_t;

//! A map item descriptor.
typedef struct map_item_t {
  map_hash_t hash;
  void *key;
  void *val;
  struct map_item_t *next;
} map_item_t;

//! Hash map type.
typedef struct {
  //! How many elements the hash map contains.
  size_t elem_count;

  //! How many bins the hash map has.
  size_t bin_count;

  //! Function to call on a key after `map_del()`.
  map_free_fun *free_key;

  //! Function to call on a value after `map_del()`.
  map_free_fun *free_val;

  //! Custom hashing function to use.
  map_hash_fun *hash;

  //! Custom comparison function to use.
  map_cmp_fun *cmp;

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
void map_free(map_t *hm);

//! Sets custom functions for freeing elements.
//!
//! @param hm Hashmap to modify.
//! @param key_free Function to call to free keys
//! @param vel_free Function to call to free values.
//!
//! ## Examples
void map_set_free(map_t *hm, map_free_fun *key_free, map_free_fun *val_free);

//! Sets custom hasing function.
//!
//! @param hm Hashmap to modify.
//! @param hash_fun Custom hashing function to use.
//!
//! ## Examples
void map_set_hash(map_t *hm, map_hash_fun *hash_fun);

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
//! // check if string exists
//! assert(map_get(&hm, "key") == NULL);
//!
//! // release
//! map_free(&hm);
//! ```
void *map_get(map_t *m, const char *str);

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
//! assert(0 == strcmp("value", map_get(&hm, "key")));
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
bool map_has(map_t *m, const char *key);


// rem? del? unset?
#define map_rem(map, key) 0
#define map_len(map) 0

//! @}
