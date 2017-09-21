// DynamicProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestFibonacci.h"
#include "BinCoTest.h"
#include "EditDistanceTest.h"
#include "LISTest.h"

int main()
{
	RunTests();
	RunBinCoTest();
	RunEditDistanceTests();
	RunLISTest();
    return 0;
}

