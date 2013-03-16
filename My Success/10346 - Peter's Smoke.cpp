/*
Shiakh Shiam Rahman 
UVa : 10346 - Peter's Smoke
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

long unsigned  a[5002][150];
int main()
{

	long i,j,num,res,k,flag=0,f=0;
	//freopen("FILE.txt","w",stdout);
	a[0][149]=1;
	a[1][149]=1;
	for(i=2;i<5000;i++)
	{
		for(j=149,res=0,f=0;j>=0;j--)
		{
			num=a[i-1][j]+a[i-2][j]+res;
			res=0;
			if(num>100000000)
			{
				res=num/100000000;
				num=num%100000000;
			}
			a[i][j]=num;
			if(a[i-1][j-1]==0 && a[i-2][j-1]==0)
				f++;
			if(f==3)
			    break;

		}
	   /* for(j=0;j<50;j++)
		{
			if(a[i][j]>0)
			    flag=1;
			if(flag==1)
			{
				if(a[i][j]/10==0 && a[i][j-1]!=0)
				     printf("0%lu",a[i][j]);
				else
				     printf("%lu",a[i][j]);
				flag=0;
			}
		}
		printf("\n");*/
	}


	while(scanf("%ld",&k)!=EOF)
	//for(k=-1;k<5000;k++)
	{
	    /*if(k==0)
		{
				printf("The Fibonacci number for 0 is 0\n");
				continue;
		}*/
		//printf("The Fibonacci number for %ld is ",k);
	    k++;
		for(j=0;j<150;j++)
		{
			if(a[k][j]>0)
			    flag=1;
			if(flag==1)
			{
				if(a[k][j]/1000==0 && a[k][j-1]!=0)
				     printf("00000%lu",a[k][j]);
				else if(a[k][j]/10000==0 && a[k][j-1]!=0)
				     printf("0000%lu",a[k][j]);
				else if(a[k][j]/100000==0 && a[k][j-1]!=0)
				     printf("000%lu",a[k][j]);
				else if(a[k][j]/1000000==0 && a[k][j-1]!=0)
				     printf("00%lu",a[k][j]);
				else if(a[k][j]/10000000==0 && a[k][j-1]!=0)
				     printf("0%lu",a[k][j]);
				else
				     printf("%lu",a[k][j]);
			}
		}
		printf("\n");
		flag=0;
	}

	return 0;
}
