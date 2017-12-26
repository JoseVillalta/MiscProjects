#include "stdafx.h"
#include "LCSTest.h"
#include "LongestCommonSubsequence.h"
#include <vector>

using namespace std;

void LCSTest()
{
	vector<int> x = { 0,1,2,3,4,1 };
	vector<int> y = { 0,3,4,1,2,1,3 };

	auto result = GetLCS(x, y);

	_ASSERT(result.size() != 0);


}