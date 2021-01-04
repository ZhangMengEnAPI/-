#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

#define MAXSIZE 50

int width(BTNode * bt)
{
	BTNode* queue[MAXSIZE] = {NULL};
	int front = -1, rear = -1;
	int right = 0, maxwidth = 1, levelwidth = 0;

	queue[++rear] = bt;
	while (rear != front)
	{
		bt = queue[++front];

		if (bt->lchild != NULL)
		{
			queue[++rear] = bt->lchild;
			levelwidth++;
		}
		if (bt->rchild != NULL)
		{
			queue[++rear] = bt->rchild;
			levelwidth++;
		}
		if (right == front)
		{
			if (maxwidth < levelwidth)
				maxwidth = levelwidth;
			levelwidth = 0;
			right = rear;
		}
	}
	return maxwidth;

}

int main()
{
	Btree root = createTree();
	cout << width(root);

	return 0;
}