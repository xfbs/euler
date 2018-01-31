//! @file vec.h
//! @author Patrick M. Elsen
//! @date 2018
//! @copyright MIT license
//! @brief generic macros for use with the vector data types.
//! @details
//! the macros in this file serve as generic functions that can be used in place
//! of the specialized functions of each vector type.
#include <euler/vec8.h>
#include <euler/vec16.h>
#include <euler/vec32.h>
#include <euler/vec64.h>
#include <euler/vecp.h>

//! @defgroup vec vec
//! @brief generic functions to operatr on various vector types implemented as
//! macros.
//! @details
//! the macros in this file serve as generic functions that can be used in place
//! of the specialized functions of each vector type.
//! @see vecp, vec8, vec16, vec32, vec64
//! @{

//! `free()`'s the data held inside a vector.
//!
//! @param v the vector that will have its data released.
//! @warning
//! this function only releases the data held inside the vector, not the
//! vector itself.
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`.
//! @see `vecp_free()`, `vec8_free()`, `vec16_free()`, `vec32_free()`,
//! `vec64_free()`
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
//! vec_free(vec);
//!
//! // free vector itself
//! free(vec);
//! ```
#define vec_free(v) _Generic(v,  \
  vecp_t*: vecp_free, \
  vec8_t*: vec8_free, \
  vec16_t*: vec16_free, \
  vec32_t*: vec32_free, \
  vec64_t*: vec64_free)(v)

//! gets an element from a vector.
//!
//! @param v vector on which to operate
//! @param pos which element to return
//! @return element at `pos`
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`
//! @see `vecp_get()`, `vec8_get()`, `vec16_get()`, `vec32_get()`, `vec64_get()`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! get elements from a pre-filled `vec8_t`
//!
//! ```c
//! // creates a pre-filled vec8
//! vec8_t vec = vec8_new(10, 99);
//!
//! // gets the first and last element
//! assert(vec_get(&vec, 0) == 99);
//! assert(vec_get(&vec, 9) == 99);
//! vec_free(&vec);
//! ```
//!
//! get elements from a `vec16_t` that has been pushed to
//!
//! ```c
//! // creates a new empty vec8
//! vec16_t vec = vec16(0, 0);
//!
//! // push some data into it
//! vec_push(&vec, 15);
//! vec_push(&vec, 95);
//!
//! // check values
//! assert(vec_get(&vec, 0) == 15);
//! assert(vec_get(&vec, 1) == 95);
//! vec_free(&vec);
//! ```
#define vec_get(v, pos) _Generic(v,  \
  vecp_t*: vecp_get, \
  vec8_t*: vec8_get, \
  vec16_t*: vec16_get, \
  vec32_t*: vec32_get, \
  vec64_t*: vec64_get)(v, pos)

//! sets the element at the specified position to `data`.
//!
//! @param v vector to operate on
//! @param pos which element to overwrite
//! @param data new data for the position
//! @return previous value at `pos`
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`
//! @see `vecp_set()`, `vec8_set()`, `vec16_set()`, `vec32_set()`, `vec64_set()`
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
//! assert(vec_set(&vec, 0, 15) == 99);
//!
//! // check if set worked
//! assert(vec_get(&vec, 0) == 15);
//! vec_free(&vec);
//! ```
//!
//! set elements in a `vec16_t` that has been pushed to
//!
//! ```c
//! // creates a new empty vec8
//! vec16_t vec = vec16_new(0, 0);
//!
//! // push some data into it
//! vec_push(&vec, 15);
//! vec_push(&vec, 95);
//!
//! // set new values
//! vec_set(&vec, 0, 100);
//! vec_set(&vec, 1, 200);
//!
//! // check values
//! assert(vec_set(&vec, 0) == 100);
//! assert(vec_get(&vec, 1) == 200);
//! vec_free(&vec);
//! ```
#define vec_set(v, pos, data) _Generic(v,  \
  vecp_t*: vecp_set, \
  vec8_t*: vec8_set, \
  vec16_t*: vec16_set, \
  vec32_t*: vec32_set, \
  vec64_t*: vec64_set)(v, pos, data)

//! get the length of a vector.
//!
//! @param v vector to get length of
//! @return length of `v`
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`
//! @see `vecp_len()`, `vec8_len()`, `vec16_len()`, `vec32_len()`, `vec64_len()`
//!
//! ## Examples
//!
//! get length of pre-filled vector
//!
//! ```c
//! // creates a vec8 with length 2
//! vec8_t vec = vec8_new(2, 0);
//!
//! // creates a vec16 with length 9
//! vec16_t other = vec16_new(9, 0);
//!
//! // checks lengths
//! assert(vec_len(&vec) == 2);
//! assert(vec_len(&other) == 9);
//! vec_free(&vec);
//! vec_free(&other);
//! ```
#define vec_len(v) _Generic(v,  \
  vecp_t*: vecp_len, \
  vec8_t*: vec8_len, \
  vec16_t*: vec16_len, \
  vec32_t*: vec32_len, \
  vec64_t*: vec64_len)(v)

//! push a value onto the end of a vector.
//!
//! @param v vector to push onto
//! @param data value to push onto the end
//! @return new size of the vector
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`
//! @see `vecp_push()`, `vec8_push()`, `vec16_push()`, `vec32_push()`,
//! `vec64_push()`.
//! @note
//! if you know that you will push a large amount of data onto the vector, you
//! may want to call `vec_reserve()` to make space for it.
//!
//! ## Examples
//!
//! push some data onto the end of an empty vector
//!
//! ```c
//! // creates a new empty vec8
//! vec8_t vec = vec8_new(0, 0);
//!
//! // push some values onto the end
//! vec_push(&vec, 77);
//! vec_push(&vec, 99);
//!
//! // make sure the values are there
//! assert(vec_len(&vec) == 2);
//! assert(vec_get(&vec, 0) == 77);
//! assert(vec_get(&vec, 1) == 99);
//! vec_free(&vec);
//! ```
#define vec_push(v, data) _Generic(v,  \
  vecp_t*: vecp_push, \
  vec8_t*: vec8_push, \
  vec16_t*: vec16_push, \
  vec32_t*: vec32_push, \
  vec64_t*: vec64_push)(v, data)

//! reserves the given amount of space for adding new elements.
//!
//! @param v the vector to reserve space for
//! @param size how much additional space to reserve
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`.
//! @see `vecp_reserve()`, `vec8_reserve()`, `vec16_reserve()`, `vec32_reserve()`,
//! `vec64_reserve()`.
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
//! // allocates new vec32
//! vec32_t vec = vec32_new(0, 0);
//!
//! // reserve enough space
//! size_t data_size = 1000000;
//! vec_reserve(&vec, data_size);
//!
//! // add data
//! for(size_t cur = 0; cur < data_size; cur++) {
//!   vec_push(&vec, 9);
//! }
//!
//! vec_free(&vec);
//! ```
#define vec_reserve(v, num) _Generic(v,  \
  vecp_t*: vecp_reserve, \
  vec8_t*: vec8_reserve, \
  vec16_t*: vec16_reserve, \
  vec32_t*: vec32_reserve, \
  vec64_t*: vec64_reserve)(v, num)

//! removes all the elements in a vector.
//!
//! @param v the vector to clear
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`
//! @see `vecp_clear()`, `vec8_clear()`, `vec16_clear()`, `vec32_clear()`,
//! `vec64_clear()`
//! @warning
//! internally, this resets the vector's size to 0, but it does not shrink the
//! array used to hold the data.
//!
//! ## Examples
//!
//! clear pre-initialized vector
//!
//! ```c
//! // allocate new pre-initialized vecp
//! vecp_t vec = vecp_new(15, NULL);
//!
//! // forget all elements in vector
//! vec_clear(&vec);
//!
//! // check
//! assert(vec_len(&vec) == 0);
//! vec_free(&vec);
//! ```
#define vec_clear(v) _Generic(v,  \
  vecp_t*: vecp_clear, \
  vec8_t*: vec8_clear, \
  vec16_t*: vec16_clear, \
  vec32_t*: vec32_clear, \
  vec64_t*: vec64_clear)(v)

//! perform reverse lookup on vector
//!
//! @param v vector to perform lookup in
//! @param data element to look up
//! @return index of `data` in `v`, or `SIZE_MAX` if `data` does not exist in
//! `v`.
//! @info
//! compatible with vectors of types `vecp_t`, `vec8_t`, `vec16_t`, `vec32_t`,
//! `vec64_t`
//! @see `vecp_index()`, `vec8_index()`, `vec16_index()`, `vec32_index()`,
//! `vec64_index()`
//!
//! for a given vector `v` and element `data`, searches the vector for
//! occurences of `data`, returning the index of the first occurence or
//! `SIZE_MAX` to indicate that the element does not exist.
//!
//! ## Examples
//!
//! ```c
//! // allocates new vec8
//! vec8_t vec = vec8_new(0, 0);
//!
//! // adds some data to vec
//! vec_push(&vec, 16);
//! vec_push(&vec, 19);
//! vec_push(&vec, 23);
//!
//! // find index of some elements in vector
//! assert(vec_index(&vec, 16) == 0);
//! assert(vec_index(&vec, 19) == 1);
//! assert(vec_index(&vec, 23) == 2);
//! assert(vec_index(&vec, 20) == SIZE_MAX);
//! ```
#define vec_index(v, data) _Generic(v,  \
  vecp_t*: vecp_index, \
  vec8_t*: vec8_index, \
  vec16_t*: vec16_index, \
  vec32_t*: vec32_index, \
  vec64_t*: vec64_index)(v, data)

//! computes the sum of elements in the vector.
//!
//! @param v vector with elements to add
//! @return sum of all elements in `v`
//! @info
//! compatible with vectors of types `vec8_t`, `vec16_t`, `vec32_t`, `vec64_t`.
//! @see `vec8_sum()`, `vec16_sum()`, `vec32_sum()`, `vec64_sum()`
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
//! vec_push(&vec, 77);
//! vec_push(&vec, 10);
//!
//! // compute sum of elements
//! assert(vec_sum(&vec) == 167);
//! ```
#define vec_sum(v) _Generic(v,  \
  vec8_t*: vec8_sum, \
  vec16_t*: vec16_sum, \
  vec32_t*: vec32_sum, \
  vec64_t*: vec64_sum)(v)

//! @}
