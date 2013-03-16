/*
Shiakh Shiam Rahman 
UVa : 10221 - Sattalite
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.14159265358979323846
int main(void)
{
double a,s;
char data[4];
while(scanf("%lf %lf %s",&s,&a,data)!=EOF)
{
if(a>180)
a=360.00-a;
if(strcmp(data,"deg")==0)
printf("%.6lf ",(6440+s)*(a*PI/180));
else
printf("%.6lf ",(6440+s)*(a/60*PI/180));
if(strcmp(data,"min")==0)
a/=60;
printf("%.6lf\n",sqrt(2*(6440+s)*(6440+s)*(1-cos(a*PI/180))));
}
return 0;
}
