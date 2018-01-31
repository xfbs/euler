//! @file vecp.h
//! pointer vector data structure and associated functions.
#include <stddef.h>
#include <stdint.h>
#pragma once

//! @defgroup vecp vecp
//! @brief a data type and functions for handling pointer vectors
//! @{

//! vector of pointers data type.
//!
//! @warning
//! this should not be used directly - use the associated vector functions to
//! mutate this.
typedef struct {
  //! pointer to the void *array, this array has size `cap`.
  void **data;

  //! capacity of the `data` array of pointers
  size_t cap;

  //! current length of the vector - how many pointers are currently stored in
  //! `data`.
  size_t len;
} vecp_t;

//! creates a new pointer vector.
//!
//! @param len length of the vecp
//! @param fill what the vector should initially be filled with
//! @return a `vecp_t` with the given length and filled with the given values.
//!
//! ## Examples
//!
//! creating a new empty void *vector
//!
//! ```c
//! // creates an empty vecp
//! vecp_t vec = vecp_new(0, NULL);
//! vecp_free(&vec);
//! ```
//!
//! creating a pre-filled void *vector
//!
//! ```c
//! // element to point to
//! int a;
//!
//! // creates a pre-filled vecp
//! vecp_t vec = vecp_new(10, &a);
//!
//! assert(vecp_len(&vec) == 10);
//! assert(vecp_get(&vec, 0) == &a);
//! assert(vecp_get(&vec, 9) == &a);
//! vecp_free(&vec);
//! ```
vecp_t vecp_new(size_t len, void *fill);

//! like `vecp_new()`, but allocates with `malloc`, used to get pointer.
//!
//! @param len initial length ov the `vecp_t`.
//! @param fill what it should be pre-filled with.
//! @return a pointer to a `malloc`-allocated `vecp_t`.
//! @warning
//! unlike `vecp_new()`, which just returns a `vecp_t` that you can keep on
//! the stack, this method returns a pointer to `malloc`'ed memory, which means
//! that in addition to calling `vecp_free()` to free the internals, you need
//! to call `free()` on the pointer itself after you're done using it.
//!
//! ## Examples
//!
//! creating a new empty pointer vector
//!
//! ```c
//! // creates an empty vecp
//! vecp_t *vec = vecp_alloc(0, NULL);
//!
//! vecp_free(vec);
//! free(vec);
//! ```
//!
//! creating a pre-filled pointer vector
//!
//! ```c
//! // element to point to
//! int a;
//!
//! // creates a pre-filled vecp
//! vecp_t *vec = vecp_alloc(10, &a);
//!
//! assert(vecp_len(vec) == 10);
//! assert(vecp_get(vec, 0) == &a);
//! assert(vecp_get(vec, 9) == &a);
//! vecp_free(vec);
//! free(vec);
//! ```
vecp_t *vecp_alloc(size_t len, void *fill);

//! `free()`'s the data held inside the pointer vector.
//!
//! @param v the vector that will have its data released.
//! @warning
//! this function only releases the data held inside a `vecp_t`, not the
//! `vecp_t` itself. if the `vecp_t` has been produced by `vecp_alloc()`,
//! `free()` must also be called on it to release the structure itself.
//!
//! ## Examples
//!
//! freeing a vector on the stack
//!
//! ```c
//! // allocate vector on the stack
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // free vector contents
//! vecp_free(&vec);
//! ```
//!
//! freeing a vector on the heap
//!
//! ```c
//! // allocate new vector on the heap
//! vecp_t *vec = vecp_alloc(0, NULL);
//!
//! // free vector contents
//! vecp_free(vec);
//!
//! // free vector itself
//! free(vec);
//! ```
void vecp_free(vecp_t *v);

//! gets an element of the pointer vector.
//!
//! @param v pointer vector on which to operate
//! @param pos which element to return
//! @return element at `pos`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! get elements from a pre-filled vector
//!
//! ```c
//! // element to point to
//! int a;
//!
//! // creates a pre-filled vecp
//! vecp_t vec = vecp_new(10, &a);
//!
//! // gets the first and last element
//! assert(vecp_get(&vec, 0) == &a);
//! assert(vecp_get(&vec, 9) == &a);
//! vecp_free(&vec);
//! ```
//!
//! get elements from a vecp that has been `vecp_push()`ed to
//!
//! ```c
//! // data to point to
//! int a, b;
//!
//! // creates a new empty vecp
//! vecp_t vec = vecp(0, NULL);
//!
//! // push some data into it
//! vecp_push(&vec, &a);
//! vecp_push(&vec, &b);
//!
//! // check values
//! assert(vecp_get(&vec, 0) == &a);
//! assert(vecp_get(&vec, 1) == &b);
//! vecp_free(&vec);
//! ```
void *vecp_get(const vecp_t *v, size_t pos);

//! sets the element at the specified position to `data`.
//!
//! @param v vector to operate on
//! @param pos which element to overwrite
//! @param ptr new pointer for the position
//! @return previous value at `pos`
//! @warning
//! this method does not check if the given `pos` is a legal position inside the
//! vector, accessing `pos` outside the length of the vector may lead to
//! undefined behaviour.
//!
//! ## Examples
//!
//! set elements in a pre-filled pointer vector
//!
//! ```c
//! // creates a pre-filled vecp
//! vecp_t vec = vecp_new(10, NULL);
//!
//! // element to point to
//! int a;
//!
//! // returns previous element
//! assert(vecp_set(&vec, 0, &a) == NULL);
//!
//! // check if set worked
//! assert(vecp_get(&vec, 0) == NULL);
//! vecp_free(&vec);
//! ```
//!
//! set elements in a pointer vector that has been pushed to
//!
//! ```c
//! // creates a new empty vecp
//! vecp_t vec = vecp(0, NULL);
//!
//! // data to point to
//! int a, b;
//!
//! // push some data into it
//! vecp_push(&vec, NULL);
//! vecp_push(&vec, NULL);
//!
//! // set new values
//! vecp_set(&vec, 0, &a);
//! vecp_set(&vec, 1, &b);
//!
//! // check values
//! assert(vecp_set(&vec, 0) == &a);
//! assert(vecp_get(&vec, 1) == &b);
//! vecp_free(&vec);
//! ```
void *vecp_set(vecp_t *v, size_t pos, void *ptr);

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
//! vecp_t vec = vecp_new(2, NULL);
//!
//! // checks length
//! assert(vecp_len(&vec) == 2);
//! vecp_free(&vec);
//! ```
size_t vecp_len(const vecp_t *v);

//! push a value onto the end of the pointer vector.
//!
//! @param v vector to push onto
//! @param ptr pointer to push onto the end
//! @return new size of the vector
//! @note
//! if you know that you will push a large amount of pointers onto the vector,
//! you may want to call `vecp_reserve()` to make space for it.
//!
//! ## Examples
//!
//! push some data onto the end of an empty vector
//!
//! ```c
//! // creates a new empty vector
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // elements to point at
//! int a, b;
//!
//! // push some values onto the end
//! vecp_push(&vec, &a);
//! vecp_push(&vec, &b);
//!
//! // make sure the values are there
//! assert(vecp_len(&vec) == 2);
//! assert(vecp_get(&vec, 0) == &a);
//! assert(vecp_get(&vec, 1) == &b);
//! vecp_free(&vec);
//! ```
size_t vecp_push(vecp_t *v, void *ptr);

//! reserves the given amount of space for adding new elements.
//!
//! @param v the vector to reserve space for
//! @param size how much additional space to reserve
//!
//! when adding large amount of pointers to a vector, and when the amount
//! is known in advance, this method can be used to reserve space to prevent
//! multiple reallocations of the data while adding them.
//!
//! ## Examples
//!
//! reserves some space in vector to add large amounts of data.
//!
//! ```c
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // reserve enough space
//! size_t data_size = 1000000;
//! vecp_reserve(&vec, data_size);
//!
//! // add data
//! for(size_t cur = 0; cur < data_size; cur++) {
//!   vecp_push(&vec, NULL);
//! }
//!
//! vecp_free(&vec);
//! ```
void vecp_reserve(vecp_t *v, size_t size);

//! removes all the elements in a vector.
//!
//! @param v the vector to clear
//! @warning
//! internally, this resets the vector's size to 0, but it does not shrink the
//! array used to hold the data. if you want to shrink the container, you can
//! call `vecp_free()` on it and make a new vector with `vecp_new()`.
//!
//! ## Examples
//!
//! clear pre-initialized vector
//!
//! ```c
//! // allocate new pre-initialized vector
//! vecp_t vec = vecp_new(15, NULL);
//!
//! // forget all elements in vector
//! vecp_clear(&vec);
//!
//! // check
//! assert(ve16_len(&vec) == 0);
//! vecp_free(&vec);
//! ```
void vecp_clear(vecp_t *v);

//! perform reverse lookup on vector
//!
//! @param v vector to perform lookup in
//! @param ptr pointer to look up
//! @return index of `ptr` in `v`, or `SIZE_MAX` if `data` does not exist in
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
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // data to point to
//! int a, b, c, d;
//!
//! // adds some data to vec
//! vecp_push(&vec, &a);
//! vecp_push(&vec, &b);
//! vecp_push(&vec, &c);
//!
//! // find index of some elements in vector
//! assert(vecp_index(&vec, &a) == 0);
//! assert(vecp_index(&vec, &b) == 1);
//! assert(vecp_index(&vec, &c) == 2);
//! assert(vecp_index(&vec, &d) == SIZE_MAX);
//! ```
size_t vecp_index(const vecp_t *v, void *ptr);

//! @}
