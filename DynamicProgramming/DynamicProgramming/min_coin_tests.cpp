#include "stdafx.h"
#include "min_coin_tests.h"
#include "min_coin_change.h"
#include <iostream>

using namespace std;

void TestMinCoinChange()
{
	cout << "Testing Minimum Coin Change" << endl;

	vector<int> coins = { 1,6,10 };
	int result = FindMinCoins(coins, 24);

	_ASSERT(result == 4);

	coins = { 1,2,5,10 };
	result = FindMinCoins(coins, 12);
	_ASSERT(result == 2);

	cout << "Test complete" << endl;


}