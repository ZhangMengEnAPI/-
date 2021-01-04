#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;

#define MAXSIZE 50

int maxDistance(AGraph* G, int v)
{
	int queue[MAXSIZE] = { 0 };
	int front = -1, rear = -1;
	ArcNode* p = NULL;
	int visited[MAXSIZE] = { 0 };

	queue[++rear] = v;
	visited[v] = 1;
	while (front != rear)
	{
		v = queue[++front];
		p = G->vertices[v].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				queue[++rear] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->nextarc;
		}
	}
	return queue[front];
}

int main()
{
	AGraph* G = createGraph();
	cout << maxDistance(G, 1);

	return 0;
}