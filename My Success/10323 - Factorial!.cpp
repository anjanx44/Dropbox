/*
Shiakh Shiam Rahman 
UVa : 10323 - Factorial!
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    double b,c;
    int a;
    //freopen("Input.txt","r",stdin);
    while(cin>>a)
    {
        b=1;c=1;
        while(c<=a && (a>=8 && a<=13))
        {
            b=b*c;
            c++;
        }

        if(a<0)
        {
            if(!(a%2)==0)
                cout<<"Overflow!";
            else
               cout<<"Underflow!";
            goto A;
        }

        if(a>=14)
            cout<<"Overflow!";
        else if(a<=7)
            cout<<"Underflow!";
        else
            printf("%.lf",b);
        A:
        cout<<endl;

    }
    return 0;
}
