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
	
	//判断平衡因子是否在-1~1之间
	if (left - right > 1 || left - right < -1)//不平衡
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