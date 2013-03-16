/*
Shiakh Shiam Rahman 
UVa : 374  - Big Mod
*/


#include <iostream>
#include "cstdio"
using namespace std;

long bigmod(long b, long p, long m){
if(p==0)
return 1;
else if(p%2==0)
return ((bigmod(b, (p/2), m))*(bigmod(b, (p/2), m)))%m;
else return((b%m)*bigmod(b, p-1, m))%m;
}
int main()
{
    unsigned b,p,m;
    while(cin>>b>>p>>m)
        printf("%ld\n",bigmod(b,p,m));

}
