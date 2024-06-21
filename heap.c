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
		#if HEAP_TYPE == 1
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
