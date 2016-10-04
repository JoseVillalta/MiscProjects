#include "stdafx.h"
#include "NearestNeighborTests.h"
#include "NearestNeighbor.h"
#include "Coordinate.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void NearestNeighborTest::DoTests()
{
    TestGetClosestNeighbor();
    TestTSP();
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
    _ASSERT(get<0>(nearest).m_x == 10);
    _ASSERT(get<0>(nearest).m_y == 10);
    //distance should be sqrt(x^2 + y^2)
    _ASSERT(get<1>(nearest) == sqrt(200));
    _ASSERT(get<2>(nearest) == 0);

    startingPoint.m_x = 40;
    nearest = nn->getNearestNeighbor(startingPoint, v);

    _ASSERT(get<0>(nearest).m_x == 30);
    _ASSERT(get<0>(nearest).m_y == 10);
    _ASSERT(get<1>(nearest) == sqrt(200));
    _ASSERT(get<2>(nearest) == 2);

    v.push_back(Coordinate(-1, -2));
    startingPoint.m_x = 0;
    startingPoint.m_y = 0;
    nearest = nn->getNearestNeighbor(startingPoint, v);
    _ASSERT(get<0>(nearest).m_x == -1);
    _ASSERT(get<0>(nearest).m_y == -2);
    _ASSERT(get<1>(nearest) == sqrt(5));
    _ASSERT(get<2>(nearest) == 4);


    cout << "Get closest neighbor finished successfully" << endl;
}

void NearestNeighborTest::TestTSP()
{
    cout << "Test TSP" << endl;
    auto nn = new NearestNeighbor();
    auto startingPoint = Coordinate(0, 0);
    vector<Coordinate> v;
    v.push_back(Coordinate(10, 10));
    v.push_back(Coordinate(10, 30));
    v.push_back(Coordinate(30, 10));
    v.push_back(Coordinate(30, 30));

    nn->traverse(startingPoint, v);
}