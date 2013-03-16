/*
Shiakh Shiam Rahman 
UVa : 10945 - MotherBear
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    char a[1000],b[1000],c[1000],d[1000];
    int i,j,len;
    freopen("Input.txt","r",stdin);
    while(1)
    {
	gets(a);
	if(!(strcmp(a,"DONE")))break;
	for(i=0;a[i]!='\0';i++)
	{
	    b[i]=toupper(a[i]);
	}
	b[i]='\0';
	for(i=0,j=0;b[i]!='\0';i++)
	{
	    if(b[i]>=65 && b[i]<=90)
	    {
		c[j]=b[i];
		j++;
	    }
	}
	c[j]='\0';
	len=strlen(c);
	for(i=len-1,j=0;i>=0 && a[j]!='\0';i--,j++)
	{
	    d[i]=c[j];
	}
	d[strlen(c)]='\0';
	if(strcmp(c,d))
	printf("Uh oh..");
        else
	printf("You won't be eaten!");
	printf("\n");
    }
    return 0;
}
