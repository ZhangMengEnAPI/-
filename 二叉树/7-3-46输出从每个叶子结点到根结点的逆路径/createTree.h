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
//前序遍历序列：AB#D##C##

void createTreeByYinYong(BTBode* (&bt))//不加引用，要用二级指针接收
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

void createTreeByOnePoint(BTBode** bt)//一级指针传入的话，要用二级指针接收
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

Btree createTree()//推荐
{
	char c;
	cin >> c;

	BTNode* bt;

	if (c == '#')
		bt = NULL;
	else
	{
		if (c == '0')
			return NULL;//串结束
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
