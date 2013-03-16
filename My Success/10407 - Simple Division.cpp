/*
Shiakh Shiam Rahman 
UVa : 10407 - Simple Division
*/
#include<iostream>
#include<cmath>
#include"cstdlib"
using namespace std;

int data[1000],sub[1000],n,a,b;

long gcd(long x,long y )
{
    if(y==0)
        return x;
    else
        return gcd(y,(x%y));
}


int main()
{
    while(1)
    {
    int i=0;
    int k=0;

    while(1)
    {
        cin>>n;
        if(n==0)
        break;
        data[i++]=n;
    }
    if(data[0]==0||i==1||i>1000)
    break;
    int j=0;
    for(j=0;j<i-1;j++)
        sub[j]=abs(data[j]-data[j+1]);

    a=sub[0];

    for(k=1;k<j;k++)
    {
        b=sub[k];
        a=gcd(a,b);
    }
    cout<<a<<endl;
    for(j=0;j<i;j++)
        data[j]=sub[j]=0;

    }
    return 0;
}
