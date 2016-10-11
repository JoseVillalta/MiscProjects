#include "stdafx.h"
#include "ClosestPairTests.h"
#include "Coordinate.h"
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

void ClosestPairTests::DoTests()
{
    TestGetClosestPair();
}

void ClosestPairTests::TestGetClosestPair()
{
    cout << "Start of Test for Closest Pair TSP Heuristic" << endl;
    ClosestPair * cp = new ClosestPair();
    LinkedTraveledPoint start = LinkedTraveledPoint(&TraveledPoint(Coordinate(0, 10), 0));
    
    vector<Coordinate> v;
    v.push_back(Coordinate(0, 0));
    v.push_back(Coordinate(12, 0));
    v.push_back(Coordinate(12, 10));
    v.push_back(Coordinate(24, 10));
    v.push_back(Coordinate(24, 0));

    LinkedTraveledPoint * p1 = &start;
    LinkedTraveledPoint * p2 = &start;

    auto result = cp->getClosestPair(p1, p2, v);
    LinkedTraveledPoint * r1 = get<0>(result);
    _ASSERT(r1->next == nullptr);
    _ASSERT(p1->next == r1);
    _ASSERT(r1->point->loc.m_x == 0);
    _ASSERT(r1->point->loc.m_y == 0);

    v.erase(v.begin()+get<1>(result));

    result = cp->getClosestPair(p1, r1, v);
    LinkedTraveledPoint * r2 = get<0>(result);
    _ASSERT(r2->next == nullptr);
    _ASSERT(r1->next == r2);
    _ASSERT(r2->point->loc.m_x == 12);
    _ASSERT(r2->point->loc.m_y == 0);

    cout<< "End of Closest Pair Test" << endl;



}