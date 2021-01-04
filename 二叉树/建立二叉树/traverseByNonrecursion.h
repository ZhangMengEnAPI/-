#pragma once
#define __TRAVERSEBYNONRECURSION_H__
using namespace std;
#include "createTree.h"
#define MAXSIZE 100

typedef struct
{
	BTNode* data[MAXSIZE];
	int top;
}stack;//˳��ջ

stack* initStack()
{
	stack* s = new stack;
	s->top = -1;

	return s;
}

void preOrderByNonrecursion(BTNode* bt)
{
	stack* s = initStack();

	while (s->top != -1 || bt != NULL)//��bt!=NULL����Ϊtop��ʼֵΪ-1
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
/*����ǵݹ�����㷨de˼��

���ھ�����������������=ԭ���������������

��������������������reverseһ�¼��ɡ�

*/
void postOrderByNonrecursion(BTNode* bt)
{
	stack* s = initStack();
}