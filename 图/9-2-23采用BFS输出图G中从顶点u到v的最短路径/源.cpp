#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;

#define MAXSIZE 50

void shortestPath(AGraph* G, int u, int v)
{
	int queue[MAXSIZE] = { 0 };
	int front = -1, rear = -1;
	int visited[MAXSIZE] = { 0 };
	int k = -1;
	int path[MAXSIZE] = { 0 };
	int level = 0, right = -1;
	ArcNode* p = NULL;

	queue[++rear] = u;
	right = rear;
	visited[u] = 1;
	while (front != rear)
	{
		k = queue[++front];
		path[level] = k;
		p = G->vertices[k].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				if (p->adjvex == v)
				{
					for (int i = 0; i <= level; i++)
						cout << path[i];
					cout << v;
					break;
				}
				queue[++rear] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->nextarc;
		}
		if (front == right)
		{
			right = rear;
			level++;
		}
	}
}

int main()
{
	AGraph* G = createGraph();
	shortestPath(G, 2, 1);

	return 0;
}