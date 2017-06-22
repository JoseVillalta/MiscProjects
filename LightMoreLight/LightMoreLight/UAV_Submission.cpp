// LightMoreLight.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

bool CalcOnOrOff(int n)
{
    bool isOn = false;
    int nFactors = 0;

    for (int i = 1; i <= n; i++)
    {
        auto r = n % i;
        if (r == 0)
        {
            nFactors++;
        }
    }

    if ((nFactors % 2) == 0)
    {
        isOn = false;
    }
    else
    {
        isOn = true;
    }
    return isOn;
}
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

