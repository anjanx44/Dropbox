/*
Shiakh Shiam Rahman 
UVa : 10127 - ones
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
   int a,b,c,count;
   freopen("Input.txt","r",stdin);
   while(cin>>a)
   {
       b=1;
       count=1;
       while(a>b)
       {
           b=b*10+1;
           count++;
       }
       while(1)
       {
           c=b%a;
           if(c==0)
           {
               cout<<count<<endl;
               break;
           }
           else
           {
               b=c*10+1;
               count++;
           }
       }


   }
   return 0;
}
