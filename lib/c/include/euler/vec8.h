//! @file vec8.h
//! `uint8_t` vector data structure and associated functions.
#include <stddef.h>
#include <stdint.h>
#pragma once

//! @defgroup vec8 uint8_t vector functions
//! @{

//! vector of uint8_t data type.
//!
//! @warning
//! this should not be used directly - use the associated vector functions to
//! mutate this.
typedef struct {
  //! pointer to the uint8_t array, this array has size `cap`.
  uint8_t *data;

  //! capacity of the `data` array of uint8_t.
  size_t cap;

  //! current length of the vector - how many `uint8_t` are stored in `data`.
  size_t len;
} vec8_t;

//! creates a new `vec8_t`.
//!
//! @param len length of the vec8
//! @param fill what the vec8 should initially be filled with
//! @return a `vec8_t` with the given length and filled with the given values.
//!
//! ## Examples
//!
//! creating a new empty uint8_t vector
//!
//! ```c
//! // creates an empty vec8
//! vec8_t vec = vec8_new(0, 0);
//!
//! vec8_free(&vec);
//! ```
//!
//! creating a pre-filled uint8_t vector
//!
//! ```c
//! // creates a pre-filled vec8
//! vec8_t vec = vec8_new(10, 99);
//!
//! assert(vec8_len(&vec) == 10);
//! assert(vec8_get(&vec, 0) == 99);
//! assert(vec8_get(&vec, 9) == 99);
//! vec8_free(&vec);
//! ```
vec8_t vec8_new(size_t len, uint8_t fill);

//! like `vec8_new()`, but allocates with `malloc`, used to get pointer.
//!
//! @param len initial length ov the `vec8_t`.
//! @param fill what it should be pre-filled with.
//! @return a pointer to a `malloc`-allocated `vec8_t`.
//! @warning
//! unlike `vec8_new()`, which just returns a `vec8_t` that you can keep on
//! the stack, this method returns a pointer to `malloc`'ed memory, which means
//! that in addition to calling `vec8_free()` to free the internals, you need
//! to call `free()` on the pointer itself after you're done using it.
//!
//! ## Examples
//! creating a new empty uint8_t vector
//!
//! ```c
//! // creates an empty vec8
//! vec8_t *vec = vec8_alloc(0, 0);
//!
//! vec8_free(vec);
//! free(vec);
//! ```
//!
//! creating a pre-filled uint8_t vector
//!
//! ```c
//! // creates a pre-filled vec8
//! vec8_t *vec = vec8_alloc(10, 99);
//!
//! assert(vec8_len(vec) == 10);
//! assert(vec8_get(vec, 0) == 99);
//! assert(vec8_get(vec, 9) == 99);
//! vec8_free(vec);
//! free(vec);
//! ```
vec8_t *vec8_alloc(size_t len, uint8_t fill);

//! `free()`'s the data held inside a `vec8_t`.
//!
//! @param v the vector that will have it's data released.
//! @warning
//! this function only releases the data held inside a `vec8_t`, not the
//! `vec8_t` itself. if the `vec8_t` has been produced by `vec8_alloc()`,
//! `free()` must also be called on it to release the structure itself.
//!
//! ## Examples
//!
//! freeing a vector on the stack
//!
//! ```c
//! // allocate vector on the stack
//! vec8_t vec = vec8_new(0, 0);
//!
//! // free vector contents
//! vec8_free(&vec);
//! ```
//!
//! freeing a vector on the heap
//!
//! ```c
//! // allocate new vector on the heap
//! vec8_t *vec = vec8_alloc(0, 0);
//!
//! // free vector contents
//! vec8_free(vec);
//!
//! // free vector itself
//! free(vec);
//! ```
void vec8_free(vec8_t *v);

//! gets an element of the `uint8_t` vector.
//!
//! @param v `uint8_t` vector on which to operate
//! @param pos which element to return
//! @return element at `pos`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! get elements from a pre-filled vec8
//!
//! ```c
//! // creates a pre-filled vec8
//! vec8_t vec = vec8_new(10, 99);
//!
//! // gets the first and last element
//! assert(vec8_get(&vec, 0) == 99);
//! assert(vec8_get(&vec, 9) == 99);
//! vec8_free(&vec);
//! ```
//!
//! get elements from a vec8 that has been `vec8_push()`ed to
//!
//! ```c
//! // creates a new empty vec8
//! vec8_t vec = vec8(0, 0);
//!
//! // push some data into it
//! vec8_push(&vec, 15);
//! vec8_push(&vec, 95);
//!
//! // check values
//! assert(vec8_get(&vec, 0) == 15);
//! assert(vec8_get(&vec, 1) == 95);
//! vec8_free(&vec);
//! ```
uint8_t vec8_get(const vec8_t *v, size_t pos);

//! sets the element at the specified position to `data`.
//!
//! @param v `uint8_t` vector to operate on
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
//! set elements in a pre-filled `vec8_t`
//!
//! ```c
//! // creates a pre-filled vec8
//! vec8_t vec = vec8_new(10, 99);
//!
//! // returns previous element
//! assert(vec8_set(&vec, 0, 15) == 99);
//!
//! // check if set worked
//! assert(vec8_get(&vec, 0) == 15);
//! vec8_free(&vec);
//! ```
//!
//! set elements in a `vec8_t` that has been pushed to
//!
//! ```c
//! // creates a new empty vec8
//! vec8_t vec = vec8(0, 0);
//!
//! // push some data into it
//! vec8_push(&vec, 15);
//! vec8_push(&vec, 95);
//!
//! // set new values
//! vec8_set(&vec, 0, 100);
//! vec8_set(&vec, 1, 200);
//!
//! // check values
//! assert(vec8_set(&vec, 0) == 100);
//! assert(vec8_get(&vec, 1) == 200);
//! vec8_free(&vec);
//! ```
uint8_t vec8_set(vec8_t *v, size_t pos, uint8_t data);

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
//! vec8_t vec = vec8_new(2, 0);
//!
//! // checks length
//! assert(vec8_len(&vec) == 2);
//! vec8_free(&vec);
//! ```
size_t vec8_len(const vec8_t *v);

//! push a value onto the end of the `uint8_t` vector.
//!
//! @param v vector to push onto
//! @param data `uint8_t` to push onto the end
//! @return new size of the vector
//! @note
//! if you know that you will push a large amount of data onto the vector, you
//! may want to call `vec8_reserve()` to make space for it.
//!
//! ## Examples
//!
//! push some data onto the end of an empty vector
//!
//! ```c
//! // creates a new empty vector
//! vec8_t vec = vec8_new(0, 0);
//!
//! // push some values onto the end
//! vec8_push(&vec, 77);
//! vec8_push(&vec, 99);
//!
//! // make sure the values are there
//! assert(vec8_len(&vec) == 2);
//! assert(vec8_get(&vec, 0) == 77);
//! assert(vec8_get(&vec, 1) == 99);
//! vec8_free(&vec);
//! ```
size_t vec8_push(vec8_t *v, uint8_t data);

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
//! vec8_t vec = vec8_new(0, 0);
//!
//! // reserve enough space
//! size_t data_size = 1000000;
//! vec8_reserve(&vec, data_size);
//!
//! // add data
//! for(size_t cur = 0; cur < data_size; cur++) {
//!   vec8_push(&vec, 9);
//! }
//!
//! vec8_free(&vec);
//! ```
void vec8_reserve(vec8_t *v, size_t size);

//! removes all the elements in a vector.
//!
//! @param v the vector to clear
//! @warning
//! internally, this resets the vector's size to 0, but it does not shrink the
//! array used to hold the data. if you want to shrink the container, you can
//! call `vec8_free()` on it and make a new vector with `vec8_new()`.
//!
//! ## Examples
//!
//! clear pre-initialized vector
//!
//! ```c
//! // allocate new pre-initialized vector
//! vec8_t vec = vec8_new(15, 9);
//!
//! // forget all elements in vector
//! vec8_clear(&vec);
//!
//! // check
//! assert(ve16_len(&vec) == 0);
//! vec8_free(&vec);
//! ```
void vec8_clear(vec8_t *v);

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
//! vec8_t vec = vec8_new(0, 0);
//!
//! // adds some data to vec
//! vec8_push(&vec, 16);
//! vec8_push(&vec, 19);
//! vec8_push(&vec, 23);
//!
//! // find index of some elements in vector
//! assert(vec8_index(&vec, 16) == 0);
//! assert(vec8_index(&vec, 19) == 1);
//! assert(vec8_index(&vec, 23) == 2);
//! assert(vec8_index(&vec, 20) == SIZE_MAX);
//! ```
size_t vec8_index(const vec8_t *v, uint8_t data);

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
//! vec8_t vec = vec8_new(10, 8);
//!
//! // add more values to vector
//! vec8_push(&vec, 77);
//! vec8_push(&vec, 10);
//!
//! // compute sum of elements
//! assert(vec8_sum(&vec) == 167);
//! ```
uint64_t vec8_sum(const vec8_t *v);

//! @}
