#ifndef HEAP_H_
#define HEAP_H_

/*
 * category: HEAP_TYPE
 * -------------------
 *  declare the type of heap tree
 *
 *  defines some functions based on this value
 *
 *  1 = Max heap
 *  2 = Min heap
 */

#define HEAP_TYPE 1

// the initial size of the heaps when declared
#define HEAP_INITIAL_SIZE 7

#define HEAP_PARENT(INDEX) (((INDEX)-1) / 2)

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

/*
 * Function: extend_heap_size
 * --------------------------
 *  add space for next level of leaves
 *
 *  struct heap* h: pointer to the heap to be extended
 */

void extend_heap_size(struct heap* h);

/*
 * Static Function: ensure_heap_size
 * ---------------------------------
 *  calculates if there's space left for one/more items and extends if not
 *
 *  struct heap* h: pointer to the heap to be ensured
 *
 *  returns the amount of space left
 *
 *  No use outside of library code
 */


#endif
