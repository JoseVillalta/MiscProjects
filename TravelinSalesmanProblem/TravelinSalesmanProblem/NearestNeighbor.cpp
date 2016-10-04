#include "stdafx.h"
#include "NearestNeighbor.h"
#include <math.h>

/*
Pick and visit an initial point p0 from P
p = p0
i = 0
While there are still unvisited points
i = i + 1
Select pi to be the closest unvisited point to pi−1
Visit pi
Return to p0 from pn−1
*/
void NearestNeighbor::traverse(Coordinate startingPoint, vector<Coordinate> v)
{

}

Coordinate NearestNeighbor::getNearestNeighbor(Coordinate start, vector<Coordinate> v)
{
    double minDistance = 100000;
    auto nearestCoord = start;
    for (auto i : v)
    {
        int x = abs(i.m_x - start.m_x);
        int y = abs(i.m_y - start.m_y);
        double distance = sqrt(x*x + y*y);
        if (distance < minDistance)
        {
            minDistance = distance;
            nearestCoord = i;
        }
    }
    return nearestCoord;
}