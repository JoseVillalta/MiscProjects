// LightMoreLight.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>

using namespace std;

bool CalcOnOrOff(unsigned int n)
{
    unsigned int x = sqrt(n);

    if (n == x*x) return true;
    return false; 
  
}
int main()
{
    unsigned int n;
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

