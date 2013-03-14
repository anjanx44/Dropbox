//shaikh shiam rahman
//Pwer of cryptography
#include<stdio.h>
int main()
{
	int a,c=0;
	double b,d;
	while(1)
		{
			scanf("%d %lf",&a,&b);
			if(a==0 && b==0)
			break;
			d=a;
			c=1;
			while(d<=b)
				{
					d=d*a;
					c++;
					if(d==b)
						printf("%d\n",c);
					else
						continue;
				}
		}
	return 0;
}