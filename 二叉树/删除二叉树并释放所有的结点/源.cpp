#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

void deleteTree(BTNode* bt)
{
	if (bt == NULL)
		return;
	else
	{
		deleteTree(bt->lchild);
		deleteTree(bt->rchild);
		free(bt);
	}
}

int main()
{
	Btree root = createTree();
	deleteTree(root);

	return 0;
}