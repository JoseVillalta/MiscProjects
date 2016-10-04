#pragma once
#include <vector>
#include <tuple>
#include "Coordinate.h"
#include "TraveledPoint.h"

using namespace std;

class NearestNeighbor
{
public:
    NearestNeighbor();
    void traverse(Coordinate startingPoint, vector<Coordinate> v);
    tuple<Coordinate,double,int> getNearestNeighbor(Coordinate start, vector<Coordinate> v);
    double totalDistanceTraveled;
    vector<TraveledPoint> traveledPath;

};