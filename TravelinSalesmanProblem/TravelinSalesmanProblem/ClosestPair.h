#pragma once
#include "LinkedTraveledPoint.h"
#include "NearestNeighbor.h"
#include <tuple>
#include <vector>

using namespace std;

class ClosestPair
{
public:
    void traverse();
    ClosestPair();
    tuple<LinkedTraveledPoint *, int> getClosestPair(LinkedTraveledPoint * p1, LinkedTraveledPoint * p2, vector<Coordinate> v);
private:
    NearestNeighbor * m_nn;
};