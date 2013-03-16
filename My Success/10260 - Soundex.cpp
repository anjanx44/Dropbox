/*
Shiakh Shiam Rahman 
UVa : 10260 - Soundex
*/
#include <iostream>
#include "cstdio"
#include "cstring"
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int a[100];
    a[(int)'B'] = a[(int)'F'] = a[(int)'P'] = a[(int)'V'] = 1;
    a[(int)'C'] = a[(int)'G'] = a[(int)'J'] = a[(int)'K'] = 2;
    a[(int)'Q'] = a[(int)'S'] = a[(int)'X'] = a[(int)'Z'] = 2;
    a[(int)'D'] = a[(int)'T'] = 3;
    a[(int)'L'] = 4;
    a[(int)'M'] = a[(int)'N'] = 5;
    a[(int)'R'] = 6;
    a[(int)'A'] = a[(int)'E'] = a[(int)'I'] = a[(int)'O'] = 0;
    a[(int)'U'] = a[(int)'H'] = a[(int)'W'] = a[(int)'Y'] = 0;

    int res[25];
    char ch[25];
    int n = 0,j;
    while(cin>>ch)
    {
        j = 0;
        int len = strlen(ch);
        for(int i=0 ;i<len;i++)
        {
            if(isalpha(ch[i]))
            {
                int b = (int)ch[i];
                int c = (int)ch[i+1];
                if(a[b]!=0)
                {
                    if(a[b]==a[c])
                    {
                        res[j]=a[b];
                        n = 1;
                    }
                    else
                    {
                        res[j++]=a[b];
                        n = 0 ;
                    }
                }

            }
        }
        if(n)j++;
        for(int k=0;k<j;k++)
            printf("%d",res[k]);
        puts("");
    }
    return 0;
}
