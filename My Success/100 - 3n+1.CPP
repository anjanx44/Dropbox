/*
Shiakh Shiam Rahman 
UVa : 100 - 3n+1
*/

#include<stdio.h>
unsigned long int count(unsigned long int a)
 {
	long int j=1;
	while(a>1)
		{
			if(a%2==0)
				a=a/2;
			else
				a=3*a+1;
            j++;
		}

	 return j;
}
 int main()
	{
		long int i,j,k,max,iorg,jorg;
		//freopen("Input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		while(scanf("%lu %lu",&i,&j)!=EOF)
			{
				iorg=i;
				jorg=j;
				if(i>j)
				{
					i=i+j;
					j=i-j;
					i=i-j;
				}
				max=0;
				while(i<=j)
				 {
					k=count(i);
					if(max<k)
					max=k;
					i++;
				 }
			printf("%lu %lu %lu\n",iorg,jorg,max);

		  }
		 return 0;
	}
