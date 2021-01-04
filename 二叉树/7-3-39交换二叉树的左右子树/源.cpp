#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

void exchange(BTNode* bt)
{
	BTNode* p = NULL;
	if (bt != NULL)
	{
		exchange(bt->lchild);
		exchange(bt->rchild);

		p = bt->lchild;
		bt->lchild = bt->rchild;
		bt->rchild = p;
	}
}

int main()
{
	Btree root = createTree();
	exchange(root);

	return 0;
}