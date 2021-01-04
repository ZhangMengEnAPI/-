#pragma once
#define __TRAVERSE_H__//�ݹ����

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

void preOrder1(BTNode** bt)//��һ��ָ�����������ָ�����
{
	if (*bt != NULL)
	{
		cout << (*bt)->data;
		preOrder1(&(*bt)->lchild);
		preOrder1(&(*bt)->rchild);
	}
}
