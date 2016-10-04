#include "stdafx.h"
#include "NearestNeighborTests.h"
#include "NearestNeighbor.h"
#include "Coordinate.h"
#include <iostream>
#include <vector>

using namespace std;

void NearestNeighborTest::DoTests()
{
    TestGetClosestNeighbor();
}

void NearestNeighborTest::TestGetClosestNeighbor()
{
    cout << "Test get closest neighbor" << endl;
    auto nn = new NearestNeighbor();
    auto startingPoint = Coordinate(0, 0);
    
    vector<Coordinate> v;
    v.push_back(Coordinate(10, 10));
    v.push_back(Coordinate(10, 30));
    v.push_back(Coordinate(30, 10));
    v.push_back(Coordinate(30, 30));

    auto nearest = nn->getNearestNeighbor(startingPoint, v);

    _ASSERT(nearest.m_x == 10);
    _ASSERT(nearest.m_y == 10);

    startingPoint.m_x = 40;
    nearest = nn->getNearestNeighbor(startingPoint, v);

    _ASSERT(nearest.m_x == 30);
    _ASSERT(nearest.m_y == 10);

    v.push_back(Coordinate(-1, -2));
    startingPoint.m_x = 0;
    startingPoint.m_y = 0;
    nearest = nn->getNearestNeighbor(startingPoint, v);
    _ASSERT(nearest.m_x == -1);
    _ASSERT(nearest.m_y == -2);


    cout << "Get closest neighbor finished successfully" << endl;
}