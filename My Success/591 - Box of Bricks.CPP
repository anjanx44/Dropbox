
/*
Shiakh Shiam Rahman 
UVa : 591 - Box of Bricks
*/

#include<stdio.h>
int main()
	{
		int a[500],i,j,k,n,b,c,m=0;
		while(1)
			{
				scanf("%d",&n);
				j=0;
            	c=0;
				if(n==0)
				break;
				m++;
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
				}
				for(i=0;i<n;i++)
					j=j+a[i];
				k=j/n;
				for(i=0;i<n;i++)
					{
						if(a[i]>k)
							{
								b=a[i]-k;
								c=b+c;
							}
					}
				printf("Set #%d\n",m);
				printf("The minimum number of moves is %d.\n\n",c);
			}
			return 0;
	 }

