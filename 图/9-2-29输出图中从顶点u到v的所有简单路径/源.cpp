#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;

int visited[MAXSIZE] = { 0 };
int path[MAXSIZE] = { 0 };
//int rear = -1;

void DFS(AGraph* G, int u, int v, int depth)
{
	ArcNode* p = G->vertices[u].firstarc;
	visited[u] = 1;

	if (u == v)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << path[i];
		}
		cout << v << endl;
		visited[u] = 0;
		return;
	}

	while (p != NULL)
	{
		path[depth] = u;
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex, v, depth+1);
		p = p->nextarc;
	}
	visited[u] = 0;
}

int main()
{
	//AGraph* G = createGraph();
	//DFS(G, 0, 4, 0);
	AGraph* G = createNoCycleGraph();
	DFS(G, 1, 4, 0);

	return 0;
}