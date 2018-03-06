#include "stdafx.h"
#include "CoinChangeTest.h"

using namespace std;

void CoinChangeTests::DoTests()
{
	vector<int> coins = { 1,2,5 };
	auto result = GetChange(coins, 5);
	_ASSERT(result == 4);

	result = GetChange(coins, 12);
	_ASSERT(result == 13);
}