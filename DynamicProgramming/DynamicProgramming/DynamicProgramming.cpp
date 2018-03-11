// DynamicProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestFibonacci.h"
#include "BinCoTest.h"
#include "EditDistanceTest.h"
#include "LISTest.h"
#include "PartitionTest.h"
#include "LongestCommonSubstringTest.h"
#include "LCSTest.h"
#include "CoinChangeTest.h"
#include "min_coin_tests.h"
#include "knapsack_tests.h"

int main()
{
	RunTests();
	RunBinCoTest();
	RunEditDistanceTests();
	RunLISTest();
	RunPartitionProblemTest();
	LongestCommonSubstringTest();
	auto cctest = new CoinChangeTests();
	cctest->DoTests();
	LCSTest();
	TestMinCoinChange();
	KnapsackTests();
    return 0;
}

