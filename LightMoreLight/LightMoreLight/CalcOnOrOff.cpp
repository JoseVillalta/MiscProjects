#include "stdafx.h"
#include "CalcOnOrOff.h"

bool CalcOnOrOff(unsigned int n)
{
    bool isOn = false;
    int nFactors = 0;
    
    for(int i = 1; i<= n; i++)
    {
        auto r = n % i;
        if(r == 0)
        {
            nFactors++;
        }
    }

    if((nFactors % 2) == 0)
    {
        isOn = false;
    }
    else
    {
        isOn = true;
    }
    return isOn;
}