#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;
#define MAXSIZE	50

char path[MAXSIZE] = { '0' };

void findpath(BTNode* bt, int depth)
{
	if (bt != NULL)
	{
		path[depth] = bt->data;

		if (bt->lchild == NULL && bt->rchild == NULL)
		{
			for (int j = depth; j > 0; --j)
			{
				cout << path[j];
			}
			cout << endl;
		}
		findpath(bt->lchild, depth+1);
		findpath(bt->rchild, depth+1);
	}
}

int main()
{
	Btree root = createTree();
	findpath(root, 1);

	return 0;
}