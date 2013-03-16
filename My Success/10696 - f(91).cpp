/*
Shiakh Shiam Rahman 
UVa : 10696 - f(91)
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    int a;
    while(cin>>a && a!=0)
    {
        if(a<=100)
           printf("f91(%d) = 91\n",a);
        else
            printf("f91(%d) = %d\n",a,a-10);
    }
    return 0;
}
