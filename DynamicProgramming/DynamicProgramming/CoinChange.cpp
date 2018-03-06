#include "stdafx.h"
#include "CoinChange.h"

long GetChange(vector<int> coins, int amount)
{
	if (coins.empty()) return 0;
	if (amount == 0) return 0;

	vector<long> amounts = vector<long>(amount+1, 0);
	amounts[0] = 1;

	for (auto coin : coins)
	{
		int index = 1;
		while (index <= amount)
		{
			if (index >= coin)
			{
				amounts[index] += amounts[index - coin];
			}
			index++;
		}		
	}

	return amounts[amount];

}