#include "stdafx.h"
#include "LCSTest.h"
#include "LongestCommonSubsequence.h"
#include <vector>
#include <iostream>

using namespace std;

void LCSTest()
{
	cout << "Longest Common Subsequence" << endl;
	vector<int> x = { 0,1,2,3,4,1 };
	vector<int> y = { 0,3,4,1,2,1,3 };

	auto result = GetLCS(x, y);

	for (auto i : result)
	{
		cout << i << " ";
	}
	cout << endl;
	_ASSERT(result.size() != 0);


}