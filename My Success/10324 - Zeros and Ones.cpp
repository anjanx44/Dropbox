/*
Shiakh Shiam Rahman 
UVa : 10324 - Zeros and Ones
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);

char ch[1000001];
int counter[1000001];

int main()
{
    READ("in.txt");

    int cas,max,min;
    int i,k,j,len,Case=1;
    while(cin>>ch)
    {
        j=0;k=0;
        len=strlen(ch);
        for(i=0;i<len;)
        {
            while(ch[i]=='1' && ch[i])
            {
                counter[i]=k;
                i++;
            }
            k++;
            while(ch[i]=='0' && ch[i])
            {
                counter[i]=k;
                i++;
            }
            k++;
        }
        cin>>cas;
        cout<<"Case "<<Case++<<":\n";
        for(i=0;i<cas;i++)
        {
            cin>>min>>max;
            if(counter[min]==counter[max])
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }

    }
    return 0;
}
