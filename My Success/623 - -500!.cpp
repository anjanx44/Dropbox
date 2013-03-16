/*
Shiakh Shiam Rahman 
UVa : 623 - -500!
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

unsigned  a[1020][2000];
int main()
{

	int i,j,num,res,k,flag=0,f=0,flag1,c;
	//freopen("FILE.txt","w",stdout);

	//j=sizeof(i);
	a[0][1999]=1;
	a[1][1999]=1;
	for(i=2;i<1010;i++)
	{
		for(j=1999,res=0,f=0,flag1=0;j>=0;j--)
		{
			num=a[i-1][j]*i+res;
			res=0;
			if(a[i-1][j]>0)
                flag1=1;
			if(num>1000000)
			{
				res=num/1000000;
				num=num%1000000;
			}
			a[i][j]=num;
			if(a[i-1][j-1]==0 && flag1==1)
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


	while(scanf("%d",&k)!=EOF)
	//for(k=-1;k<5000;k++)
	{
	    /*if(k==0)
		{
				printf("The Fibonacci number for 0 is 0\n");
				continue;
		}*/
		//printf("The Fibonacci number for %ld is ",k);
	    //k++;
	    printf("%d!\n",k);
		for(j=0,c=0;j<2000;j++)
		{
			if(a[k][j]>0)
			    {
			        flag=1;
			        c++;
                }
			if(flag==1)
			{
			    if(c==1)
			    {
			        printf("%u",a[k][j]);
			    }
			    else
			    {
			     if(a[k][j]==0)
                    printf("000000");
				 else if(a[k][j]/10==0)
				     printf("00000%u",a[k][j]);
				 else if(a[k][j]/100==0  )
				     printf("0000%u",a[k][j]);
				 else if(a[k][j]/1000==0  )
				     printf("000%u",a[k][j]);
				 else if(a[k][j]/10000==0  )
				     printf("00%u",a[k][j]);
				 else if(a[k][j]/100000==0  )
				     printf("0%u",a[k][j]);
                 else
				     printf("%u",a[k][j]);
                }
			}
		}
		printf("\n");
		flag=0;
	}
    return 0;
}
