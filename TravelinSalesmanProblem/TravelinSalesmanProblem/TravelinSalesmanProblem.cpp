// TravelinSalesmanProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NearestNeighborTests.h"
#include "ClosestPairTests.h"
#include "ComparisonTest.h"

int _tmain(int argc, _TCHAR* argv[])
{
    auto nnt = new NearestNeighborTest();
    auto cpt = new ClosestPairTests();
    auto comp = new ComparisonTest();

    nnt->DoTests();
    cpt->DoTests();
    comp->DoTests();
    return 0;
}

