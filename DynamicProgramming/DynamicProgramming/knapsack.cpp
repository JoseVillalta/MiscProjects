#include "stdafx.h"
#include "knapsack.h"
#include <iostream>
#define MAXN 1000
cell m[MAXN][MAXN];

void Init(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m[i][j].val = 0;
			m[i][j].parent = 0;
		}
	}
}

void PrintSubset(int row, int col)
{
	if (row == 0 || col == 0) return;

	PrintSubset(row - 1, col - m[row][col].parent);
	cout << m[row][col].parent << " ";
}

void Knapsack(vector<int> values, int target)
{

	Init(values.size(), target + 1);

	int i, j;

	for ( i = 1; i < values.size(); i++)
	{
		for (j = 1; j <= target; j++)
		{
			if (values[i] <= j)
			{
				if (m[i - 1][j].val > m[i - 1][j - values[i]].val + values[i])
				{
					m[i][j].val = m[i - 1][j].val;
					m[i][j].parent = m[i - 1][j].parent;
				}
				else
				{
					m[i][j].val = m[i - 1][j - values[i]].val + values[i];
					m[i][j].parent = values[i];
				}
			}
			else
			{
				m[i][j].val = m[i - 1][j].val;
				m[i][j].parent = m[i - 1][j].parent;
			}
		}
	}
	if (m[values.size()-1][target].val == target)
	{
		PrintSubset( values.size()-1, target);
	}
	else
	{
		cout << "Values don't add up to target value" << endl;
	}
}