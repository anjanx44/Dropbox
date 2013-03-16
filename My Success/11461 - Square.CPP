/*
Shiakh Shiam Rahman 
UVa : 11461 - Square
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	int a,b,c,i;
	while(cin>>a>>b && a && b)
	{
		c=a;
		for(c=a,i=0;c*c<=b;c++,i++){}
		cout<<i<<endl;
	}
	return 0;
}
