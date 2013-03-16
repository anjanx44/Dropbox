/*
Shiakh Shiam Rahman 
UVa : 10872 - Trangles
*/
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
typedef long long ll;
typedef unsigned u;


int main()
{
    READ("in.txt");

    ll n,ans;
    int count=0;
    char ch[200];
    while(scanf("%s",ch))
    {
        if(!strcmp(ch,"0"))
        break;
        sscanf(ch,"%lld",&n);
        //i=ch[0]-48;
        if(n==3 || n==6)
            ans=1;
        else if((n%2)==0)
            ans=(n*n)/48;
        else if((n%2)!=0)
            ans=((n+3)*(n+3))/48;
        printf("%lld ",n%48);
        printf("Case %d: %lld\n",++count,ans);
    }
    return 0;
}
