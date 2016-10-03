#pragma once
#include <vector>
#include "Coordinate.h"

using namespace std;

class NearestNeighbor
{
    void traverse(Coordinate startingPoint, vector<Coordinate> v);
    int distanceTraveled;

};