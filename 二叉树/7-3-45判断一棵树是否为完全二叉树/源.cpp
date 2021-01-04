#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

#define MAXSIZE 50

bool isCompleteBTree(BTNode* bt)
{
	BTNode* queue[MAXSIZE];
	int rear = -1, front = -1;

	queue[++rear] = bt;
	while (rear != front)
	{
		bt = queue[++front];
		if (bt != NULL)
		{
			queue[++rear] = bt->lchild;
			queue[++rear] = bt->rchild;
		}
		else
		{
			while (rear != front && bt == NULL)
				bt = queue[++front];
			if(bt != NULL)
				return false;
		}
	}
	return true;
}

int main()
{
	Btree root = createTree();
	cout << isCompleteBTree(root);

	return 0;
}