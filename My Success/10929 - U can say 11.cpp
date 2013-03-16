/*
Shiakh Shiam Rahman 
UVa : 10929 - U can say 11
*/

#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    char a[1100];
    int i,len;
    long sum2,sum1,res;
    freopen("Input.txt","r",stdin);
    while(1)
    {
        gets(a);
        if(a[0]=='0' && a[1]=='\0')break;
        len=strlen(a);
        for(i=0,sum1=0,sum2=0;i<len;i++)
        {
            if(((i+1)%2)==0)
            sum1+=(a[i]-48);
            else
            sum2+=(a[i]-48);
        }
        //puts(a);
        if(sum1>=sum2)
        res=sum2-sum1;
        else
        res=sum1-sum2;
        if(res==0 || (res%11)==0)
        printf("%s is a multiple of 11.\n",a);
        else
        printf("%s is not a multiple of 11.\n",a);

    }
    return 0;
}
