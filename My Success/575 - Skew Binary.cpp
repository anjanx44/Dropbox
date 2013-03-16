/*
Shiakh Shiam Rahman 
UVa : 575 - Skew Binary
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    char a[1000];
    double sum,m,n,o;
    int i;
    freopen("Input.txt","r",stdin);
    while(1)
    {
        gets(a);
        if(a[0]=='0' && a[1]=='\0')break;
        m=(double)strlen(a);
        for(i=0,sum=0;a[i]!='\0';i++,m--)
        {
            n=pow(2,m);
            if(a[i]=='1')
                o=1;
            else if(a[i]=='2')
                o=2;
            else
                o=0;
            sum+=o*(n-1);
        }
        printf("%.lf\n",sum);

    }

    return 0;
}
