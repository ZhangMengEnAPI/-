#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grapph.h"
using namespace std;
/*
1������ͼ 
	��DFS��visited[]����0,1״̬�Ͻ������䣬0��ʾΪ���ʹ���1��ʾ�ѷ��ʵ���û��������������ܳ��ֵĻ�·
	������û�˳�ϵͳջ���������ӽ�㻹�ڷ��ʵ�״̬����2��ʾ�ý���Ѿ��˳�ϵͳջ�������ڵݹ���У���
	����DFS������v����ʱ�����Ϊ1��Ȼ������ӽ�㣬����ӽ�㱻���ʹ��ˣ����ӽ�����״̬Ϊ1���ʾ�л�·��
	����ӽ��״̬Ϊ2������˵������㡣�ڼ����˳��ݹ��ʱ���������Ϊ2��Ȼ���˳�ϵͳջ��������һ�㡣

2������ͼ ����˫��ߵ����

1.��������ͼ

�����DFS�����м�鵽�رߴ������������

1�����ڻ�

2������˫��ߡ�
	��ʱҪ���˵�˫��ߡ���DFS�����ⲿ���ñ���i���������no[N]������ʼ��Ϊ0��
	����DFSʱ��i++����ʾ������һ���µ�˫�׽�㣩������ĳ������a���������i��Ȼ����ʺ��ӽ��b��
	������ӽ��bδ���ʹ�������DFS�ݹ�֮ǰ��b�ı������Ϊi+1��������ʹ���������һ�����c��
	���ĺ��ӽ��d�Ѿ������ʹ�����d�ı��+1����c�ı�ţ�֤��Ϊ˫��ߣ�����Ϊ��·��
	�˳�һ��DFS����ʱ��i--����ʾ�ص���˫�׽�㡣
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
		else if (visited[p->adjvex] == 1 && p->adjvex != parent)//��˫���
			cout << "���ڻ�";

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