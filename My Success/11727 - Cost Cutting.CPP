/*
Shiakh Shiam Rahman 
UVa : 11727 - Cost Cutting
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int a[3],n,i=1;

	freopen("input.txt","r",stdin);
		
	cin>>n;
	while(n--)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<"Case "<<i<<": "<<a[1]<<endl;
		i++;
	}

	return 0;
}
