//! @file vec32.h
//! `uint32_t` vector data structure and associated functions.
#include <stddef.h>
#include <stdint.h>
#pragma once

//! @defgroup vec32 vec32
//! @brief data type and functions for handling vectors of `uint32_t`
//! @{

//! vector of uint32_t data type.
//!
//! @warning
//! this should not be used directly - use the associated vector functions to
//! mutate this.
typedef struct {
  //! pointer to the uint32_t array, this array has size `cap`.
  uint32_t *data;

  //! capacity of the `data` array of uint32_t.
  size_t cap;

  //! current length of the vector - how many `uint32_t` are stored in `data`.
  size_t len;
} vec32_t;

//! Comparison function between two elements.
//!
//! Functions that have this type can be used as sorting functions with
//! `vec32_sort()`, or as comparison functions for `vec32_bsearch()`. Functions
//! are expected to behave in the same way as comparison functions for the
//! `qsort()` function of the standard library.
typedef int (*vec32_cmp)(const void *, const void *);

//! creates a new `vec32_t`.
//!
//! @param len length of the vec32
//! @param fill what the vec32 should initially be filled with
//! @return a `vec32_t` with the given length and filled with the given values.
//!
//! ## Examples
//!
//! creating a new empty uint32_t vector
//!
//! ```c
//! // creates an empty vec32
//! vec32_t vec = vec32_new(0, 0);
//!
//! vec32_free(&vec);
//! ```
//!
//! creating a pre-filled uint32_t vector
//!
//! ```c
//! // creates a pre-filled vec32
//! vec32_t vec = vec32_new(10, 99);
//!
//! assert(vec32_len(&vec) == 10);
//! assert(vec32_get(&vec, 0) == 99);
//! assert(vec32_get(&vec, 9) == 99);
//! vec32_free(&vec);
//! ```
vec32_t vec32_new(size_t len, uint32_t fill);

//! like `vec32_new()`, but allocates with `malloc`, used to get pointer.
//!
//! @param len initial length ov the `vec32_t`.
//! @param fill what it should be pre-filled with.
//! @return a pointer to a `malloc`-allocated `vec32_t`.
//! @warning
//! unlike `vec32_new()`, which just returns a `vec32_t` that you can keep on
//! the stack, this method returns a pointer to `malloc`'ed memory, which means
//! that in addition to calling `vec32_free()` to free the internals, you need
//! to call `free()` on the pointer itself after you're done using it.
//!
//! ## Examples
//! creating a new empty uint32_t vector
//!
//! ```c
//! // creates an empty vec32
//! vec32_t *vec = vec32_alloc(0, 0);
//!
//! vec32_free(vec);
//! free(vec);
//! ```
//!
//! creating a pre-filled uint32_t vector
//!
//! ```c
//! // creates a pre-filled vec32
//! vec32_t *vec = vec32_alloc(10, 99);
//!
//! assert(vec32_len(vec) == 10);
//! assert(vec32_get(vec, 0) == 99);
//! assert(vec32_get(vec, 9) == 99);
//! vec32_free(vec);
//! free(vec);
//! ```
vec32_t *vec32_alloc(size_t len, uint32_t fill);

//! `free()`'s the data held inside a `vec32_t`.
//!
//! @param v the vector that will have it's data released.
//! @warning
//! this function only releases the data held inside a `vec32_t`, not the
//! `vec32_t` itself. if the `vec32_t` has been produced by `vec32_alloc()`,
//! `free()` must also be called on it to release the structure itself.
//!
//! ## Examples
//!
//! freeing a vector on the stack
//!
//! ```c
//! // allocate vector on the stack
//! vec32_t vec = vec32_new(0, 0);
//!
//! // free vector contents
//! vec32_free(&vec);
//! ```
//!
//! freeing a vector on the heap
//!
//! ```c
//! // allocate new vector on the heap
//! vec32_t *vec = vec32_alloc(0, 0);
//!
//! // free vector contents
//! vec32_free(vec);
//!
//! // free vector itself
//! free(vec);
//! ```
void vec32_free(vec32_t *v);

//! gets an element of the `uint32_t` vector.
//!
//! @param v `uint32_t` vector on which to operate
//! @param pos which element to return
//! @return element at `pos`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! get elements from a pre-filled vec32
//!
//! ```c
//! // creates a pre-filled vec32
//! vec32_t vec = vec32_new(10, 99);
//!
//! // gets the first and last element
//! assert(vec32_get(&vec, 0) == 99);
//! assert(vec32_get(&vec, 9) == 99);
//! vec32_free(&vec);
//! ```
//!
//! get elements from a vec32 that has been `vec32_push()`ed to
//!
//! ```c
//! // creates a new empty vec32
//! vec32_t vec = vec32_new(0, 0);
//!
//! // push some data into it
//! vec32_push(&vec, 15);
//! vec32_push(&vec, 95);
//!
//! // check values
//! assert(vec32_get(&vec, 0) == 15);
//! assert(vec32_get(&vec, 1) == 95);
//! vec32_free(&vec);
//! ```
uint32_t vec32_get(const vec32_t *v, size_t pos);

//! sets the element at the specified position to `data`.
//!
//! @param v `uint32_t` vector to operate on
//! @param pos which element to overwrite
//! @param data new data for the position
//! @return previous value at `pos`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! set elements in a pre-filled `vec32_t`
//!
//! ```c
//! // creates a pre-filled vec32
//! vec32_t vec = vec32_new(10, 99);
//!
//! // returns previous element
//! assert(vec32_set(&vec, 0, 15) == 99);
//!
//! // check if set worked
//! assert(vec32_get(&vec, 0) == 15);
//! vec32_free(&vec);
//! ```
//!
//! set elements in a `vec32_t` that has been pushed to
//!
//! ```c
//! // creates a new empty vec32
//! vec32_t vec = vec32_new(0, 0);
//!
//! // push some data into it
//! vec32_push(&vec, 15);
//! vec32_push(&vec, 95);
//!
//! // set new values
//! vec32_set(&vec, 0, 100);
//! vec32_set(&vec, 1, 200);
//!
//! // check values
//! assert(vec32_get(&vec, 0) == 100);
//! assert(vec32_get(&vec, 1) == 200);
//! vec32_free(&vec);
//! ```
uint32_t vec32_set(vec32_t *v, size_t pos, uint32_t data);

//! get the length of a vector.
//!
//! @param v vector to get length of
//! @return length of `v`
//!
//! ## Examples
//!
//! get length of pre-filled vector
//!
//! ```c
//! // creates a vec with length 2
//! vec32_t vec = vec32_new(2, 0);
//!
//! // checks length
//! assert(vec32_len(&vec) == 2);
//! vec32_free(&vec);
//! ```
size_t vec32_len(const vec32_t *v);

//! push a value onto the end of the `uint32_t` vector.
//!
//! @param v vector to push onto
//! @param data `uint32_t` to push onto the end
//! @return new size of the vector
//! @note
//! if you know that you will push a large amount of data onto the vector, you
//! may want to call `vec32_reserve()` to make space for it.
//!
//! ## Examples
//!
//! push some data onto the end of an empty vector
//!
//! ```c
//! // creates a new empty vector
//! vec32_t vec = vec32_new(0, 0);
//!
//! // push some values onto the end
//! vec32_push(&vec, 77);
//! vec32_push(&vec, 99);
//!
//! // make sure the values are there
//! assert(vec32_len(&vec) == 2);
//! assert(vec32_get(&vec, 0) == 77);
//! assert(vec32_get(&vec, 1) == 99);
//! vec32_free(&vec);
//! ```
size_t vec32_push(vec32_t *v, uint32_t data);

//! reserves the given amount of space for adding new elements.
//!
//! @param v the vector to reserve space for
//! @param size how much additional space to reserve
//!
//! when adding large amount of data to a vector, and when the size of the data
//! is known in advance, this method can be used to reserve space for the data
//! to add to prevent multiple reallocations of the data.
//!
//! ## Examples
//!
//! reserves some space in vector to add large amounts of data.
//!
//! ```c
//! vec32_t vec = vec32_new(0, 0);
//!
//! // reserve enough space
//! size_t data_size = 1000000;
//! vec32_reserve(&vec, data_size);
//!
//! // add data
//! for(size_t cur = 0; cur < data_size; cur++) {
//!   vec32_push(&vec, 9);
//! }
//!
//! vec32_free(&vec);
//! ```
void vec32_reserve(vec32_t *v, size_t size);

//! removes all the elements in a vector.
//!
//! @param v the vector to clear
//! @warning
//! internally, this resets the vector's size to 0, but it does not shrink the
//! array used to hold the data. if you want to shrink the container, you can
//! call `vec32_free()` on it and make a new vector with `vec32_new()`.
//!
//! ## Examples
//!
//! clear pre-initialized vector
//!
//! ```c
//! // allocate new pre-initialized vector
//! vec32_t vec = vec32_new(15, 9);
//!
//! // forget all elements in vector
//! vec32_clear(&vec);
//!
//! // check
//! assert(vec32_len(&vec) == 0);
//! vec32_free(&vec);
//! ```
void vec32_clear(vec32_t *v);

//! perform reverse lookup on vector
//!
//! @param v vector to perform lookup in
//! @param data element to look up
//! @return index of `data` in `v`, or `SIZE_MAX` if `data` does not exist in
//! `v`.
//!
//! for a given vector `v` and element `data`, searches the vector for
//! occurences of `data`, returning the index of the first occurence or
//! `SIZE_MAX` to indicate that the element does not exist.
//!
//! ## Examples
//!
//! ```c
//! // allocates new vector
//! vec32_t vec = vec32_new(0, 0);
//!
//! // adds some data to vec
//! vec32_push(&vec, 16);
//! vec32_push(&vec, 19);
//! vec32_push(&vec, 23);
//!
//! // find index of some elements in vector
//! assert(vec32_index(&vec, 16) == 0);
//! assert(vec32_index(&vec, 19) == 1);
//! assert(vec32_index(&vec, 23) == 2);
//! assert(vec32_index(&vec, 20) == SIZE_MAX);
//! ```
size_t vec32_index(const vec32_t *v, uint32_t data);

//! Perform a linear search on the vector.
//!
//! @param v vector to search
//! @param data data to search for
//! @param cmp comparison function between elements and data
//! @return an index to the found element, or `SIZE_MAX`
//!
//! This function performs a linear search on the vector, meaning that it will
//! traverse it in order and compare all elements to `data` using `cmp`, a
//! comparison function supplied by the user. Returns the index of the first
//! element for which the comparison function indicates that the elements are
//! equal.
//!
//! If `NULL` is passed as `cmp`, then the built-in comparison function is used,
//! which assumes that `data` is a pointer to `uint32_t`, and compares each
//! element with that.
//!
//! ## Examples
//!
//! @todo
size_t vec32_lsearch(const vec32_t *v, void *data, vec32_cmp cmp);

//! Perform a binary search on the vector.
//!
//! @param v vector to search
//! @param data data to search for
//! @param cmp comparison function between elements and data
//! @return an index to the found element, or `SIZE_MAX`
//!
//! This function performs a binary search on the sorted vector using `cmp`
//! as a comparison function. Note that if the vector is not sorted, this
//! function will not work, then you must use `vec32_lsearch()`.
//!
//! It returns an index to an element that is equal to `data`.
//!
//! If `NULL` is passed as `cmp`, then the built-in comparison function is used,
//! which assumes that `data` is a pointer to `uint32_t`, and compares each
//! element with that.
//!
//! ## Examples
//!
//! Find an element in a sorted vector.
//!
//! ```c
//! // new empty vector
//! vec32_t vec = vec32_new(0, 0);
//!
//! // adds some data to it
//! vec32_push(&vec, 9);
//! vec32_push(&vec, 5);
//! vec32_push(&vec, 14);
//! vec32_push(&vec, 1);
//!
//! // sort vector
//! vec32_sort(&vec, NULL);
//!
//! // bsearch only works for sorted vectors, so sort it
//! assert(vec32_get(&vec, 0) == 1);
//! assert(vec32_get(&vec, 1) == 5);
//! assert(vec32_get(&vec, 2) == 9);
//! assert(vec32_get(&vec, 3) == 14);
//!
//! // find '9'
//! uint32_t target = 9;
//! assert(vec32_bsearch(&vec, &target, NULL) == 2);
//!
//! // find an element that doesn't exist
//! target = 0;
//! assert(vec32_bsearch(&vec, &target, NULL) == SIZE_MAX);
//!
//! // release
//! vec32_free(&vec);
//! ```
size_t vec32_bsearch(const vec32_t *v, void *data, vec32_cmp cmp);

//! Sort the vector.
//!
//! Sorts the vector in-place using the provided comparison function. If `NULL`
//! is passed as comparison function, then falls back to a built-in comparison
//! function that sorts the numbers.
//!
//! @param v vector to sort.
//! @param cmp comparison function between elements.
//!
//! ## Examples
//!
//! ```c
//! // new empty vector
//! vec32_t vec = vec32_new(0, 0);
//!
//! // adds some data to it
//! vec32_push(&vec, 9);
//! vec32_push(&vec, 5);
//! vec32_push(&vec, 14);
//! vec32_push(&vec, 1);
//!
//! // sort vector
//! vec32_sort(&vec, NULL);
//!
//! // check that it's sorted
//! assert(vec32_get(&vec, 0) == 1);
//! assert(vec32_get(&vec, 1) == 5);
//! assert(vec32_get(&vec, 2) == 9);
//! assert(vec32_get(&vec, 3) == 14);
//!
//! // release
//! vec32_free(&vec);
//! ```
void vec32_sort(vec32_t *v, vec32_cmp cmp);

//! computes the sum of the vector.
//!
//! @param v vector with numbers
//! @return sum of all elements in `v`
//!
//! ## Examples
//!
//! compute sum of some numbers
//!
//! ```c
//! // allocate new pre-initialized vector
//! vec32_t vec = vec32_new(10, 8);
//!
//! // add more values to vector
//! vec32_push(&vec, 77);
//! vec32_push(&vec, 10);
//!
//! // compute sum of elements
//! assert(vec32_sum(&vec) == 167);
//! ```
uint64_t vec32_sum(const vec32_t *v);

//! @}
