/*
Shiakh Shiam Rahman 
UVa : 10220 - I love Big Number
*/
#include <iostream>
#include "cstdio"
using namespace std;

int fac[1002][2600];

int sum[1002];

int main()
{
    fac[0][2599] = 1;
    sum[0] = 1;
    int carry = 0;
    for(int i=1;i<=1000;i++)
    {
        carry = 0 ;
        for(int j = 2599;j>=0;j--)
        {
            int m ;
            m = fac[i-1][j]*i;
            fac[i][j] = (carry + m)%10;
            carry = (carry+m)/10;
            sum[i]+=fac[i][j];
        }
    }
    int n;
    while(cin>>n)
        printf("%d\n",sum[n]);
    return 0;
}
