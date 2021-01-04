#pragma once
#define __CREATETREE_H__

#include <iostream>
using namespace std;

typedef struct BTNode
{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;

}BTBode, * Btree;
//ǰ��������У�AB#D##C##

void createTreeByYinYong(BTBode* (&bt))//�������ã�Ҫ�ö���ָ�����
{
	char c;
	cin >> c;

	if (c == '#')
		bt = NULL;
	else
	{
		if (c == '0')
			return;
		else
		{
			bt = new BTNode;
			bt->data = c;
			createTreeByYinYong(bt->lchild);
			createTreeByYinYong(bt->rchild);
		}
	}
}

void createTreeByOnePoint(BTBode** bt)//һ��ָ�봫��Ļ���Ҫ�ö���ָ�����
{
	char c;
	cin >> c;

	if (c == '#')
		(*bt) = NULL;
	else
	{
		if (c == '0')
			return;
		else
		{
			(*bt) = new BTNode;
			(*bt)->data = c;
			createTreeByOnePoint(&(*bt)->lchild);
			createTreeByOnePoint(&(*bt)->rchild);
		}
	}
}

Btree createTree()//�Ƽ�
{
	char c;
	cin >> c;

	BTNode* bt;

	if (c == '#')
		bt = NULL;
	else
	{
		if (c == '0')
			return NULL;//������
		else
		{
			bt = new BTNode;
			bt->data = c;
			bt->lchild = createTree();
			bt->rchild = createTree();
		}
	}
	return bt;
}
