/*
Shiakh Shiam Rahman 
UVa : 10347 - Medians
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	double m1,m2,m3,a,b,c;
	double s,area,T;
	freopen("input.txt","r",stdin);
	while(cin>>m1>>m2>>m3)
	{
		T=(4.0*(m1*m1+m2*m2+m3*m3))/3.0;
		a=sqrt((2.0*(T-2.0*m1*m1))/3.0);
		b=sqrt((2.0*(T-2.0*m2*m2))/3.0);
		c=sqrt((2.0*(T-2.0*m3*m3))/3.0);
		s=0.5*(a+b+c);
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		if(m1<0.0 || m2<0.0 || m3<0.0 || area<=0.0)	area=-1.0;	
			printf("%.3lf\n",area+1e-7);
			
	}
	return 0;
}
