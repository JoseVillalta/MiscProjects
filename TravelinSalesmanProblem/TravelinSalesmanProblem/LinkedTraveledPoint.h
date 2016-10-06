#pragma once
#include "TraveledPoint.h"

class LinkedTraveledPoint
{
public:
    TraveledPoint point;
    LinkedTraveledPoint * next;
};