#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

int calculateBF(BTNode* bt)
{
	int left = 0, right = 0;
	if (bt == NULL)
		return 0;
	left = calculateBF(bt->lchild);
	right = calculateBF(bt->rchild);
	cout << bt->data << ": " << left - right << endl;
	return (left > right ? left : right) + 1;
	
}

int main()
{
	Btree root = createTree();
	calculateBF(root);


	return 0;
}