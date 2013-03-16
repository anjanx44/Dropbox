/*
Shiakh Shiam Rahman 
UVa : 494 - Kinder Garden Counting 
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    char a;
    int i=1,count=0;
    freopen("Input.txt","r",stdin);
    while((a=getchar())!=EOF)
    {
        a=toupper(a);
        if(a>=65 && a<=90 && i==1)
        {
            count++;
            i=0;
        }
        if((a<65 || a>90) && i==0)
            i=1;
        if(a=='\n' || a=='\r')
        {
            cout<<count<<endl;
            count=0;
        }
    }


    return 0;
}
