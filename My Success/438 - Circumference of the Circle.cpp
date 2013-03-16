/*
Shiakh Shiam Rahman 
UVa : 438 - Circumference of the Circle
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
   double x1,x2,x3,y1,y2,y3;
   double a,b,c,s,area,R,cir;
   freopen("Input.txt","r",stdin);
   while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
   {
       a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
       b=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
       c=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
       s=(a+b+c)/2;
       area=sqrt(s*(s-a)*(s-b)*(s-c));
       R=(a*b*c)/(4*area);
       cir=2*4*atan(1)*R;
       printf("%.2lf\n",cir);
   }

   return 0;
}
