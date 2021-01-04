#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;

int edgenum = 0, vertexnum = 0;
int visited[MAXSIZE] = { 0 };

void DFS(AGraph* G, int v)
{
	ArcNode* p = G->vertices[v].firstarc;
	visited[v] = 1;
	vertexnum++;
	while (p != NULL)
	{
		edgenum++;
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

bool judgeTree(AGraph* G)
{
	DFS(G, 0);
	if (edgenum == 2 * (G->vexnum - 1) && vertexnum == G->vexnum)
		return true;
	return false;
}

int main()
{
	AGraph* G = createTreeGraph();
	cout << judgeTree(G);

	return 0;
}