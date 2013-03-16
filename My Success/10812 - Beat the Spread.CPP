#include<stdio.h>
#include<string.h>
/*
Shiakh Shiam Rahman 
UVa : 10812 - Beat the Spread
*/
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	unsigned a,b;
	int c,d=1;
	scanf("%d",&c);
	while(d<=c)
	{
		cin>>a>>b;
		if(b>a)
			cout<<"impossible"<<endl;
		else
			cout<<(a+b)/2<<" "<<(a-b)/2<<endl;
		d++;
	}
	cout<<"shiam"<<endl;
	return 0;
}
