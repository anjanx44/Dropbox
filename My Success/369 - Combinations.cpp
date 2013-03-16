/*
Shiakh Shiam Rahman 
UVa : 369 - Combinations
*/


#include<stdio.h>
double factorial_down(double f)
{
	double m=1,n=1;
	while(n<=f)
		{
			m=m*n;
			n++;
		}
	return m;
}
double factorial_up(double n,double m)
{
	double q;
	q=n;
	while(n>m+1)
		{
			n--;
			q=n*q;
		}
	return q;
}
int main()
{
	int a,b;
	double i,j,k;
	//freopen("D:\\Input\\Input_369.txt","r",stdin);
	//freopen("D:\\Output\\output_369.txt","w",stdout);

	while(scanf("%d %d",&a,&b))
	{
		if(a==0 && b==0)
		break;
		i=factorial_down(b);
		j=factorial_up(a,a-b);
		k=j/i;
		printf("%d things taken %d at a time is %.0lf exactly.\n",a,b,k);

	}
	return 0;
}

