#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000],c[1000],e[1000];
	int n=1,i,j,k,d,l;
	while(gets(a))
	{
		if(a[0]=='0')
		{
			 if(a[1]>='0'&&a[1]<='9');
			 else
				goto A;
		}
		if(n==1)
		{
			strcpy(b,a);
			strcpy(c,a);
		}
		if(n>=2)
		{
			i=strlen(b);
			k=strlen(a);
			if(i<k)
			{
				l=0;
				for(j=0;b[l]!='\0';j++)
				{
					if((j+1)>(k-i))
					{
						e[j]=b[l];
						l++;
					}
					else
					e[j]=48;
				}
				e[j]='\0';
				strcpy(b,e);
				i=strlen(b);
			}
			if(i>k)
			{
				l=0;
				for(j=0;a[l]!='\0';j++)
				{
					if((j+1)>(i-k))
					{
						e[j]=a[l];
						l++;
					}
					else
					e[j]=48;
				}
				e[j]='\0';
				strcpy(a,e);
            			k=strlen(a);
			}
			j=0;
			for(i--,k--;i>=0&&k>=0;i--,k--)
			{
				d=a[k]+b[i];
				if(d>=96&&d<=105)
				c[j]=d-48;
				if(d>105)
				{
					c[j]=d-58;
					b[i-1]=b[i-1]+1;
				}
				j++;
			}
			if(d>105)
			{
				c[j]=49;
				j++;
			}
			c[j]='\0';
		}
		i++;
		if(n>=2)
		{
			for(j--;j>=0;j--)
			{
				b[i]=c[j];
				i++;
			}
			b[i]='\0';
		}
		n++;
	}
	A :
	puts(b);
	return 0;
}
