#pragma once
#include "TraveledPoint.h"

class LinkedTraveledPoint
{
public:
    TraveledPoint* point;
    LinkedTraveledPoint * next;
    LinkedTraveledPoint(TraveledPoint * coord, LinkedTraveledPoint * nextNode = nullptr)
    {
        point = coord;
        next = nextNode;

    }


};