#pragma
#include "Coordinate.h"

class TraveledPoint
{
public:
    Coordinate loc;
    //Distance to next location
    int dist;
    TraveledPoint(Coordinate coord, int distance)
    {
        loc = coord;
        dist = distance;
    }
};