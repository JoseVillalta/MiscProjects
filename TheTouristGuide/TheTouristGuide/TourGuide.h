#pragma once
#include "stdafx.h"
#include <algorithm>
#define MAXV 100
#define INFINITY_MINE 100000
 struct edge
{
	int y;
	int cap;
	edge * next;
 };

class TourGuide
{
private:
	int numOfVertices;
	int cost[MAXV + 1];
	int parent[MAXV + 1];
	edge * edges[MAXV + 1];
public:
	TourGuide(int nVertices)
	{
		numOfVertices = nVertices;
		for (int i = 1; i <= nVertices; i++)
		{
			cost[i] = -1;
			parent[i] = -1;
			edges[i] = nullptr;
		}
	}
	void InsertEdge(int x, int y, int cap)
	{
		auto e1 = new edge();
		e1->y = y;
		e1->cap = cap;
		e1->next = edges[x];
		edges[x] = e1;

		auto e2 = new edge();
		e2->y = x;
		e2->cap = cap;
		e2->next = edges[y];
		edges[y] = e2;
	}

	int FindPath(int start, int end, int passangers)
	{
		bool updating = true;
		int result;
		cost[start] = INFINITY_MINE;

		while (updating)
		{
			updating = false;
			for (int x = 1; x <= numOfVertices; x++)
			{
				if (cost[x] > 0)
				{
					auto neighborEdges = edges[x];
					while (neighborEdges != nullptr)
					{
						int y = neighborEdges->y;
						int edgeCap = neighborEdges->cap;
						int minInPath = std::min(edgeCap, cost[x]);
						if (minInPath > cost[y])
						{
							cost[y] = minInPath;
							parent[y] = x;
							updating = true;
						}
						neighborEdges = neighborEdges->next;
					}
				}
			}
		}

		int minPathCap = cost[end];
		result = CalculateNumTrips(minPathCap, passangers);
		return result;
	}

	int CalculateNumTrips(int capacity, int passengers)
	{
		double cap = (double)(capacity -1);
		double pass = (double)(passengers);

		int result = ceil(pass / cap);
		return result;
	}

};
