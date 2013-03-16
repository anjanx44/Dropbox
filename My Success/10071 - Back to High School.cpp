/*
Shiakh Shiam Rahman 
UVa : 10071 - Back to High School
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    int v,t;
    while(scanf("%d %d",&v,&t)==2)
    {
        if(v>=0)
            printf("%ld\n",(long)2*v*t);
        else
            printf("%ld\n",(long)-2*v*t);
    }
    return 0;
}
