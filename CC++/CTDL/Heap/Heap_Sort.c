#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void create_heap(int*, int);
void create_random_array(int*, int);
void sort(int *, int);
void swap(int*, int*);
void sift_down(int*, int, int);
void print_array(int*, int);

int main()
{
	int arr[MAX_SIZE];

	srand(time(0));
	create_random_array(arr, MAX_SIZE);
	sort(arr, MAX_SIZE);
	print_array(arr, MAX_SIZE);

	return 0;
}

void create_random_array(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sift_down(int *heap, int start_index, int size)
{
	int parent_index = start_index;
	int left_child_index = parent_index * 2 + 1;
	int right_child_index;
	int max_child_index;

	while (left_child_index < size)
	{
		max_child_index = left_child_index;
		right_child_index = left_child_index + 1;

		if (right_child_index < size && heap[right_child_index] > heap[max_child_index])
		{
			max_child_index = right_child_index;
		}

		if (heap[parent_index] < heap[max_child_index])
		{
			swap(&heap[parent_index], &heap[max_child_index]);
			parent_index = max_child_index;
			left_child_index = parent_index * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void create_heap(int *arr, int size)
{
	int i;
	for (i = (size - 1) / 2; i >= 0; i--)
	{
		sift_down(arr, i, size - 1);
	}
}

void sort(int *arr, int size)
{
	int i;
	
	create_heap(arr, size);
	
	for (i = size - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		sift_down(arr, 0, i);
	}
}

void print_array(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
