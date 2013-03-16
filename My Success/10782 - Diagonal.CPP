/*
Shiakh Shiam Rahman 
UVa : 10782 - Diagonal
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
using namespace std;
int main()
{
	double N,res;
	int ca=1;
	while(cin>>N && N>0)
	{
		res=ceil((3+sqrt(9+8*N))/2);
		cout<<"Case "<<ca<<": ";
		printf("%.lf\n",res);
		ca++;
	}
	return 0;
}