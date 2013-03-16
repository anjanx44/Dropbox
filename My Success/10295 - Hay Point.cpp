/*
Shiakh Shiam Rahman 
UVa : 10295 - Hay Point
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);

int main()
{
    READ("in.txt");

    map<string,int> m;
    int a,wd,pass;
    string s;
    char ch[10000],c[200];
    long long counter;

    cin>>wd>>pass;
    getchar();
    while(wd--)
    {
        gets(ch);
        sscanf(ch,"%s %d",&c,&a);
        s=string(c);
        m[s]=a;
    }
    counter=0;
    while(pass--)
    {
        cin>>ch;
        s=string(ch);
        while(s!=".")
           {
               counter+=m[s];
               scanf("%s",ch);
               s=string(ch);
           }
        if(s==".")
        {
            cout<<counter<<"\n";
            counter=0;
            continue;
        }
    }
    return 0;
}
