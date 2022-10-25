#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

typedef struct
{
	int age;

} DetailsT;

struct Leaf
{
	int level;
	struct leaf* left;
	struct leaf* right;
	struct leaf* parent;

	DetailsT details;
};
struct Leaf* Root = NULL;

struct QueueItem
{
	struct Leaf* leaf;
	struct QueueItem* next;
	struct QueueItem* prev;

};
struct QueueItem* Queue_Head = NULL;
struct QueueItem* Queue_Tail = NULL;



void AddItem(DetailsT item)
{
	struct Leaf* currentLeaf;
	currentLeaf = (struct Leaf*)malloc(sizeof(struct Leaf));
	if (currentLeaf == NULL)
	{
		printf("Memory allocation problem");
		return;
	}
	else
	{
		//currentLeaf->details.age = item.age;
		currentLeaf->details = item;
		
		if (Root == NULL)
		{
			currentLeaf->right = NULL;
			currentLeaf->left = NULL;
			currentLeaf->parent = NULL;
			currentLeaf->level = 0;
			Root = currentLeaf;
		}
		else
		{
			if (Root->right == NULL)
			{
				Root->right = currentLeaf;
				currentLeaf->parent = Root;
				currentLeaf->level = 1;
			}
			else if (Root->left == NULL)
			{
				Root->left = currentLeaf;
				currentLeaf->parent = Root;
				currentLeaf->level = 2;
			}
		}
	}
}

void Queue_Push(struct Leaf* item)
{
	struct QueueItem* currentItem;
	currentItem = (struct QueueItem*)malloc(sizeof(struct QueueItem));
	if (currentItem == NULL)
	{
		printf("Memory allocation problem");
		return;
	}
	else
	{ 
		currentItem->leaf = item;

		if (Queue_Head == NULL)
		{
			Queue_Head = currentItem;
			Queue_Tail = currentItem;
			currentItem->next = NULL;
			currentItem->prev = NULL;
		}
		else
		{
			Queue_Head->prev = currentItem;
			currentItem->next = Queue_Head;
			currentItem->prev = NULL;
			Queue_Head = currentItem;
		}
	}
}

struct QueueItem* Queue_Pop()
{
	struct QueueItem* ret = Queue_Tail;

	if (Queue_Tail == NULL)
	{
		printf("The list is empty");
		return NULL;
	}

	if (Queue_Tail->prev != NULL)
	{
		Queue_Tail = Queue_Tail->prev;
	}

	return ret;
}

void Queue_Status()
{
	struct QueueItem* currentItem = Queue_Tail;

	printf("The reasulting linked list:\n");
	while (currentItem != NULL)
	{
		printf("%p\n", currentItem);
		currentItem = currentItem->prev;
	}
}

void Queue_Clear()
{
	struct QueueItem* currentItem = Queue_Tail;
	struct QueueItem* release;

	while (currentItem != NULL)
	{
		release = currentItem;
		currentItem = currentItem->prev;
		free(release);
	}

	Queue_Head = NULL;
	Queue_Tail = NULL;
}



int main_1()
{
	DetailsT detail1;
	detail1.age = 23;
	AddItem(detail1);

	DetailsT detail2;
	detail2.age = 12;
	AddItem(detail2);

	DetailsT detail3;
	detail3.age = 50;
	AddItem(detail3);

	Queue_Push(NULL);
	Queue_Push(NULL);
	Queue_Push(NULL);
	Queue_Status();
	Queue_Pop();
	Queue_Status();
	Queue_Pop();
	Queue_Status();
	Queue_Clear();

	return 0;
}