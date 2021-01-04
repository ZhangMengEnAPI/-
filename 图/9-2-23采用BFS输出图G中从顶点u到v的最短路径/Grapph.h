#pragma once
#define __GRAPH_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAXSIZE	50

//邻接表
//边表节点
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
	int weight;
}ArcNode;
//顶点表节点
typedef struct VNode
{
	int data;//顶点信息
	ArcNode* firstarc;
}VNode, AdjList[MAXSIZE];
//表
typedef struct
{
	AdjList vertices;//vertex的复数
	int vexnum, arcnum;
}AGraph;

AGraph* createGraph()
{
	/*
		P330 9-2-18
		v0->1->2
		v1->2->3
		v2->3
		v3->4
		v4->0->2
	*/
	AGraph* G = new AGraph;
	G->arcnum = 9;
	G->vexnum = 4;
	//v0
	ArcNode* p = new ArcNode;
	p->adjvex = 1;
	G->vertices[0].firstarc = p;	
	p = new ArcNode;
	p->adjvex = 2;
	p->nextarc = NULL;
	G->vertices[0].firstarc->nextarc = p;
	//v1
	p = new ArcNode;
	p->adjvex = 2;
	G->vertices[1].firstarc = p;
	p = new ArcNode;
	p->adjvex = 3;
	p->nextarc = NULL;
	G->vertices[1].firstarc->nextarc = p;
	//v2
	p = new ArcNode;
	p->adjvex = 3;
	p->nextarc = NULL;
	G->vertices[2].firstarc = p;
	//v3
	p = new ArcNode;
	p->adjvex = 4;
	p->nextarc = NULL;
	G->vertices[3].firstarc = p;
	//v4
	p = new ArcNode;
	p->adjvex = 0;
	G->vertices[4].firstarc = p;
	p = new ArcNode;
	p->adjvex = 2;
	p->nextarc = NULL;
	G->vertices[4].firstarc->nextarc = p;

	return G;
}
