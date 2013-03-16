/*
Shiakh Shiam Rahman 
UVa : 10451 - Ancient Village
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
   double A;
   int cas=0;
   while(cin>>n>>A)
   {
       if(n<3)break;
       printf("Case %d: %.5lf %.5lf\n",++cas,pi*((2.0*A)/(n*sin(pi2/n)))-A,A-pi*(A/(n*tan(pi/n))));
   }
    return 0;
}
