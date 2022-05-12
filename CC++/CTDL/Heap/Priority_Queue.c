#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

struct Element
{
	char data;
	int priority;
};
struct Priority_Queue
{
	struct Element elements[MAX_SIZE];
	int size;
};

struct Priority_Queue *init();
void add(struct Priority_Queue*, struct Element);
void sift_up(struct Priority_Queue*);
void sift_down(struct Priority_Queue*, int, int);
void swap(struct Element*, struct Element*);
void print_PQ(struct Priority_Queue);
void print_Element(struct Element);
struct Element removee(struct Priority_Queue*);
int random(int, int);

int main()
{
	struct Priority_Queue *pq = init();
	struct Element e;
	int i;
	srand(time(0));

	for (i = 0; i < 10; i++)
	{
		// e.data is a random character ranged from 'a'(97) to 'z'(122)
		e.data = random(97, 122);
		e.priority = rand();
		add(pq, e);
	}

	printf("Priority Queue: ");
	print_PQ(*pq);
	e = removee(pq);
	printf("\n\nThe element got by removing: ");
	print_Element(e);

	return 0;
}

int random(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

struct Priority_Queue *init()
{
	struct Priority_Queue *pq = (struct Priority_Queue*) malloc(sizeof(struct Priority_Queue));
	pq->size = 0;
	return pq;
}

void swap(struct Element *e1, struct Element *e2)
{
	struct Element temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void sift_up(struct Priority_Queue *pq)
{
	struct Element *parent;
	struct Element *child;
	int child_index = pq->size - 1;
	int parent_index;

	while (child_index > 0)
	{
		parent_index = (child_index - 1) / 2;
		parent = &pq->elements[parent_index];
		child = &pq->elements[child_index];

		if (parent->priority < child->priority)
		{
			swap(parent, child);
			child_index = parent_index;
		}
		else
		{
			return;
		}
	}
}

void add(struct Priority_Queue *pq, struct Element element)
{
	int current_size = pq->size;
	if (current_size < MAX_SIZE)
	{
		pq->elements[current_size] = element;
		pq->size++;
		sift_up(pq);
	}
}

void sift_down(struct Priority_Queue *pq, int start_index, int size)
{
	int parent_index = start_index;
	int left_child_index = (parent_index * 2 ) + 1;
	int right_child_index;
	int highest_priority_child_index;
	int left_child_priority;
	int right_child_priority;
	int highest_child_priority;
	int parent_priority;

	while (left_child_index < size)
	{
		right_child_index = (left_child_index) + 1;
		highest_priority_child_index = left_child_index;
		highest_child_priority = pq->elements[left_child_index].priority;
		right_child_priority = pq->elements[right_child_index].priority;
		parent_priority = pq->elements[parent_index].priority;

		if (right_child_index < size && right_child_priority > highest_child_priority)
		{
			highest_priority_child_index = right_child_index;
			highest_child_priority = right_child_priority;
		}

		if (parent_priority < highest_child_priority)
		{
			swap(&pq->elements[parent_index], &pq->elements[highest_priority_child_index]);
			parent_index = highest_priority_child_index;
			left_child_index = (parent_index * 2) + 1;
		}
		else
		{
			return;
		}
	}
}

struct Element removee(struct Priority_Queue *pq)
{
	int last_index = pq->size - 1;

	swap(&pq->elements[0], &pq->elements[last_index]);
	pq->size--;
	sift_down(pq, 0, pq->size);

	return pq->elements[last_index];
}

void print_Element(struct Element e)
{
	printf("%c %d", e.data, e.priority);
}

void print_PQ(struct Priority_Queue pq)
{
	for (int i = 0; i < pq.size; i++)
	{
		print_Element(pq.elements[i]);
		printf(", ");
	}
}