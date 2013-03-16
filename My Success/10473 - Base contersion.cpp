/*
Shiakh Shiam Rahman 
UVa : 10473 - Base contersion
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
#define MAXN 1000000

int main()
{
    READ("in.txt");

    unsigned a;
    int i,j;
    char ch[20],c[20];
    while(cin>>ch)
    {
        if(ch[0]=='-')
            break;
        if(ch[1]=='x')
        {
            i=2;j=0;
            while(ch[i]!=NULL)
            {
                c[j++]=ch[i++];
            }
            c[j]=NULL;
            sscanf(c,"%X",&a);
            printf("%u\n",a);
        }
        else
        {
            sscanf(ch,"%u",&a);
            printf("0x%X\n",a);
        }
    }
    return 0;
}
