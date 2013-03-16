/*
Shiakh Shiam Rahman 
UVa : 11332 - Summing Digit
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	unsigned num,sum;
	while(cin>>num && num)
	{
		/*sum=0;
		while(num>0)
		{
			sum+=(num%10);
			num/=10;
			if(sum>10)
			{
				num=sum;
				sum=0;
			}
		}*/
		sum=num%9;
		if(sum==0)sum=9;
		cout<<sum<<endl;
	}
	return 0;
}
