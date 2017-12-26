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

int main()
{
	RunTests();
	RunBinCoTest();
	RunEditDistanceTests();
	RunLISTest();
	RunPartitionProblemTest();
	LongestCommonSubstringTest();
	LCSTest();
    return 0;
}

