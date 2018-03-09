#include "stdafx.h"
#include "stdafx.h"
#include "LongestCommonSubsequence.h"
#include <vector>

using namespace std;

typedef struct
{
	int val;
	int parX;
	int parY;
	int x;
	int y;
	bool match;
}cell;

cell c[NMAX + 1][NMAX + 1];

void init_cells()
{
	for (int i = 0; i<= NMAX; i++)
	{
		for (int j = 0; j<=NMAX; j++)
		{
			c[i][j].val = 0;
			c[i][j].parX = -1;
			c[i][j].parY = -1;
			c[i][j].x = i;
			c[i][j].y = j;
			c[i][j].match = false;
		}
	}
}

cell GetMaxCell(cell x, cell y)
{
	if (x.val >= y.val) return x;
	return y;
}

vector<int> rebuild_pattern(int x, int y, vector<int> s)
{
	vector<int> result;
	while (x>0 && y>0)
	{
		if (c[x][y].match == true)
		{
			result.push_back(s[x]);
			x--;
			y--;
		}
		else
		{
			x = c[x][y].parX;
			y = c[x][y].parY;
		}
	}
	return result;
}

vector<int> GetLCS(vector<int> x, vector<int> y)
{
	vector<int> result;
	init_cells();

	for (int i = 1; i<x.size(); i++)
	{
		for (int j = 1; j<y.size(); j++)
		{
			if (x[i] == y[j])
			{
				c[i][j].val = c[i - 1][j - 1].val + 1;
				c[i][j].parX = i - 1;
				c[i][j].parY = j - 1;
				c[i][j].match = true;
			}
			else
			{
				auto cellR = GetMaxCell(c[i - 1][j], c[i][j - 1]);

				c[i][j].val = cellR.val;
				c[i][j].parX = cellR.x;
				c[i][j].parY = cellR.y;
				c[i][j].match = false;
			}
		}
	}

	result = rebuild_pattern(x.size()-1,y.size()-1, x);
	return result;
}