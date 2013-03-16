/*
Shiakh Shiam Rahman 
UVa : 10338 - mischevious
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

unsigned factorial(int a)
{
	unsigned b,c;
	b=c=1;
	while(c<=a)
	{
		b*=c;
		c++;
	}
	return b;
}

int main()
{
	int arr[26];
	char c;
	int Case,i,ch;
	unsigned fac,ans;
	
	cin>>Case;
	
	while(Case)
	{
		for(i=0;i<26;i++)
			arr[i]=0;
		while((c=getchar())!='\n')
		{
		
			c=toupper(c);
			ch=(int)c;
			arr[ch-65]++;
		}
		for(i=0;i<26;i++)
			if(arr[i]>0)
				fac++;
		ans=factorial(fac);
		for(i=0;i<26;i++)
			if(arr[i]>1)
				ans/=factorial(arr[i]);
		printf("Data set %d: ",Case);
			Case--;
		printf("%u\n",ans);
	}
	return 0;
}
