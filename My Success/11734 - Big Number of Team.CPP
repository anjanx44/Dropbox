/*
Shiakh Shiam Rahman 
UVa : 11734 - Big Number of Team
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int c;
	int i,j,k=1;
	char ch[30],ca[30],cp[30],aa;
	
	cin>>c;
	aa=getchar();
	while(c-- && gets(ch) && gets(ca))
	{
		cout<<"Case "<<k<<": ";
		if(!(strcmp(ch,ca)))
			cout<<"Yes"<<endl;
		else
		{
			for(i=0,j=0;ch[i];i++)
			{
				if(ch[i]==32)
					continue;
				else
				{
					cp[j]=ch[i];
					j++;
				}
			}
			cp[j]='\0';
			if(!(strcmp(cp,ca)))
				cout<<"Output Format Error"<<endl;
			else 
				cout<<"Wrong Answer"<<endl;
			}
		
		k++;
	}

	return 0;
}
