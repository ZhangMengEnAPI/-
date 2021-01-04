#pragma once
#define __TRAVERSE_H__//递归遍历

#include "createTree.h"

void preOrder(BTNode* bt)
{
	if (bt != NULL)
	{
		cout << bt->data;
		preOrder(bt->lchild);
		preOrder(bt->rchild);
	}
}

void preOrder1(BTNode** bt)//传一级指针进来，二级指针接收
{
	if (*bt != NULL)
	{
		cout << (*bt)->data;
		preOrder1(&(*bt)->lchild);
		preOrder1(&(*bt)->rchild);
	}
}
