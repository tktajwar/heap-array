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

#endif
