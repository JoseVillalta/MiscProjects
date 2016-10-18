#include "stdafx.h"
#include "NearestNeighbor.h"
#include <math.h>
#include <iostream>
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

NearestNeighbor::NearestNeighbor()
{
    vector<TraveledPoint> traveledPath;
}

void NearestNeighbor::traverse(Coordinate startingPoint, vector<Coordinate> v)
{
    //first make a copy of the vector
    vector<Coordinate> coords;
    for (auto i : v)
    {
        coords.push_back(i);
    }

    auto curLoc = startingPoint;


    while (!coords.empty())
    {
        auto result = getNearestNeighbor(curLoc, coords);
        auto nearestN = get<0>(result);
        auto distance = get<1>(result);
        auto index = get<2>(result);
        traveledPath.push_back(TraveledPoint(nearestN, distance));
        totalDistanceTraveled += distance;
        coords.erase(coords.begin() + index);
        curLoc = nearestN;

       // std::cout << "X" << curLoc.m_x << " , Y" << curLoc.m_y <<"  distance: "<<distance<<std::endl;
        
    }

    //std::cout << "Total travleled distance" << totalDistanceTraveled << endl;

}

tuple<Coordinate,double,int> NearestNeighbor::getNearestNeighbor(Coordinate start, vector<Coordinate> v)
{
    double minDistance = 100000;
    auto nearestCoord = start;
    int index = 0;
    int nearestIndex = 0;
    for (auto i : v)
    {
        int x = abs(i.m_x - start.m_x);
        int y = abs(i.m_y - start.m_y);
        double distance = sqrt(x*x + y*y);
        if (distance < minDistance)
        {
            minDistance = distance;
            nearestCoord = i;
            nearestIndex = index;
        }
        index++;
    }
    return make_tuple(nearestCoord, minDistance, nearestIndex);
}