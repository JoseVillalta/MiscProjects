#pragma once
#include "Coordinate.h"

class TraveledPoint
{
public:
    Coordinate loc;
    //Distance to next location
    double dist;
    TraveledPoint(Coordinate coord, double distance)
    {
        loc = coord;
        dist = distance;
    }
};