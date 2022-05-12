#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

struct Heap
{
	int elements[MAX_SIZE];
	int size;
};

struct Heap *create_heap(int*, int);
void create_random_array(int*, int);
void sort(int *, int);
void swap(int*, int*);
void sift_down(struct Heap*, int, int);
void print_array(int*, int);

int main()
{
	int array[MAX_SIZE];

	srand(time(0));
	create_random_array(array, MAX_SIZE);
	sort(array, MAX_SIZE);
	print_array(array, MAX_SIZE);

	return 0;
}

void create_random_array(int *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		array[i] = rand();
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sift_down(struct Heap *heap, int start_index, int size)
{
	int parent_index = start_index;
	int left_child_index = parent_index * 2 + 1;
	int right_child_index;
	int max_child_index;

	while (left_child_index < size)
	{
		max_child_index = left_child_index;
		right_child_index = left_child_index + 1;

		if (right_child_index < size && heap->elements[right_child_index] > heap->elements[max_child_index])
		{
			max_child_index = right_child_index;
		}

		if (heap->elements[parent_index] < heap->elements[max_child_index])
		{
			swap(&heap->elements[parent_index], &heap->elements[max_child_index]);
			parent_index = max_child_index;
			left_child_index = parent_index * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

struct Heap *create_heap(int *array, int size)
{
	int i;
	struct Heap *heap = (struct Heap*) malloc(sizeof(struct Heap));

	heap->size = size;
	for (i = 0; i < size; i++)
	{
		heap->elements[i] = array[i];
	}

	for (i = (size - 1) / 2; i >= 0; i--)
	{
		sift_down(heap, i, heap->size - 1);
	}

	return heap;
}

void sort(int *array, int size)
{
	int i;
	struct Heap *heap = create_heap(array, size);

	for (i = heap->size - 1; i > 0; i--)
	{
		swap(&heap->elements[0], &heap->elements[i]);
		sift_down(heap, 0, i);
	}

	for (i = 0; i < size; i++)
	{
		array[i] = heap->elements[i];
	}
}

void print_array(int *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}