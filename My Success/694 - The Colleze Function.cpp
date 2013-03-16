/*
Shiakh Shiam Rahman 
UVa : 694 - The Colleze Function
*/
#include<stdio.h>
int main()
{
 long long i,j;
int clen,setnum=1;

while(1)
{
scanf("%lld %lld",&i,&j);
if (i<0 && j<0) break;

printf("Case %d: A = %lld, limit = %lld, number of terms = ",setnum,i,j);

for (clen=1;i!=1;clen++)
{
if (i%2!=0) { i=3*i+1; }
else { i=i/2; }
if (i>j) break;
}

printf("%d\n",clen);
setnum++;
}
return 0;
}
