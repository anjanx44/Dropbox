/*
Shiakh Shiam Rahman 
UVa : 11574 - Automatic Ans
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	int c,n,ans;
	//freopen("Input.txt","r",stdin);
	cin>>c;
	while(c--)
	{
		cin>>n;
		ans=n*567;
		ans/=9;
		ans+=7492;
		ans*=235;
		ans/=47;
		ans-=498;
		ans/=10;
		n=ans%10;
		if(n<0)n*=-1;
		cout<<n<<endl;
	}
	return 0;
}
