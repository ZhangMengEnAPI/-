#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

char path[50];
int top = -1;

void findPath(BTNode* bt, char p)
{
	int rear = top;
	if (bt == NULL)
		return;
	if (bt->data == p)
	{
		path[++top] = bt->data;
		for (int i = 0; i <= top; i++)
			cout << path[i];
		return;
	}
	if (bt->data != p)
	{
		path[++top] = bt->data;
	}
	findPath(bt->lchild, p);
	findPath(bt->rchild, p);
	top = rear;//»ØËÝ
}


int main()
{
	Btree root = createTree();
	findPath(root, 'J');

	return 0;
}