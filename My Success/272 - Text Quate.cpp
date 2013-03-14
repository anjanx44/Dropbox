/*
Shiakh Shiam Rahman 
UVa : 272 - Text Quate
*/
#include <iostream>
#include<stdio.h>
//#include<iostream.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    char a;
    int flag=0;
    freopen("Input.txt","r",stdin);
    while((a=getchar())!=EOF)
    {
        if(a==34 && flag==0)
        {
            putchar(96);
            putchar(96);
            flag=1;
        }
        else if(a==34 && flag==1)
        {
            putchar(39);
            putchar(39);
            flag=0;
        }
        else
        putchar(a);
    }
    return 0;
}
