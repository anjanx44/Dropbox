#include <stdio.h>

int main()
{
	 long int a[1000],i,b=0,j,k;
	 for(i=0;;i++)
	 {
		  scanf("%ld",&a[i]);
		  if(a[i]==0)
		  break;
	 }
	 printf("PERFECTION OUTPUT\n");
	 for(k=0;a[k]!=0;k++)
	 {
	     b=0;
		for(i=1;i<a[k];i++)
		{
			j=0;
			if(a[k]%i==0)
			b=b+i;
		}
		if(b==a[k])
		printf("%5ld  PERFECT\n",a[k]);
		if(b<a[k])
		printf("%5ld  DEFICIENT\n",a[k]);
		if(b>a[k])
		printf("%5ld  ABUNDANT\n",a[k]);
	 }
	 printf("END OF OUTPUT\n");
	 return 0;
}
