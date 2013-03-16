/*
Shiakh Shiam Rahman 
UVa : 10783 - Odd Sum
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    int a,b,c,n,temp,sum=0,i;
    //freopen("Input.txt","r",stdin);
    cin>>n;
    for(c=1;c<=n;c++)
    {
        cin>>a>>b;
        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        for(i=a;i<=b;i++)
        {
            if((i%2)==0)
                continue;
            else
               sum+=i;
        }
        printf("Case %d: %d\n",c,sum);
        sum=0;
    }
    return 0;
}
