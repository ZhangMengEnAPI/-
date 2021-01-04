/* 
* �ݹ������
1.��ֹ������
	1.��Խ��Ҷ�ڵ㣬��ֱ�ӷ��� null ��
	2.�� root ���� p,q ����ֱ�ӷ��� root ��
2.���ƹ�����
	1.�����ݹ����ӽڵ㣬����ֵ��Ϊ left ��
	2.�����ݹ����ӽڵ㣬����ֵ��Ϊ right ��
3.����ֵ�� ���� left �� right ����չ��Ϊ���������
	1.�� left �� right ͬʱΪ�� ��˵�� root ���� / �������ж������� p,q ������ null ��
	2.�� left �� right ͬʱ��Ϊ�� ��˵�� p,q ������ root �� ��� ���ֱ��� �� / ������������� root Ϊ����������ȣ����� root ��
	3.�� left Ϊ�� ��right ��Ϊ�� ��p,q ������ root ���������У�ֱ�ӷ��� right ������ɷ�Ϊ���������
		1.p,q ����һ���� root �� ������ �У���ʱ right ָ�� p������Ϊ p ����
		2.p,q ���ڵ㶼�� root �� ������ �У���ʱ�� right ָ�� ����������Ƚڵ� ��
	4.�� left ��Ϊ�� �� right Ϊ�� ������� 3. ͬ��

���ߣ�jyd
���ӣ�https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "createTree.h"
using namespace std;

BTNode* findNearestCommonAncestor(BTNode* bt, char p, char q)
{
	if (bt == NULL || bt->data == p || bt->data == q)
		return bt;
	BTNode* left = findNearestCommonAncestor(bt->lchild, p, q);
	BTNode* right = findNearestCommonAncestor(bt->rchild, p, q);
	if (left == NULL)
		return right;
	if (right == NULL)
		return left;
	return bt;
}

int main()
{
	Btree root = createTree();
	cout << findNearestCommonAncestor(root, 'H', 'G')->data;

	return 0;
}