#include "stdafx.h"
#include "LongestCommonSubstringTest.h"
#include <string>
#include <iostream>
using namespace std;

void LongestCommonSubstringTest()
{
	cout << "Start of Longest Common Substring" << endl;
	string s = " Topograph";
	string t = " Photography";

	string lcs = GetLongestCommonSubstring(s, t);
	cout << "Longest common substring is " << lcs << endl;
}
