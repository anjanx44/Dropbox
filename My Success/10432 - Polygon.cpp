/*
Shiakh Shiam Rahman 
UVa : 10432 - Polygon
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#define pi2 4.0*acos(0.0)
#define pi 2.0*acos(0.0)

using namespace std;

int main()
{
    double n;
    double r;
    while(cin>>r>>n)
    {
        // cout<< pi*r*r<<endl;
        //cout <<(2000*(r*r*sin(pi2/n))*0.5) << endl;
        printf("%0.3lf\n",n*(r*r*sin(pi2/n))*0.5);
    }
    return 0;

}
