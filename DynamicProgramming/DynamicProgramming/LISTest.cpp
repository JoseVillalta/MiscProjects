#include "stdafx.h"
#include "LISTest.h"
#include "LongestIncreasingSubsequence.h"
#include <iostream>

void RunLISTest()
{
	//int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	//auto result = lis_r(arr, 8);
	//int arr[] = { 7,2,3};
	//auto result = lis_r(arr, 3);

	int arr[] = { 10, 29471, 5242, 21175, 28931, 2889, 7275, 19159,	21773, 1325, 6901 };
	auto result = lis(arr, 11);
	std::cout << "The Longest Increasing Subsequence is: " << result.val << std::endl;
	printLIS(result.parent, arr);
	std::cout << std::endl;

}
