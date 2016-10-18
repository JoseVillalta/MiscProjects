#include "stdafx.h"
#include "ComparisonTest.h"
#include "LinkedTraveledPoint.h"
#include "NearestNeighbor.h"
#include "ClosestPair.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void ComparisonTest::DoTests()
{
    Compare();
}

void ComparisonTest::Compare()
{
    nn_count = 0;
    cp_count = 0;
    for (int i = 0; i < 50; i++)
    {
        auto nn = new NearestNeighbor();
        auto cp = new ClosestPair();
        auto v = getRandomVector(100, 500);
        auto start = getRandomStartingPoint(500);

        nn->traverse(start, v);
        auto nnDistance = nn->totalDistanceTraveled;
        cp->traverse(start, v);
        auto cpDistance = cp->m_dTraveledDistance;

        cout << "Nearest Neighbor distance: " << nnDistance << endl;
        cout << "Closest Pair distance: " << cpDistance << endl;

        nnDistance < cpDistance ? nn_count++ : cp_count++;
        delete nn;
        delete cp;
    }
    
    cout << "Nearest Neighbor Count is: " << nn_count << endl;
    cout << "Closest Pair is :" << cp_count << endl;


}

vector<Coordinate> ComparisonTest::getRandomVector(unsigned int size, int upperLimit)
{
    vector<Coordinate> v;
    for (unsigned int i = 0; i < size; i++)
    {
        Coordinate c;
        c.m_x = rand() % upperLimit;
        c.m_y = rand() % upperLimit;
        v.push_back(c);
    }

    return v;
}

Coordinate ComparisonTest::getRandomStartingPoint(int upperLimit)
{
    Coordinate c;
    c.m_x = rand() % upperLimit;
    c.m_y = rand() % upperLimit;
    return c;
}