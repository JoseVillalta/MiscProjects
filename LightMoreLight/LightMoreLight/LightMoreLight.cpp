// LightMoreLight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CalcOnOrOff.h"

using namespace std;


int main()
{
    int n;
    while(cin >> n )
    {
        if (n == 0) break;
        auto result = CalcOnOrOff(n);
        if(result)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}

