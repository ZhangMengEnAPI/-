#include "createTree.h"
#include <iostream>
#include "traverse.h"
#include "traverseByNonrecursion.h"
using namespace std;

int main()
{
	/*Btree bt = NULL;
	createTreeByYinYong(bt);
	preOrder(bt);

	cout << '\n';
	int ch;
	cin >> ch;*/

	//Btree root = new BTNode;	
	//createTreeByOnePoint(&root);
	//preOrder1(&root); //OK
	//preOrder(root); //OK
	//preOrderByNonrecursion(root);
	//inOrderByNonrecursion(root);


	Btree T = createTree();
	preOrder(T);

	return 0;
}