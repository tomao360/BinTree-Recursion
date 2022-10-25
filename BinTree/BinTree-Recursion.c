#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

struct Leaf
{
	//Management or MetaData
	struct leaf* left;
	struct leaf* right;
	struct leaf* parent;

	//Data (Real Data)
	int Val;
};
struct Leaf* root = NULL;


void AddLeaf(struct Leaf* curr, int val)
{
	struct Leaf* newLeaf = (struct Leaf*)malloc(sizeof(struct Leaf));
	newLeaf->Val = val;
	newLeaf->right = NULL;
	newLeaf->left = NULL;

	if (root == NULL)
	{
		root = newLeaf;
		newLeaf->parent = NULL;
	}
	else 
	{
		if (curr == NULL)
		{
			curr = root;
		}

		if (curr->Val < val)
		{
			if (curr->right == NULL)
			{
				//Add into
				curr->right = newLeaf;
				newLeaf->parent = curr;
			}
			else
			{
				AddLeaf(curr->right, val);
			}
		}
		else
		{
			if (curr->left == NULL)
			{
				//Add into
				curr->left = newLeaf;
				newLeaf->parent = curr;
			}
			else
			{
				AddLeaf(curr->left, val);
			}
		}
	}
}

void PrintTreeSmallToBig(struct Leaf* curr)
{
	if (curr->left != NULL)
	{
		PrintTreeSmallToBig(curr->left);
	}

	printf("%d\n", curr->Val);

	if (curr->right != NULL)
	{
		PrintTreeSmallToBig(curr->right);
	}
}

void PrintTreeBigToSmall(struct Leaf* curr)
{
	if (curr->right != NULL)
	{
		PrintTreeBigToSmall(curr->right);
	}

	printf("%d\n", curr->Val);

	if (curr->left != NULL)
	{
		PrintTreeBigToSmall(curr->left);
	}
}



int main_3()
{
	/*AddLeaf(NULL, 3);
	AddLeaf(NULL, 9);
	AddLeaf(NULL, 4);
	AddLeaf(NULL, 2);
	AddLeaf(NULL, 223);
	AddLeaf(NULL, 23);
	AddLeaf(NULL, 5);
	AddLeaf(NULL, 123);
	AddLeaf(NULL, 1);
	AddLeaf(NULL, 10);
	AddLeaf(NULL, 100);*/

	for (int i = 0; i < 10; i++)
	{
		int num;
		printf("Please enter a number: ");
		scanf("%d", &num);
		AddLeaf(NULL, num);
	}

	PrintTreeSmallToBig(root);
	printf("\n\n");
	PrintTreeBigToSmall(root);

	
}