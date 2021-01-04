#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

int isAVL(BTNode* bt, bool &value)
{
	int left = 0, right = 0;
	if (bt == NULL)
		return 0;
	left = isAVL(bt->lchild, value);
	right = isAVL(bt->rchild, value);
	
	//�ж�ƽ�������Ƿ���-1~1֮��
	if (left - right > 1 || left - right < -1)//��ƽ��
		value = false;
	else
		value = true;

	return (left > right ? left : right) + 1;
}

int main()
{
	Btree root = createTree();
	bool value = false;
	isAVL(root, value);
	cout << value;

	return 0;
}