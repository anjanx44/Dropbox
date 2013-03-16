/*
Shiakh Shiam Rahman 
UVa : 10931 - Parity
*/
#include<stdio.h>
int main()
{
    long int num;
    int a[5000],i,j,k,x;
    //freopen("D:\\Input\\Input_10931.txt","r",stdin);
    while(1)
    {
	scanf("%ld",&num);
	if(num==0)break;
	for(i=0,k=0,x=0;num>0;i++,k++)
	{
	    j=num%2;
	    a[i]=j;
	    num=num/2;
	}
	printf("The parity of ");
	for(i=k-1;i>=0;i--)
	{
	    printf("%d",a[i]);
	    if(a[i]==1)
	    x++;
	}
	printf(" is %d (mod 2).\n",x);
    }
    return 0;
}
