#include "stdafx.h"
#include "CarryCounter.h"

int CalculateNumberCarry(int a, int b)
{
    auto arrA = ConvertToArray(a);
    auto arrB = ConvertToArray(b);

    int counter = 0;
    int hasCarry = 0;

    for(int i = 0; i<11; i++)
    {
        hasCarry = HasCarry(arrA[i], arrB[i], hasCarry);
        if(hasCarry == 1)
        {
            counter++;
        }
    }

    delete[] arrA;
    delete[] arrB;
    return counter;
}

int * ConvertToArray(int a)
{
    int *  array = new int[11];

    for(int j=0; j<11; j++)
    {
        array[j] = 0;
    }
   
    int i = 0;
    while(a > 0)
    {
        int digit = a % 10;
        array[i] = digit;
        a -= digit;
        a = a / 10;
        i++;
    }

    return array;
}

int HasCarry(int a, int b, int c)
{
    if( a + b + c >= 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}