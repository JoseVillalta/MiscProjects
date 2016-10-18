#pragma once
#include "Coordinate.h"
#include <vector>

using namespace std;

class ComparisonTest
{
public:
    void DoTests();
private:
    void Compare();
    vector<Coordinate> getRandomVector(unsigned int size, int upperLimit);
    Coordinate getRandomStartingPoint(int upperLimit);
    int nn_count;
    int cp_count;
    
};