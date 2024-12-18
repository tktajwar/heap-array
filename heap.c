#include <stdlib.h>

#include "heap.h"

int const INITIAL_SIZE = HEAP_INITIAL_SIZE;

static inline int ensure_heap_size(struct heap* h)
{
	if (h->size > h->length)
		return h->size - h->length;
	else
		extend_heap_size(h);
	return 0;
}

static inline void swap_heap_elements(struct heap* h, int index1, int index2)
{
	int temp;
	temp = h->array[index1];
	h->array[index1] = h->array[index2];
	h->array[index2] = temp;
}

static inline void heapify_up(struct heap* h)
{
	int index = h->length - 1;
	int parent_index;

	while (index > 0) {
		parent_index = HEAP_PARENT(index);

		// break if last element reached the right position
		#if HEAP_TYPE == max
		if (h->array[index] < h->array[parent_index])
			break;
		#else
		if (h->array[index] > h->array[parent_index])
			break;
		#endif

		// else swap with parent and continue doing so
		swap_heap_elements(h, index, parent_index);
		index = parent_index;
	}
}

static inline void heapify_down(struct heap* h, int index)
{
	int left_child_index, right_child_index, next_child_index;

	left_child_index = HEAP_LEFT_CHILD(index);
	right_child_index = HEAP_RIGHT_CHILD(index);

	while (left_child_index < h->length) {
		next_child_index = left_child_index;

		#if HEAP_TYPE == max
		if ( (right_child_index < h->length) &&
		(h->array[right_child_index] > h->array[left_child_index]) )
		#else
		if ( (right_child_index < h->length) &&
		(h->array[right_child_index] < h->array[left_child_index]) )
		#endif
			next_child_index = right_child_index;

		#if HEAP_TYPE == max
		if (h->array[index] > h->array[next_child_index])
		#else
		if (h->array[index] < h->array[next_child_index])
		#endif
			break;

		swap_heap_elements(h, index, next_child_index);
		index = next_child_index;
		left_child_index = HEAP_LEFT_CHILD(index);
		right_child_index = HEAP_RIGHT_CHILD(index);
	}
}

struct heap create_heap()
{
	struct heap h;

	h.size = INITIAL_SIZE;
	h.length = 0;
	h.array = (int *) malloc(sizeof(int) * h.size);

	return h;
}

void clear_heap(struct heap* h)
{
	h->size = INITIAL_SIZE;
	h->length = 0;
	free(h->array);
	h->array = NULL;
}

void extend_heap_size(struct heap* h)
{
	h->size += h->size + 1;
	int* new_array = (int *) malloc(sizeof(int) * h->size);
	for (int i=0; i < h->length; i++)
		new_array[i] = h->array[i];
	free(h->array);
	h->array = new_array;
}

void insert_to_heap(struct heap* h, int n)
{
	ensure_heap_size(h);
	h->array[h->length++] = n;
	heapify_up(h);
}

int pop_from_heap(struct heap* h, int index)
{
	// invalid index
	if (index < 0 || index >= h->length)
		return 0;

	int popped = h->array[index];

	// remove the element
	h->length--;
	h->array[index] = h->array[h->length];
	h->array[h->length] = 0;
	heapify_down(h, index);

}
