#include <iostream>
#include "createTree.h"
using namespace std;

BTNode* findK(BTNode* bt, int x)
{
	BTNode* l = NULL, * r = NULL;
	static int k = x;

	if (bt == NULL)
		return NULL;
	else
	{
		k--;		
		if (k != 0)
		{			
			l = findK(bt->lchild, k);
			r = findK(bt->rchild, k);
		}
		else
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