#pragma once
#include "LinkedTraveledPoint.h"
#include "NearestNeighbor.h"
#include <tuple>
#include <vector>

using namespace std;

class ClosestPair
{
public:
    LinkedTraveledPoint * traverse(Coordinate start, vector<Coordinate> v);
    ClosestPair();
    tuple<LinkedTraveledPoint *,LinkedTraveledPoint *, int> getClosestPair(LinkedTraveledPoint * p1, LinkedTraveledPoint * p2, vector<Coordinate> v);
    double m_dTraveledDistance;
private:
    NearestNeighbor * m_nn;
};