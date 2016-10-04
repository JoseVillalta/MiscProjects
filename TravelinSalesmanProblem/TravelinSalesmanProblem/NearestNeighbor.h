#pragma once
#include <vector>
#include <tuple>
#include "Coordinate.h"
#include "TraveledPoint.h"

using namespace std;

class NearestNeighbor
{
public:
    void traverse(Coordinate startingPoint, vector<Coordinate> v);
    tuple<Coordinate,double,int> getNearestNeighbor(Coordinate start, vector<Coordinate> v);
    int totalDistanceTraveled;
    vector<TraveledPoint> traveledPath;

};