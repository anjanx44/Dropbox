/*
Shiakh Shiam Rahman 
UVa : 10370 - Above average
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    int a,b,c=1,arr[1100],i,count;
    double ans,sum,avg;
    freopen("Input.txt","r",stdin);
    cin>>a;
    while(c<=a)
    {
        cin>>b;
        for(i=0;i<b;i++)
            cin>>arr[i];
        for(sum=0,i=0;i<b;i++)
            sum+=arr[i];
        avg=sum/b;
        for(i=0,count=0;i<b;i++)
            if(avg<arr[i])
                count++;
        ans=(double)count/b*100.00;
        if(count==b)ans=0.0;
        printf("%.3lf",ans);
        putchar('%');
        cout<<endl;
        c++;
    }
    return 0;
}
