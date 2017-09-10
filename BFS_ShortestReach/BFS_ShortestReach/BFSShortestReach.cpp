#include "stdafx.h"
#include <queue>
#include <iostream>
#define MAXV 1000
using namespace std;

struct edgeNode
{
	int y;
	int weight;
	edgeNode * next;
};

typedef struct
{
	edgeNode * edges[MAXV + 1];
	int nvertices;
	int nedges;

}Graph;

class BFS
{
public:
	Graph * m_graph;
	bool discovered[MAXV];
	bool processed[MAXV];
	int parent[MAXV];

	BFS(int vertices, int edges)
	{
		m_graph = new Graph();
		m_graph->nvertices = vertices;
		m_graph->nedges = edges;
		for (int i = 1; i< MAXV; i++) m_graph->edges[i] = nullptr;
	}

	void InsertEdge(int x, int y, bool directed)
	{
		auto edge = new edgeNode();
		edge->weight = 6;
		edge->y = y;
		edge->next = m_graph->edges[x];
		m_graph->edges[x] = edge;

		if (!directed)
		{
			InsertEdge(y, x, true);
		}
	}
	void InitSearch()
	{
		for (int i = 1; i<MAXV; i++)
		{
			processed[i] = false;
			discovered[i] = false;
			parent[i] = -1;
		}
	}
	void BFSearch(int start)
	{
		auto q = new queue<int>();
		q->push(start);
		discovered[start] = true;
		int y;

		while (!q->empty())
		{
			int p = q->front();
			q->pop();
			auto edge = m_graph->edges[p];
			processed[p] = true;
			while (edge != nullptr)
			{
				y = edge->y;
				if (discovered[y] == false)
				{
					discovered[y] = true;
					parent[y] = p;
					q->push(y);
				}
				edge = edge->next;
			}
		}
	}
	void PrintOutput(int s)
	{
		for (int i = 1; i< m_graph->nvertices + 1; i++)
		{
			if(i != s)
			{
				int weight = 0;
				if (parent[i] == -1)
				{
					cout << "-1 ";
				}
				else
				{
					PrintWeight(s, i, &weight);
					cout << weight << " ";
				}
			}
				
		}
		cout << endl;
	}

	void PrintWeight(int start, int end, int * counter)
	{
		if ((start == end) || (end == -1))
		{
			return;
		}
		else
		{
			*counter += 6;
			PrintWeight(start, parent[end],counter);
		}

	}

};

int main() {
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++) {
		int n;
		int m;
		cin >> n >> m;
		auto bfs = new BFS(n, m);
		for (int a1 = 0; a1 < m; a1++) {
			int u;
			int v;
			cin >> u >> v;
			bfs->InsertEdge(u, v, false);
		}
		int s;
		cin >> s;
		bfs->InitSearch();
		bfs->BFSearch(s);
		bfs->PrintOutput(s);
	}
	return 0;
}
