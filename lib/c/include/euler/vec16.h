//! @file vec16.h
//! `uint16_t` vector data structure and associated functions.
#include <stddef.h>
#include <stdint.h>
#pragma once

//! @defgroup vec16 vec16
//! @brief data type and functions for handling vectors of `uint16_t`
//! @{

//! vector of uint16_t data type.
//!
//! @warning
//! this should not be used directly - use the associated vector functions to
//! mutate this.
typedef struct {
  //! pointer to the uint16_t array, this array has size `cap`.
  uint16_t *data;

  //! capacity of the `data` array of uint16_t.
  size_t cap;

  //! current length of the vector - how many `uint16_t` are stored in `data`.
  size_t len;
} vec16_t;

//! creates a new `vec16_t`.
//!
//! @param len length of the vec16
//! @param fill what the vec16 should initially be filled with
//! @return a `vec16_t` with the given length and filled with the given values.
//!
//! ## Examples
//!
//! creating a new empty uint16_t vector
//!
//! ```c
//! // creates an empty vec16
//! vec16_t vec = vec16_new(0, 0);
//!
//! vec16_free(&vec);
//! ```
//!
//! creating a pre-filled uint16_t vector
//!
//! ```c
//! // creates a pre-filled vec16
//! vec16_t vec = vec16_new(10, 99);
//!
//! assert(vec16_len(&vec) == 10);
//! assert(vec16_get(&vec, 0) == 99);
//! assert(vec16_get(&vec, 9) == 99);
//! vec16_free(&vec);
//! ```
vec16_t vec16_new(size_t len, uint16_t fill);

//! like `vec16_new()`, but allocates with `malloc`, used to get pointer.
//!
//! @param len initial length ov the `vec16_t`.
//! @param fill what it should be pre-filled with.
//! @return a pointer to a `malloc`-allocated `vec16_t`.
//! @warning
//! unlike `vec16_new()`, which just returns a `vec16_t` that you can keep on
//! the stack, this method returns a pointer to `malloc`'ed memory, which means
//! that in addition to calling `vec16_free()` to free the internals, you need
//! to call `free()` on the pointer itself after you're done using it.
//!
//! ## Examples
//! creating a new empty uint16_t vector
//!
//! ```c
//! // creates an empty vec16
//! vec16_t *vec = vec16_alloc(0, 0);
//!
//! vec16_free(vec);
//! free(vec);
//! ```
//!
//! creating a pre-filled uint16_t vector
//!
//! ```c
//! // creates a pre-filled vec16
//! vec16_t *vec = vec16_alloc(10, 99);
//!
//! assert(vec16_len(vec) == 10);
//! assert(vec16_get(vec, 0) == 99);
//! assert(vec16_get(vec, 9) == 99);
//! vec16_free(vec);
//! free(vec);
//! ```
vec16_t *vec16_alloc(size_t len, uint16_t fill);

//! `free()`'s the data held inside a `vec16_t`.
//!
//! @param v the vector that will have it's data released.
//! @warning
//! this function only releases the data held inside a `vec16_t`, not the
//! `vec16_t` itself. if the `vec16_t` has been produced by `vec16_alloc()`,
//! `free()` must also be called on it to release the structure itself.
//!
//! ## Examples
//!
//! freeing a vector on the stack
//!
//! ```c
//! // allocate vector on the stack
//! vec16_t vec = vec16_new(0, 0);
//!
//! // free vector contents
//! vec16_free(&vec);
//! ```
//!
//! freeing a vector on the heap
//!
//! ```c
//! // allocate new vector on the heap
//! vec16_t *vec = vec16_alloc(0, 0);
//!
//! // free vector contents
//! vec16_free(vec);
//!
//! // free vector itself
//! free(vec);
//! ```
void vec16_free(vec16_t *v);

//! gets an element of the `uint16_t` vector.
//!
//! @param v `uint16_t` vector on which to operate
//! @param pos which element to return
//! @return element at `pos`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! get elements from a pre-filled vec16
//!
//! ```c
//! // creates a pre-filled vec16
//! vec16_t vec = vec16_new(10, 99);
//!
//! // gets the first and last element
//! assert(vec16_get(&vec, 0) == 99);
//! assert(vec16_get(&vec, 9) == 99);
//! vec16_free(&vec);
//! ```
//!
//! get elements from a vec16 that has been `vec16_push()`ed to
//!
//! ```c
//! // creates a new empty vec16
//! vec16_t vec = vec16(0, 0);
//!
//! // push some data into it
//! vec16_push(&vec, 15);
//! vec16_push(&vec, 95);
//!
//! // check values
//! assert(vec16_get(&vec, 0) == 15);
//! assert(vec16_get(&vec, 1) == 95);
//! vec16_free(&vec);
//! ```
uint16_t vec16_get(const vec16_t *v, size_t pos);

//! sets the element at the specified position to `data`.
//!
//! @param v `uint16_t` vector to operate on
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
//! set elements in a pre-filled `vec16_t`
//!
//! ```c
//! // creates a pre-filled vec16
//! vec16_t vec = vec16_new(10, 99);
//!
//! // returns previous element
//! assert(vec16_set(&vec, 0, 15) == 99);
//!
//! // check if set worked
//! assert(vec16_get(&vec, 0) == 15);
//! vec16_free(&vec);
//! ```
//!
//! set elements in a `vec16_t` that has been pushed to
//!
//! ```c
//! // creates a new empty vec16
//! vec16_t vec = vec16(0, 0);
//!
//! // push some data into it
//! vec16_push(&vec, 15);
//! vec16_push(&vec, 95);
//!
//! // set new values
//! vec16_set(&vec, 0, 100);
//! vec16_set(&vec, 1, 200);
//!
//! // check values
//! assert(vec16_set(&vec, 0) == 100);
//! assert(vec16_get(&vec, 1) == 200);
//! vec16_free(&vec);
//! ```
uint16_t vec16_set(vec16_t *v, size_t pos, uint16_t data);

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
//! vec16_t vec = vec16_new(2, 0);
//!
//! // checks length
//! assert(vec16_len(&vec) == 2);
//! vec16_free(&vec);
//! ```
size_t vec16_len(const vec16_t *v);

//! push a value onto the end of the `uint16_t` vector.
//!
//! @param v vector to push onto
//! @param data `uint16_t` to push onto the end
//! @return new size of the vector
//! @note
//! if you know that you will push a large amount of data onto the vector, you
//! may want to call `vec16_reserve()` to make space for it.
//!
//! ## Examples
//!
//! push some data onto the end of an empty vector
//!
//! ```c
//! // creates a new empty vector
//! vec16_t vec = vec16_new(0, 0);
//!
//! // push some values onto the end
//! vec16_push(&vec, 77);
//! vec16_push(&vec, 99);
//!
//! // make sure the values are there
//! assert(vec16_len(&vec) == 2);
//! assert(vec16_get(&vec, 0) == 77);
//! assert(vec16_get(&vec, 1) == 99);
//! vec16_free(&vec);
//! ```
size_t vec16_push(vec16_t *v, uint16_t data);

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
//! vec16_t vec = vec16_new(0, 0);
//!
//! // reserve enough space
//! size_t data_size = 1000000;
//! vec16_reserve(&vec, data_size);
//!
//! // add data
//! for(size_t cur = 0; cur < data_size; cur++) {
//!   vec16_push(&vec, 9);
//! }
//!
//! vec16_free(&vec);
//! ```
void vec16_reserve(vec16_t *v, size_t size);

//! removes all the elements in a vector.
//!
//! @param v the vector to clear
//! @warning
//! internally, this resets the vector's size to 0, but it does not shrink the
//! array used to hold the data. if you want to shrink the container, you can
//! call `vec16_free()` on it and make a new vector with `vec16_new()`.
//!
//! ## Examples
//!
//! clear pre-initialized vector
//!
//! ```c
//! // allocate new pre-initialized vector
//! vec16_t vec = vec16_new(15, 9);
//!
//! // forget all elements in vector
//! vec16_clear(&vec);
//!
//! // check
//! assert(ve16_len(&vec) == 0);
//! vec16_free(&vec);
//! ```
void vec16_clear(vec16_t *v);

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
//! vec16_t vec = vec16_new(0, 0);
//!
//! // adds some data to vec
//! vec16_push(&vec, 16);
//! vec16_push(&vec, 19);
//! vec16_push(&vec, 23);
//!
//! // find index of some elements in vector
//! assert(vec16_index(&vec, 16) == 0);
//! assert(vec16_index(&vec, 19) == 1);
//! assert(vec16_index(&vec, 23) == 2);
//! assert(vec16_index(&vec, 20) == SIZE_MAX);
//! ```
size_t vec16_index(const vec16_t *v, uint16_t data);

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
//! vec16_t vec = vec16_new(10, 8);
//!
//! // add more values to vector
//! vec16_push(&vec, 77);
//! vec16_push(&vec, 10);
//!
//! // compute sum of elements
//! assert(vec16_sum(&vec) == 167);
//! ```
uint64_t vec16_sum(const vec16_t *v);

//! @}
