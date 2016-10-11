// TravelinSalesmanProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NearestNeighborTests.h"
#include "ClosestPairTests.h"

int _tmain(int argc, _TCHAR* argv[])
{
    auto nnt = new NearestNeighborTest();
    auto cpt = new ClosestPairTests();

    nnt->DoTests();
    cpt->DoTests();
    return 0;
}

