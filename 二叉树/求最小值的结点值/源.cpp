#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

BTNode* findMin(BTNode* bt)
{
	BTNode* l = NULL, * r = NULL;
	static BTNode* min = bt;

	if (bt == NULL)
		return NULL;
	else
	{
		min = bt->data < min->data ? bt : min;
		l = findMin(bt->lchild);
		r = findMin(bt->rchild);
		return min;
	}
}

int main()
{
	Btree root = createTree();
	cout << findMin(root)->data;

	return 0;
}