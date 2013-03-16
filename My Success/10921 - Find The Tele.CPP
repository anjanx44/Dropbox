/*
Shiakh Shiam Rahman 
UVa : 10921 - Find The Tele
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    char a[300];
    int i;
    freopen("Input.txt","r",stdin);
    while(scanf("%s",a)!=EOF)
    {
	for(i=0;a[i]!='\0';i++)
		{
			if(a[i]==65 || a[i]==66 || a[i]==67)
			printf("2");
			else if(a[i]==68 || a[i]==69 || a[i]==70)
			printf("3");
			else if(a[i]==71 || a[i]==72 || a[i]==73)
			printf("4");
			else if(a[i]==74 || a[i]==75 || a[i]==76)
			printf("5");
			else if(a[i]==77 || a[i]==78 || a[i]==79)
			printf("6");
			else if(a[i]==80 || a[i]==81 || a[i]==82 ||a[i]==83)
			printf("7");
			else if(a[i]==84 || a[i]==85 || a[i]==86)
			printf("8");
			else if(a[i]==87 || a[i]==88 || a[i]==89 || a[i]==90)
			printf("9");
			else if(a[i]=='-' || a[i]==48 || a[i]==49)
			putchar(a[i]);
			else;

		  }
		  printf("\n");
}

    return 0;
}
