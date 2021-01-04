#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

#define MAXSIZE 50

int leafNum(BTNode* bt, int k)
{
	BTNode* queue[MAXSIZE];
	int rear = -1, front = -1;
	int right = 0, level = 1, leafnum = 0;

	queue[++rear] = bt;
	while (rear != front)
	{
		bt = queue[++front];
		if (level == k)
		{
			if (bt->lchild == NULL && bt->rchild == NULL)
				leafnum++;
		}
		else
		{
			if (bt->lchild != NULL)
				queue[++rear] = bt->lchild;
			if (bt->rchild != NULL)
				queue[++rear] = bt->rchild;
		}

		if (right == front)
		{
			if (level == k)
				return leafnum;
			right = rear;
			level++;
		}
	}
	return 0;
}

int main()
{
	Btree root = createTree();
	int k = 4;
	cout << leafNum(root, k);

	return 0;
}