#include<stdio.h>
#include<string.h>
//char a[100000],b[100000],c[100000];
int main()
{
	char a[100000],b[100000],c[100000];
	//char a[],*b,*c;
	unsigned long int i,j,k,n;
	//freopen("Input.txt","r",stdin);
	while(gets(a))
	{
		for(i=0;a[i]!=' ';i++);
		for(k=i+1,j=0;a[k]!='\0';k++,j++)
		b[j]=a[k];
		b[j]='\0';
		a[i]='\0';
		/*l=strlen(a);
		m=strlen(b);
		if(l>=m)
		{
			strcpy(c,b);
			strcpy(b,a);
			strcpy(a,c);
		}*/
		k=0;
		for(i=0,n=0;b[i]!='\0';i++)
		{
			if(b[i]==a[n])
			{
				n++;
				for(j=0;a[j]!='\0';j++)
				{
					if(a[j]==b[i])
					{
						c[k]=a[j];
						k++;
						break;
					}
				}
			}
		}
		c[k]='\0';
		if(strcmp(a,c)==0)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}