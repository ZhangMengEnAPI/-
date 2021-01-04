#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

void findparent(BTNode* b, char x, BTNode*& p)
{
	if (b == NULL)
		return;
	else
	{
		if (b->lchild != NULL)
			if (b->lchild->data == x)
			{
				p = b;
				return;
			}
		if (b->rchild != NULL)
			if (b->rchild->data == x)
			{
				p = b;
				return;
			}
		
		findparent(b->lchild, x, p);
		findparent(b->rchild, x, p);

	}

}

int main()
{
	Btree root = createTree();
	BTNode* parent = NULL;
	findparent(root, 'C', parent);
	if(parent != NULL)
		cout << parent->data;

	return 0;
}