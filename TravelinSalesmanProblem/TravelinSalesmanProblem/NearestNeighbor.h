#pragma once
#include <vector>
#include "Coordinate.h"

using namespace std;

class NearestNeighbor
{
public:
    void traverse(Coordinate startingPoint, vector<Coordinate> v);
    Coordinate getNearestNeighbor(Coordinate start, vector<Coordinate> v);
    int distanceTraveled;

};