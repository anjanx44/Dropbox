/*
Shiakh Shiam Rahman 
UVa : 10922 - 2 the 9's
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
	char ch[1200];
	//int a[]={0,10,100,1000,10000};
	int sum,i,love=0,ans,temp,t;
	//freopen("Input.txt","r",stdin);
	while(cin>>ch)
	{
	    if(ch[0]=='0' && ch[1]=='\0')break;
	    for(i=0,sum=0;ch[i];i++)
            sum+=ch[i]-48;
        if((sum%9)==0)
        {
            cout<<ch<<" is a multiple of 9 and has 9-degree ";
            /*for(i=1;i<=4;i++)
                if((sum/a[i])==0)
                {
                    cout<<i<<"."<<endl;
                    break;
                }*/

            /*while(sum>0)
			{
				love+=(sum%10);
				sum=sum/10;
				if(love>=10)
				{
					sum=love;
					love=0;

				}

			}*/
			i=0;
			ans=sum;
			 while(ans>9)
            {

                temp=ans;
                ans=0;

                while(temp>0)
                {
                    t=temp%10;
                    ans=ans+t;
                    temp=temp/10;

                }
                i++;

            }

            if(!strcmp(ch,"9"))i=0;
            cout<<++i<<"."<<endl;
            love=0;

        }
        else
                cout<<ch<<" is not a multiple of 9."<<endl;
	}
	return 0;
}
