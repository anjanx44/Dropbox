/*
Shiakh Shiam Rahman 
UVa : 10302 - Polnomials
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    long long sum;
    unsigned int n;
    //freopen("input.txt","r",stdin);
    while(cin>>n)
    {
        sum=n*n*(n+1)*(n+1)/4;
        printf("%lld\n",sum);

    }
	return 0;
}
