/*
Shiakh Shiam Rahman 
UVa : 11716 - Digital FortLess
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	int c;
	char ch[20000],ca[500][500],aa;
	int i,j,k,sq,len;
	freopen("Input.txt","r",stdin);	
	
	cin>>c;
	aa=getchar();
	while(c--)
	{
		gets(ch);
		len=strlen(ch);
		sq=(int)sqrt(len);
		if(sq*sq!=len)
		{
			cout<<"INVALID"<<endl;
			continue;
		}
		else 
		{
			for(i=0,j=0;j<sq;j++)
				for(k=0;k<sq;k++)
				{
					ca[j][k]=ch[i];
					i++;
				}
					
		}
		for(j=0;j<sq;j++)
			for(k=0;k<sq;k++)
				putchar(ca[k][j]);
		cout<<endl;
	}
	return 0;
}
