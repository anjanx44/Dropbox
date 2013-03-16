/*
Shiakh Shiam Rahman 
UVa : 371 - Acerman Function
*/
#include<stdio.h>
#include<stdlib.h>
//using namespace std;

//typedef __int64 ll;

int main()
{
long long s,e,n,c,t,p,m,temp,i;
while(scanf("%lld %lld",&s,&e)==2)
{
if(s==0&&e==0)
break;
t=0;
if(s>e)
{
temp=s;
s=e;
e=temp;
}
p=0;

for(i=s;i<=e;i++)
{
n=i;
c=0;
m=i;
do
{
if(n%2==0)
n/=2;
else
n=n*3+1;
c++;
}while(n!=1);


if(c>t){
t=c;
p=m;
}
}
printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",s,e,p,t);

}
return 0;
}