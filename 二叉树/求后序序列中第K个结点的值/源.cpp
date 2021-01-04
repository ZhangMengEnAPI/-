#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

BTNode* findK(BTNode * bt, int x)
{
	BTNode* l = NULL, * r = NULL;
	static int k = x;

	if (bt != NULL && k != 0)
	{
		l = findK(bt->lchild, k);
		r = findK(bt->rchild, k);
		k--;
		if (k == 0)
			return bt;
	}
	return l ? l : r;
}

char valueK(BTNode* bt, int k)
{
	return findK(bt, k)->data;
}

int main()
{
	Btree root = createTree();
	int k = 4;
	cout << valueK(root, k);

	return 0;
}