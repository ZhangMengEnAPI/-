#include <iostream>
#include "createTree.h"
using namespace std;

BTNode* findK(BTNode* bt, int x)
{
	BTNode* l = NULL, * r = NULL;
	static int k = x;

	if (bt != NULL && k != 0)
	{
		l = findK(bt->lchild, k);
		k--;
		if (k == 0)
			return bt;
		else
			r = findK(bt->rchild, k);
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