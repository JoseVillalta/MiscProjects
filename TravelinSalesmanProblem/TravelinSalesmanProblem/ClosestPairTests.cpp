#include "stdafx.h"
#include "ClosestPairTests.h"
#include "Coordinate.h"
#include <vector>

using namespace std;

void ClosestPairTests::DoTests()
{
    TestGetClosestPair();
}

void ClosestPairTests::TestGetClosestPair()
{
    Coordinate startingPoint = Coordinate(0, 10);
    
    vector<Coordinate> v;
    v.push_back(Coordinate(0, 0));
    v.push_back(Coordinate(12, 0));
    v.push_back(Coordinate(12, 10));
    v.push_back(Coordinate(24, 10));
    v.push_back(Coordinate(24, 0));


}