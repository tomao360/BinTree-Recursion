
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

typedef struct
{
	unsigned int age;
} DetailsT;

typedef struct Leaf
{
	// Management or MetaData
	int level;
	struct Leaf* Left;
	struct Leaf* Right;
	struct Leaf* Parent;

	// Data (Real Data)
	DetailsT Details;
} TLeaf;
struct Leaf* Root;

typedef struct QueueItem {
	TLeaf* leaf;
	int Id;
	struct QueueItem* prev;
	struct QueueItem* next;

} TQueueItem;

TQueueItem* Queue_Head;
TQueueItem* Queue_Tail;

void QueuePush(TLeaf* leaf)
{
	//malloc
	TQueueItem* newItem = (TQueueItem*)malloc(sizeof(TQueueItem));
	newItem->leaf = leaf;
	newItem->next = NULL;

	if (Queue_Head == NULL)
	{
		Queue_Head = newItem;
		Queue_Tail = newItem;
		newItem->next = NULL;
		newItem->prev = NULL;
	}
	else
	{
		Queue_Head->next = newItem;
		newItem->prev = Queue_Head;
		Queue_Head = newItem;

	}
}

int Queue_IsEmpty()
{
	if (Queue_Head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void QueueClear()
{
	Queue_Head = NULL;
	Queue_Tail = NULL;
}


TQueueItem* QueuePop()
{
	TQueueItem* ret = NULL;
	if (Queue_Head == NULL)
	{
		return NULL;
	}
	else if (Queue_Head == Queue_Tail)
	{
		ret = Queue_Head;
		Queue_Head = NULL;
		Queue_Tail = NULL;
		return ret;

	}
	else {
		ret = Queue_Tail;
		Queue_Tail->next->prev = NULL;
		Queue_Tail = Queue_Tail->next;
		return ret;
	}
}

//////////////////////////////////////
void AddTreeItem(DetailsT item)
{
	// Add new item into Tree
	TLeaf* newLeaf = (TLeaf*)malloc(sizeof(TLeaf));
	newLeaf->Details = item;

	newLeaf->Right = NULL;
	newLeaf->Left = NULL;

	if (Root == NULL)
	{
		newLeaf->Parent = NULL;
		Root = newLeaf;
		newLeaf->level = 0;
	}
	else
	{
		TQueueItem* curr;
		TLeaf* foundEmptyPlace = NULL;
		QueuePush(Root);

		while ((curr = QueuePop()) != NULL)
		{
			foundEmptyPlace = NULL;
			if (curr->leaf->Left == NULL)
			{
				foundEmptyPlace = curr->leaf;
				foundEmptyPlace->Left = newLeaf;
				newLeaf->Parent = foundEmptyPlace;

			}
			else if (curr->leaf->Right == NULL)
			{
				foundEmptyPlace = curr->leaf;
				foundEmptyPlace->Right = newLeaf;
				newLeaf->Parent = foundEmptyPlace;
			}
			else
			{
				QueuePush(curr->leaf->Left);
				QueuePush(curr->leaf->Right);
			}

			if (foundEmptyPlace)
				QueueClear();

		}
	}
}


void BuildTree()
{
	for (int i = 0; i < 100; i++)
	{
		DetailsT* details = (DetailsT*)malloc(sizeof(DetailsT));
		details->age = i;

		AddTreeItem(*details);
	}
}


TLeaf* FindEmptyPlaceLeaf(TLeaf* leaf)
{
	if (leaf->Left != NULL)
		return leaf->Left;
	else if (leaf->Right != NULL)
		return leaf->Right;
	else
		return NULL;
}


main_4()
{
	Root = NULL;
	Queue_Tail = NULL;
	Queue_Head = NULL;
	QueuePush(NULL);
	QueuePush(NULL);
	QueuePush(NULL);
	QueuePop();
	QueuePop();
	QueuePop();
	QueueClear();


	BuildTree();
	struct Leaf leaf;
	struct Leaf* leafPtr = (struct Leaf*)malloc(sizeof(struct Leaf));

	leaf.Details.age = 23;
	leafPtr->Details.age = 23;

	//strcpy(leaf.Details.address, "dafsdfsdf");
}