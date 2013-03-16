/*
Shiakh Shiam Rahman 
UVa : 483 - Word Scarmble
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
    char b[100];
    int i,j;
    //freopen("Input.txt","r",stdin);
    for(i=0;(a=getchar())!=EOF;i++)
    {
        b[i]=a;

        if(a==32 || a=='\n')
        {
            b[i]='\0';
            j=strlen(b);
            for(i=j-1;i>=0;i--)
                putchar(b[i]);
            printf(" ");
            i=-1;
        }
        if(a=='\n')
        {
            cout<<endl;
        }

    }
    return 0;
}
