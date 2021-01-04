#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;
/*
1）有向图 
	在DFS的visited[]数组0,1状态上进行扩充，0表示为访问过，1表示已访问但还没监测完这个顶点可能出现的回路
	（即还没退出系统栈，处于有子结点还在访问的状态），2表示该结点已经退出系统栈（即不在递归层中）。
	进入DFS函数对v访问时，标记为1，然后访问子结点，如果子结点被访问过了，且子结点访问状态为1则表示有回路，
	如果子结点状态为2，则过滤掉这个结点。在即将退出递归层时，将结点标记为2，然后退出系统栈，返回上一层。

2）无向图 存在双向边的情况

1.对于无向图

如果在DFS过程中检查到回边存在两种情况：

1）存在环

2）存在双向边。
	此时要过滤掉双向边。在DFS函数外部设置变量i，编号数组no[N]，并初始化为0。
	进入DFS时，i++（表示来到了一个新的双亲结点），访问某个顶点a，给它编号i，然后访问孩子结点b，
	如果孩子结点b未访问过，则在DFS递归之前将b的编号设置为i+1。如果访问过程中来到一个结点c，
	它的孩子结点d已经被访问过，且d的编号+1等于c的编号，证明为双向边，否则为回路。
	退出一层DFS函数时，i--，表示回到了双亲结点。
*/
int visited[MAXSIZE] = { 0 };

void hasCycle(AGraph* G, int v, int parent)
{
	ArcNode* p = G->vertices[v].firstarc;
	visited[v] = 1;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			hasCycle(G, p->adjvex, v);
		else if (visited[p->adjvex] == 1 && p->adjvex != parent)//非双向边
			cout << "存在环";

		p = p->nextarc;
	}
}

int main()
{
	AGraph* G = createNoCycleGraph();
	//AGraph* G = createGraph();	 
	hasCycle(G, 1, 0);

	return 0;
}