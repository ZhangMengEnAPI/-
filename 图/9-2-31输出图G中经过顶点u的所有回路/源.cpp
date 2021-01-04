#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;

int visited[MAXSIZE] = { 0 };
int path[MAXSIZE] = { 0 };

void allCycle(AGraph* G, int u, int v, int parent, int level)
{
	ArcNode* p = G->vertices[u].firstarc;
	visited[u] = 1;
	while (p != NULL)
	{
		path[level] = u;
		if (visited[p->adjvex] == 1 && p->adjvex != parent && p->adjvex == v)
		{
			for (int i = 0; i <= level; i++)
			{
				cout << path[i];
			}
			cout << v << endl;
			visited[u] = 0;
		}
		if (visited[p->adjvex] == 0)
			allCycle(G, p->adjvex, v, u, level+1);
		p = p->nextarc;
	}
	visited[u] = 0;
}

int main()
{
	//AGraph* G = createGraph();
	//allCycle(G, 0, 0, 0, 0);

	AGraph* G = createNoCycleGraph();
	allCycle(G, 1, 1, 0, 0);

	return 0;
}