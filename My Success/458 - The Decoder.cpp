/*
Shiakh Shiam Rahman 
UVa : 458 - The Decoder
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
    freopen("input.txt","r",stdin);
    while((a=getchar())!=EOF)
    {
        if(a=='\n')
            printf("\n");
        else
            putchar(a-7);
    }
    return 0;
}
