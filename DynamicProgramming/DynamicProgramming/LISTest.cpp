#include "stdafx.h"
#include "LISTest.h"
#include "LongestIncreasingSubsequence.h"
#include <iostream>

void RunLISTest()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	//auto result = lis_r(arr, 8);
	//int arr[] = { 7,2,3};
	//auto result = lis_r(arr, 3);
	auto result = lis(arr, 8);
	std::cout << "The Longest Increasing Subsequence is: " << result << std::endl;

}
