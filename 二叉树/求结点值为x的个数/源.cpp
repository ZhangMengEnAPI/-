#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

int xNum(BTNode* bt, char x)
{
	int lnum, rnum;

	if (bt == NULL)
		return 0;
	else
	{
		lnum = xNum(bt->lchild, x);
		rnum = xNum(bt->rchild, x);
		if (bt->data == x)
			return lnum + rnum + 1;
		else
			return lnum + rnum;
	}
}

int main()
{
	Btree root = createTree();
	char c = 'C';
	cout << xNum(root, c);

	return 0;
}