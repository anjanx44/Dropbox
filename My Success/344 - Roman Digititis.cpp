#include<stdio.h>
int main()
{
	int a,m=0,n=0,o=0,p=0,q=0,b,c=1;
	while(scanf("%d",&a))
	{
		if(a==0)
		break;
		b=a;
		while(c<=b)
		{
			a=c;
			A:
			if(a>=1&&a<=10)
			{
				if(a==1)
				m++;
				if(a==2)
				m+=2;
				if(a==3)
				m+=3;
				if(a==4)
				{
					m++;
					n++;
				}
				if(a==5)
					n++;
				if(a==6)
				{
					m++;
					n++;
				}
				if(a==7)
				{
					m+=2;
					n++;
				}
				if(a==8)
				{
					m+=3;
					n++;
				}
				if(a==9)
				{
					m++;
					o++;
				}
				if(a==10)
				o++;
				goto B;
			}
			if(a>=11&&a<40)
			{
				if(a/10==3)
				{
					o+=3;
					a=a%10;
					goto A;
				}
				if(a/10==2)
				{
					o+=2;
					a=a%10;
					goto A;
				}
				if(a/10==1)
				{
					o++;
					a=a%10;
					goto A;
				}
			}
			if(a>=40&&a<50)
			{
				o++;
				p++;
				a=a%10;
				goto A;
			}
			if(a>=50&&a<90)
			{
				p++;
				a=a%50;
				if(a/10==3)
				{
					o+=3;
					a=a%10;
					goto A;
				}
				if(a/10==2)
				{
					o+=2;
					a=a%10;
					goto A;
				}
				if(a/10==1)
				{
					o++;
					a=a%10;
					goto A;
				}
				if(a>=1&&a<=10)
				goto A;
			}
			if(a>=90&&a<100)
			{
				o++;
				q++;
				a=a%90;
				goto A;
			}
			if(a==100)
			q++;
			B:
			c++;
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",b,m,n,o,p,q);
		m=n=o=p=q=0;
		c=1;
	}
	return 0;
}
