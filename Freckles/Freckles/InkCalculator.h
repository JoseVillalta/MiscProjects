#pragma once
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <math.h>
#define MAXV 100

using namespace std;


struct edge
{
	int x;
	int y;
	double weight;
	edge * next;
};

struct coord
{
	double x;
	double y;
};

struct unionSet
{
	int p[MAXV];
	int size[MAXV];
};

bool Compare(edge * lhs, edge * rhs)
{
	return (lhs->weight < rhs->weight);
}
class InkCalculator
{
public:
	InkCalculator()
	{
		s = new unionSet();
		for (int i = 0; i < MAXV; i++)
		{
			edges.push_back(nullptr);
			ink.push_back(0.0);
		}
	}
	~InkCalculator()
	{
		delete s;
	}
	void InsertPoint(double x, double y)
	{
		coord c;
		c.x = x;
		c.y = y;
		points.push_back(c);
	}
	void InitUnionSet()
	{
		for (int i = 0; i < numOfVertices; i++)
		{
			s->p[i] = i;
			s->size[i] = 1;
		}
	}
	int FindRootInSet(int x)
	{
		if (s->p[x] == x) return x;
		return FindRootInSet(s->p[x]);
	}
	bool SameComponent(int x, int y)
	{
		return (FindRootInSet(x) == FindRootInSet(y));
	}
	void UnionSet(int x, int y)
	{
		int r1 = FindRootInSet(x);
		int r2 = FindRootInSet(y);

		if (r1 == r2) return;
		if (s->size[r1] >= s->size[r2])
		{
			s->p[r2] = r1;
			s->size[r1] += s->size[r2];
		}
		else
		{
			s->p[r1] = r2;
			s->size[r2] += s->size[r1];
		}
	}
	double GetSolution()
	{
		numOfVertices = points.size();
		InitUnionSet();
		GetEdges();
		GetSortedEdgeArray();

		for (auto edge : sortedEdges)
		{
			int x = edge->x;
			int y = edge->y;
			if (!SameComponent(x, y))
			{
				UnionSet(x, y);
				ink.at(y) = edge->weight;
			}
		}

		double result = SumAllTheInk();
		return result;
	}
	void GetEdges()
	{
		for (int i = 0; i < numOfVertices; i++)
		{
			for (int j = 0; j < numOfVertices; j++)
			{
				if (i != j)
				{
					edge * currentEdge = new edge();
					currentEdge->x = i;
					currentEdge->y = j;
					currentEdge->weight = GetDistance(points.at(i), points.at(j));
					currentEdge->next = edges[i];
					edges[i] = currentEdge;
				}
			}
		}
	}
	void GetSortedEdgeArray()
	{
		for (auto edgePtr : edges)
		{
			while (edgePtr != nullptr)
			{
				sortedEdges.push_back(edgePtr);
				edgePtr = edgePtr->next;
			}
		}
		sort(sortedEdges.begin(), sortedEdges.end(), Compare);
	}

	double SumAllTheInk()
	{
		double sum = 0.0;
		for (auto i : ink)
		{
			sum += i;
		}
		return sum;
	}
	double GetDistance(coord a, coord b)
	{
		double x1 = abs(a.x - b.x);
		double y1 = abs(a.y - b.y);

		double xsqr = x1 * x1;
		double ysqr = y1 * y1;

		double distance = sqrt(xsqr + ysqr);
		return distance;
	}
	int numOfVertices;
	
	unionSet * s;
	vector<coord> points;
	vector<edge*> sortedEdges;
	vector<edge*> edges;
	vector<double> ink;
};
