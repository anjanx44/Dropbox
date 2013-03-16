/*
Shiakh Shiam Rahman 
UVa : 11172 - Relational Operator
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	int a,b,n;
	scanf("%d",&n);
	
	while(n--)
	{
		cin>>a>>b;
		/*if(a<0)a=(-1)*a;
		if(b<0)b=(-1)*b;*/
		if(a>b)cout<<">"<<endl;
		else if(a<b)cout<<"<"<<endl;
		else cout<<"="<<endl; 
	}
	return 0;
}
