#include "stdafx.h"
#include "min_coin_change.h"
#include <algorithm>
#define MAXN 1000


void init(int m[], vector<int> coins, int amount)
{
	for (int i = 0; i <= amount; i++) m[i] = MAXN;

	for (auto c : coins)
	{
		m[c] = 1;
	}
}

int FindMinCoins(vector<int> coins, int amount)
{
	int m[MAXN + 1];

	init(m, coins, amount);

	for (int i = 1; i <= amount; i++)
	{
		for (auto c : coins)
		{
			int val = i + c;
			if (val <= amount)
			{
				m[val] = min(m[i] + 1, m[val]);
			}
		}
	}
	return m[amount];
}