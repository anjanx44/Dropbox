#include<stdio.h>
#include<string.h>
struct name{
	char name[13];
	int moeny;
		};
int main()
{
int a,x,y,z,h,g,b,j=0;
name c[10],e[10];
char d[13];
while(scanf("%d",&a)==1)
{
	if(j==1)
		printf("\n");
	j=1;
	for(b=0;b<a;b++)
		{
			scanf("%s",c[b].name);
			c[b].moeny=0;
		}
	for(b=0;b<a;b++)
		{
			scanf("%s%d%d",d,&x,&y);
			for(z=0;z<y;z++)
				{
					scanf("%s",e[z].name);
				}
			for(z=0;z<a;z++)
				{
					h=strcmp(d,c[z].name);
					if(y!=0)
						{
							if(h==0)
							c[z].moeny-=(x-x%y);
						}
				}
			for(g=0;g<y;g++)
				{
					for(z=0;z<a;z++)
						{
							h=strcmp(e[g].name,c[z].name);
							if(y!=0)
								{
									if(h==0)
										c[z].moeny+=(int)(x/y);
								}
						}
				}

		}
for(b=0;b<a;b++)
	{
		printf("%s %d\n",c[b].name,c[b].moeny);
	}
}
return 0;
}