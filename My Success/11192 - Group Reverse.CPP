/*
Shiakh Shiam Rahman 
UVa : 11192 - Group Reverse
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

void rev(char r[200],int x)
{
	for(int m=x;m>=0;m--)
		putchar(r[m]);
}
int main()
{
	char ch[200],re[200],aa;
	int a,i,j,len;
	freopen("Input.txt","r",stdin);
	while(cin>>a && a)
	{
		aa=getchar();
		gets(ch);
		len=strlen(ch);
		a=len/a;
		for(i=0,j=0;ch[i];i++,j++)
		{
			re[j]=ch[i];
			if(!((i+1)%a))
			{
				j++;
				re[j]='\0';
				rev(re,a-1);
				j=-1;
			}
		}
		cout<<endl;
	}
return 0;
}
