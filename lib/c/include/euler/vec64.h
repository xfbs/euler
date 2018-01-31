//! @file vec64.h
//! `uint64_t` vector data structure and associated functions.
#include <stddef.h>
#include <stdint.h>
#pragma once

//! @defgroup vec64 vec64
//! @brief data type and functions for handling vectors of `uint64_t`
//! @{

//! vector of uint64_t data type.
//!
//! @warning
//! this should not be used directly - use the associated vector functions to
//! mutate this.
typedef struct {
  //! pointer to the uint64_t array, this array has size `cap`.
  uint64_t *data;

  //! capacity of the `data` array of uint64_t.
  size_t cap;

  //! current length of the vector - how many `uint64_t` are stored in `data`.
  size_t len;
} vec64_t;

//! creates a new `vec64_t`.
//!
//! @param len length of the vec64
//! @param fill what the vec64 should initially be filled with
//! @return a `vec64_t` with the given length and filled with the given values.
//!
//! ## Examples
//!
//! creating a new empty uint64_t vector
//!
//! ```c
//! // creates an empty vec64
//! vec64_t vec = vec64_new(0, 0);
//!
//! vec64_free(&vec);
//! ```
//!
//! creating a pre-filled uint64_t vector
//!
//! ```c
//! // creates a pre-filled vec64
//! vec64_t vec = vec64_new(10, 99);
//!
//! assert(vec64_len(&vec) == 10);
//! assert(vec64_get(&vec, 0) == 99);
//! assert(vec64_get(&vec, 9) == 99);
//! vec64_free(&vec);
//! ```
vec64_t vec64_new(size_t len, uint64_t fill);

//! like `vec64_new()`, but allocates with `malloc`, used to get pointer.
//!
//! @param len initial length ov the `vec64_t`.
//! @param fill what it should be pre-filled with.
//! @return a pointer to a `malloc`-allocated `vec64_t`.
//! @warning
//! unlike `vec64_new()`, which just returns a `vec64_t` that you can keep on
//! the stack, this method returns a pointer to `malloc`'ed memory, which means
//! that in addition to calling `vec64_free()` to free the internals, you need
//! to call `free()` on the pointer itself after you're done using it.
//!
//! ## Examples
//! creating a new empty uint64_t vector
//!
//! ```c
//! // creates an empty vec64
//! vec64_t *vec = vec64_alloc(0, 0);
//!
//! vec64_free(vec);
//! free(vec);
//! ```
//!
//! creating a pre-filled uint64_t vector
//!
//! ```c
//! // creates a pre-filled vec64
//! vec64_t *vec = vec64_alloc(10, 99);
//!
//! assert(vec64_len(vec) == 10);
//! assert(vec64_get(vec, 0) == 99);
//! assert(vec64_get(vec, 9) == 99);
//! vec64_free(vec);
//! free(vec);
//! ```
vec64_t *vec64_alloc(size_t len, uint64_t fill);

//! `free()`'s the data held inside a `vec64_t`.
//!
//! @param v the vector that will have it's data released.
//! @warning
//! this function only releases the data held inside a `vec64_t`, not the
//! `vec64_t` itself. if the `vec64_t` has been produced by `vec64_alloc()`,
//! `free()` must also be called on it to release the structure itself.
//!
//! ## Examples
//!
//! freeing a vector on the stack
//!
//! ```c
//! // allocate vector on the stack
//! vec64_t vec = vec64_new(0, 0);
//!
//! // free vector contents
//! vec64_free(&vec);
//! ```
//!
//! freeing a vector on the heap
//!
//! ```c
//! // allocate new vector on the heap
//! vec64_t *vec = vec64_alloc(0, 0);
//!
//! // free vector contents
//! vec64_free(vec);
//!
//! // free vector itself
//! free(vec);
//! ```
void vec64_free(vec64_t *v);

//! gets an element of the `uint64_t` vector.
//!
//! @param v `uint64_t` vector on which to operate
//! @param pos which element to return
//! @return element at `pos`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! get elements from a pre-filled vec64
//!
//! ```c
//! // creates a pre-filled vec64
//! vec64_t vec = vec64_new(10, 99);
//!
//! // gets the first and last element
//! assert(vec64_get(&vec, 0) == 99);
//! assert(vec64_get(&vec, 9) == 99);
//! vec64_free(&vec);
//! ```
//!
//! get elements from a vec64 that has been `vec64_push()`ed to
//!
//! ```c
//! // creates a new empty vec64
//! vec64_t vec = vec64(0, 0);
//!
//! // push some data into it
//! vec64_push(&vec, 15);
//! vec64_push(&vec, 95);
//!
//! // check values
//! assert(vec64_get(&vec, 0) == 15);
//! assert(vec64_get(&vec, 1) == 95);
//! vec64_free(&vec);
//! ```
uint64_t vec64_get(const vec64_t *v, size_t pos);

//! sets the element at the specified position to `data`.
//!
//! @param v `uint64_t` vector to operate on
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
//! set elements in a pre-filled `vec64_t`
//!
//! ```c
//! // creates a pre-filled vec64
//! vec64_t vec = vec64_new(10, 99);
//!
//! // returns previous element
//! assert(vec64_set(&vec, 0, 15) == 99);
//!
//! // check if set worked
//! assert(vec64_get(&vec, 0) == 15);
//! vec64_free(&vec);
//! ```
//!
//! set elements in a `vec64_t` that has been pushed to
//!
//! ```c
//! // creates a new empty vec64
//! vec64_t vec = vec64(0, 0);
//!
//! // push some data into it
//! vec64_push(&vec, 15);
//! vec64_push(&vec, 95);
//!
//! // set new values
//! vec64_set(&vec, 0, 100);
//! vec64_set(&vec, 1, 200);
//!
//! // check values
//! assert(vec64_set(&vec, 0) == 100);
//! assert(vec64_get(&vec, 1) == 200);
//! vec64_free(&vec);
//! ```
uint64_t vec64_set(vec64_t *v, size_t pos, uint64_t data);

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
//! vec64_t vec = vec64_new(2, 0);
//!
//! // checks length
//! assert(vec64_len(&vec) == 2);
//! vec64_free(&vec);
//! ```
size_t vec64_len(const vec64_t *v);

//! push a value onto the end of the `uint64_t` vector.
//!
//! @param v vector to push onto
//! @param data `uint64_t` to push onto the end
//! @return new size of the vector
//! @note
//! if you know that you will push a large amount of data onto the vector, you
//! may want to call `vec64_reserve()` to make space for it.
//!
//! ## Examples
//!
//! push some data onto the end of an empty vector
//!
//! ```c
//! // creates a new empty vector
//! vec64_t vec = vec64_new(0, 0);
//!
//! // push some values onto the end
//! vec64_push(&vec, 77);
//! vec64_push(&vec, 99);
//!
//! // make sure the values are there
//! assert(vec64_len(&vec) == 2);
//! assert(vec64_get(&vec, 0) == 77);
//! assert(vec64_get(&vec, 1) == 99);
//! vec64_free(&vec);
//! ```
size_t vec64_push(vec64_t *v, uint64_t data);

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
//! vec64_t vec = vec64_new(0, 0);
//!
//! // reserve enough space
//! size_t data_size = 1000000;
//! vec64_reserve(&vec, data_size);
//!
//! // add data
//! for(size_t cur = 0; cur < data_size; cur++) {
//!   vec64_push(&vec, 9);
//! }
//!
//! vec64_free(&vec);
//! ```
void vec64_reserve(vec64_t *v, size_t size);

//! removes all the elements in a vector.
//!
//! @param v the vector to clear
//! @warning
//! internally, this resets the vector's size to 0, but it does not shrink the
//! array used to hold the data. if you want to shrink the container, you can
//! call `vec64_free()` on it and make a new vector with `vec64_new()`.
//!
//! ## Examples
//!
//! clear pre-initialized vector
//!
//! ```c
//! // allocate new pre-initialized vector
//! vec64_t vec = vec64_new(15, 9);
//!
//! // forget all elements in vector
//! vec64_clear(&vec);
//!
//! // check
//! assert(ve16_len(&vec) == 0);
//! vec64_free(&vec);
//! ```
void vec64_clear(vec64_t *v);

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
//! vec64_t vec = vec64_new(0, 0);
//!
//! // adds some data to vec
//! vec64_push(&vec, 16);
//! vec64_push(&vec, 19);
//! vec64_push(&vec, 23);
//!
//! // find index of some elements in vector
//! assert(vec64_index(&vec, 16) == 0);
//! assert(vec64_index(&vec, 19) == 1);
//! assert(vec64_index(&vec, 23) == 2);
//! assert(vec64_index(&vec, 20) == SIZE_MAX);
//! ```
size_t vec64_index(const vec64_t *v, uint64_t data);

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
//! vec64_t vec = vec64_new(10, 8);
//!
//! // add more values to vector
//! vec64_push(&vec, 77);
//! vec64_push(&vec, 10);
//!
//! // compute sum of elements
//! assert(vec64_sum(&vec) == 167);
//! ```
uint64_t vec64_sum(const vec64_t *v);

//! @}
