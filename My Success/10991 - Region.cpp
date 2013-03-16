#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const double pi = acos(-1.0);
double area_triangle(double a,double b,double c)
{
	double p = (a+b+c)/2.0;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
double area_fan(double r,double a,double b,double c)
{
	double angle = acos((a*a + b*b - c*c)/(2*a*b));
	return r*r*angle/2;
}
int main()
{
	int ncases;
	double r1,r2,r3,a,b,c;
	scanf("%d",&ncases);

	while( ncases-- )
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		a = r1 + r2;
		b = r1 + r3;
		c = r2 + r3;
		double area = area_triangle(a,b,c);
		double fan = ( area_fan(r1,a,b,c) + area_fan(r2,a,c,b) + area_fan(r3,b,c,a) );
		printf("%.6lf/n",area - fan);
	}

return 0;
}
