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

//! Comparison function between two elements.
//!
//! Functions that have this type can be used as sorting functions with
//! `vecp_sort()`, or as comparison functions for `vecp_bsearch()`. Functions
//! are expected to behave in the same way as comparison functions for the
//! `qsort()` function of the standard library.
typedef int (*vecp_cmp)(const void *, const void *);

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
//! vecp_t vec = vecp_new(0, NULL);
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
//! assert(vecp_get(&vec, 0) == &a);
//! vecp_free(&vec);
//! ```
//!
//! set elements in a pointer vector that has been pushed to
//!
//! ```c
//! // creates a new empty vecp
//! vecp_t vec = vecp_new(0, NULL);
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
//! assert(vecp_get(&vec, 0) == &a);
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
//! assert(vecp_len(&vec) == 0);
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
//! which just compares the pointers' numerical values directly.
//!
//! ## Examples
//!
//! ```c
//! // new pointer vector
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // some strings
//! vecp_push(&vec, "Hello");
//! vecp_push(&vec, "vecp_test");
//! vecp_push(&vec, "World");
//! vecp_push(&vec, "12345qwerty");
//! vecp_push(&vec, "World");
//!
//! // find the strings. note that lsearch always returns the first match.
//! assert(vecp_lsearch(&vec, "Hello", (vecp_cmp) strcmp) == 0);
//! assert(vecp_lsearch(&vec, "World", (vecp_cmp) strcmp) == 2);
//!
//! vecp_free(&vec);
//! ```
size_t vecp_lsearch(const vecp_t *v, void *data, vecp_cmp cmp);

//! Perform a binary search on the vector.
//!
//! @param v vector to search
//! @param data data to search for
//! @param cmp comparison function between elements and data
//! @return an index to the found element, or `SIZE_MAX`
//!
//! This function performs a binary search on the sorted vector using `cmp`
//! as a comparison function. Note that if the vector is not sorted, this
//! function will not work, then you must use `vecp_lsearch()`.
//!
//! It returns an index to an element that is equal to `data`.
//!
//! If `NULL` is passed as `cmp`, then the built-in comparison function is used,
//! which just compares the pointers' numerical values directly.
//!
//! ## Examples
//!
//! Find an element in a sorted vector.
//!
//! ```c
//! // new empty vector
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // targets
//! void *a = (void *) 0xABCDEF1;
//! void *b = (void *) 0xABCDEF2;
//! void *c = (void *) 0xABCDEF3;
//! void *d = (void *) 0xABCDEF4;
//!
//! // adds some data to it
//! vecp_push(&vec, a);
//! vecp_push(&vec, b);
//! vecp_push(&vec, c);
//! vecp_push(&vec, d);
//!
//! // sort vector
//! //vecp_sort(&vec, NULL);
//!
//! // check that all pointers exist
//! assert(vecp_bsearch(&vec, a, NULL) != SIZE_MAX);
//! assert(vecp_bsearch(&vec, b, NULL) != SIZE_MAX);
//! assert(vecp_bsearch(&vec, c, NULL) != SIZE_MAX);
//! assert(vecp_bsearch(&vec, d, NULL) != SIZE_MAX);
//! assert(vecp_bsearch(&vec, (void *) 0x2AAA899, NULL) == SIZE_MAX);
//!
//! // check if the get the correct element back
//! assert(vecp_get(&vec, vecp_bsearch(&vec, a, NULL)) == a);
//! assert(vecp_get(&vec, vecp_bsearch(&vec, b, NULL)) == b);
//! assert(vecp_get(&vec, vecp_bsearch(&vec, c, NULL)) == c);
//! assert(vecp_get(&vec, vecp_bsearch(&vec, d, NULL)) == d);
//!
//! // release
//! vecp_free(&vec);
//! ```
//!
//! Find a string in a sorted vector.
//!
//! ```c
//! // new emprt vector
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // add strings (pre-sorted)
//! vecp_push(&vec, "another");
//! vecp_push(&vec, "birthday");
//! vecp_push(&vec, "comes");
//! vecp_push(&vec, "deliberately");
//!
//! // find the indexes of the words
//! assert(vecp_bsearch(&vec, "another", (vecp_cmp) strcmp) == 0);
//! assert(vecp_bsearch(&vec, "birthday", (vecp_cmp) strcmp) == 1);
//! assert(vecp_bsearch(&vec, "comes", (vecp_cmp) strcmp) == 2);
//! assert(vecp_bsearch(&vec, "deliberately", (vecp_cmp) strcmp) == 3);
//! assert(vecp_bsearch(&vec, "easy", (vecp_cmp) strcmp) == SIZE_MAX);
//!
//! // release
//! vecp_free(&vec);
//! ```
size_t vecp_bsearch(const vecp_t *v, void *data, vecp_cmp cmp);

//! Sort the vector.
//!
//! Sorts the vector in-place using the provided comparison function.
//!
//! If `NULL` is passed as `cmp`, then the built-in comparison function is used,
//! which just compares the pointers' numerical values directly.
//!
//! @param v vector to sort.
//! @param cmp comparison function between elements.
//!
//! ## Examples
//!
//! Sort pointers by numerical value
//!
//! ```c
//! // new empty vector
//! vecp_t vec = vecp_new(0, NULL);
//!
//! // adds some data to it
//! vecp_push(&vec, (void *) 0xDEADBEEF);
//! vecp_push(&vec, (void *) 0xCAEFBABE);
//! vecp_push(&vec, (void *) 0xC0FFEBAD);
//! vecp_push(&vec, (void *) 0xAABBCCDD);
//!
//! // sort vector: after this, vec contains sorted pointers to a, b, d and d.
//! vecp_sort(&vec, NULL);
//!
//! // check order of pointers
//! assert(vecp_get(&vec, 0) == (void *) 0xAABBCCDD);
//! assert(vecp_get(&vec, 1) == (void *) 0xC0FFEBAD);
//! assert(vecp_get(&vec, 2) == (void *) 0xCAEFBABE);
//! assert(vecp_get(&vec, 3) == (void *) 0xDEADBEEF);
//!
//! // release
//! vecp_free(&vec);
//! ```
//!
//! Sort strings with `strcmp()`
//!
//! ```c
//! ```
void vecp_sort(vecp_t *v, vecp_cmp cmp);

//! @}
