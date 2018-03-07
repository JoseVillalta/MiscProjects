#pragma once
#include <iostream>
#define MAXV 51

using namespace std;

int g[MAXV][MAXV];
int degree[MAXV];

void InitG()
{
	for (int i = 1; i < MAXV; i++)
	{
		for (int j = 1; j < MAXV; j++)
		{
			g[i][j] = 0;
		}
		degree[i] = 0;
	}
}

void Insert(int start, int end)
{
	g[start][end]++;
	g[end][start]++;
	degree[start]++;
	degree[end]++;
}

bool CheckValid()
{
	bool valid = true;

	for (int i = 1; i < MAXV; i++)
	{
		if (degree[i] & 1)
		{
			valid = false;
			break;
		}
	}
	return valid;
}

void Dfs(int node)
{
	for (int i = 1; i < MAXV; i++)
	{
		if (g[node][i])
		{
			g[node][i]--;
			g[i][node]--;
			cout << node << " " << i << endl;
			Dfs(i);
		}
	}
}