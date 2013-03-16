/*
Shiakh Shiam Rahman 
UVa : 10018 - Reverse and Add
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int powr(unsigned x,int y)
{
	while(y--)
	{
		x*=10;
	}
	return x;
}
int main()
{
	freopen("Input.txt","r",stdin);
	unsigned a,c,res;
	int i,j,count,x,arr[100];
	scanf("%d",&i);
	while(i--)
	{
		scanf("%lu",&a);
		x=0;
		c=a;
		res=0;
		count=0;
		while(1)
		{
			for(j=0;c>0;j++)
			{
				arr[j]=c%10;
				c=c/10;
				count++;
			}
			for(j=0;count--;j++)
				res+=powr(arr[j],count);
			if(res==a)
			{
				printf("%d %lu\n",x,res);
				break;
			}
			a=res+a;
			c=a;
			count=0;
			res=0;
			x++;
		}
	}
		

	return 0;
}
