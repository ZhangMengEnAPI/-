#pragma once
#define __TRAVERSEBYNONRECURSION_H__
using namespace std;
#include "createTree.h"
#define MAXSIZE 100

typedef struct
{
	BTNode* data[MAXSIZE];
	int top;
}stack;//顺序栈

stack* initStack()
{
	stack* s = new stack;
	s->top = -1;

	return s;
}

void preOrderByNonrecursion(BTNode* bt)
{
	stack* s = initStack();

	while (s->top != -1 || bt != NULL)//加bt!=NULL是因为top初始值为-1
	{
		while (bt != NULL)
		{
			cout << bt->data;
			s->data[++s->top] = bt;
			bt = bt->lchild;
		}
		
		if (s->top != -1)
		{
			bt = s->data[s->top--];
			bt = bt->rchild;
		}
	}
}

void inOrderByNonrecursion(BTNode* bt)
{
	stack* s = initStack();

	while (s->top != -1 || bt != NULL)
	{
		while (bt != NULL)
		{
			s->data[++s->top] = bt;
			bt = bt->lchild;
		}

		if (s->top != -1)
		{
			bt = s->data[s->top--];
			cout << bt->data;
			bt = bt->rchild;
		}
	}
}
/*后序非递归遍历算法de思想

由于镜像二叉树的先序遍历=原二叉树后序遍历，

可以先求出镜像先序，最后reverse一下即可。

*/
void postOrderByNonrecursion(BTNode* bt)
{
	stack* s = initStack();
}