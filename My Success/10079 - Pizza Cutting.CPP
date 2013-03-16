/*
Shiakh Shiam Rahman 
UVa : 10079 - Pizza Cutting
*/
#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

//using namespace std;

int main()
{
    long double n;
    while(1)
    {
	cin>>n;
	if(n<0)break;
	printf("%.Lf\n",1+(n*(n+1))/2);
    }
    return 0;
}
//Run with TC
