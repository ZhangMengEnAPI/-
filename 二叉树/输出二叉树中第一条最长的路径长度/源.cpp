#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;
#define MAXSIZE 50

char path[MAXSIZE] = { '0' };
char maxpath[MAXSIZE] = { '0' };
int maxdepth = 1;

void findMaxPath(BTNode* bt, int depth)
{
	if (bt != NULL)
	{
		path[depth] = bt->data;
		if (bt->lchild == NULL && bt->rchild == NULL && depth > maxdepth)
		{
			for (int i = 0; i < depth; ++i)
				maxpath[i] = path[i + 1];
			maxdepth = depth;
		}
		findMaxPath(bt->lchild, depth + 1);
		findMaxPath(bt->rchild, depth + 1);
	}
}
int main()
{
	Btree root = createTree();
	findMaxPath(root, 1);
	for (int j = 0; j < maxdepth; ++j)
		cout << maxpath[j];

	return 0;
}