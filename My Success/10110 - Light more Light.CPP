/*
Shiakh Shiam Rahman 
UVa : 10110 - Light more Light
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	long long a,b;
	double root;
	while(cin>>a && a)
	{
		root=sqrt(a);
		b=(long)root;
		if(b*b==a)
			printf("yes\n");
		else
			printf("no\n");
	}


	return 0;
}
