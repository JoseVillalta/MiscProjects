#include "stdafx.h"
#include "CalcOnOrOff.h"
#include "cmath"

bool CalcOnOrOff(unsigned int n)
{
    unsigned int x = sqrt(n);

    if (n == x*x) return true;
    return false; 
  
}