#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

int nodeLevel(BTNode* bt, char x, int level)
{
	int llevel = 0, rlevel = 0;
	if (bt == NULL)
		return 0;
	else
	{
		if (bt->data == x)
			return level;
		llevel = nodeLevel(bt->lchild, x, level+1);
		if (llevel != 0)
			return llevel;
		else
			rlevel = nodeLevel(bt->rchild, x, level+1);
		if (rlevel != 0)
			return rlevel;
	}
}

int main()
{
	Btree root = createTree();
	cout << nodeLevel(root, 'C', 1);

	return 0;
}