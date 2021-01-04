#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

int nodeNum(BTNode * bt)
{
	int lnum = 0, rnum = 0;

	if (bt == NULL)
		return 0;
	else
	{
		lnum = nodeNum(bt->lchild);
		rnum = nodeNum(bt->rchild);
		return lnum + rnum + 1;//1为根结点本身
	}

}

int leafNum(BTNode* bt)
{
	int lnum = 0, rnum = 0;

	if (bt != NULL)
	{
		if (bt->lchild == NULL && bt->rchild == NULL)
			return 1;
		else
		{
			lnum = leafNum(bt->lchild);
			rnum = leafNum(bt->rchild);			
		}
	}
	return lnum + rnum;
}

int doubleBranchNodeNum(BTNode* bt)
{
	int lnum = 0, rnum = 0;

	if (bt != NULL)
	{
		lnum = doubleBranchNodeNum(bt->lchild);
		rnum = doubleBranchNodeNum(bt->rchild);
			
		if (bt->lchild != NULL && bt->rchild != NULL)
			return lnum + rnum + 1;
	}
	return 0;
}

int main()
{
	Btree root = createTree();
	cout << nodeNum(root);
	cout << endl;
	cout << leafNum(root);
	cout << endl;
	cout << doubleBranchNodeNum(root);

	return 0;
}