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


#define MAX_HEAP 1
#define MIN_HEAP -1
#define HEAP_TYPE MAX_HEAP

// the initial size of the heaps when initialized
#define HEAP_INITIAL_SIZE 7

// get the parent index
#define HEAP_PARENT(INDEX) (((INDEX)-1) / 2)

// get children index
#define HEAP_LEFT_CHILD(INDEX) (((INDEX)*2) + 1)
#define HEAP_RIGHT_CHILD(INDEX) (((INDEX)*2) + 2)

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
 * Function: cut_heap_size
 * --------------------------
 *  cut space for unnecessary level of leaves
 *
 *  struct heap* h: pointer to the heap to be cut
 */

void cut_heap_size(struct heap* h);

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

/*
 * Static function: swap_heap_elements
 * -----------------------------------
 *  swap two elements in the heap
 *
 *  struct heap* h: pointer to the heap to be modified
 *  int index1:     index of the first element
 *  int index2:     index of the second element
 *
 *  No use outside of library code
 */

/*
 * Static function: heapify_up
 * --------------------
 *  moves the last element in heap up to its right position
 *
 *  struct heap* h: pointer to the heap to modify
 *
 *  No use outside of library code
 */

/*
 * Static function: heapify_down
 * -----------------------------
 *  moves the element in heap down to its right position
 *
 *  struct heap* h: pointer to the heap to modify
 *  int index:      the index of the element
 *
 *  No use outside of library code
 */

/*
 * Function: insert_to_heap
 * ------------------------
 *  inserts an element to heap and positions it to its right place
 *
 *  struct heap* h: pointer to the heap to insert to
 *  int n:          the element to be added
 */

void insert_to_heap(struct heap* h, int n);

/*
 * Function: pop_from_heap
 * --------------------------
 *  pops an element from the heap
 *
 *  struct heap* h: pointer to the heap
 *  int index:      the index of the element
 *
 *  returns 0 if invalid index otherwise returns the value of popped element
 */

int pop_from_heap(struct heap* h, int index);

/*
 * Function: pop_heap_max
 * --------------------------
 *  pops the maximum element from the heap
 *
 *  struct heap* h: pointer to the heap
 *
 *  returns 0 if heap is empty otherwise returns the value of max
 */

int pop_heap_max(struct heap* h);

/*
 * Function: pop_heap_min
 * --------------------------
 *  pops the minimum element from the heap
 *
 *  struct heap* h: pointer to the heap
 *
 *  returns 0 if heap is empty otherwise returns the value of min
 */

int pop_heap_min(struct heap* h);

#endif
