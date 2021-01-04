#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;

int visited[MAXSIZE] = { 0 };

void DFS(AGraph* G, int v)
{
	ArcNode* p;
	visited[v] = 1;
	cout << v;
	p = G->vertices[v].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

int main()
{
	AGraph* G = createGraph();
	for (int i = 0; i < G->vexnum; i++)
		if (visited[i] == 0)
		{
			DFS(G, i);
			cout << endl;
		}
	
	return 0;
}