#ifndef HEAP_H_
#define HEAP_H_

// the initial size of the heaps when declared
#define HEAP_INITIAL_SIZE 7

/*
 * Structure: Heaps
 * ----------------
 *  Heaps data structure
 *
 *  int size: size of heap array
 *  int length: number of elements stored in heap
 *  int* array: pointer to the first element of the heap array
 */

struct heap
{
	int size;
	int length;
	int* array;
};

/*
 * Function: create_heap
 * ----------------------
 *  creates a new heaps data structure
 *
 *  returns the newly created heaps
 */

struct heap create_heap();

/*
 * Function: clear_heap
 * --------------------
 *  frees the heap array and sets the size and length of heap to initial values
 *
 *  struct heap *h: pointer to the heap to be cleared
 */

void clear_heap(struct heap* h);

#endif
