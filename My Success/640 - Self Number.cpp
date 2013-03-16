/*
Shiakh Shiam Rahman 
UVa : 640 - Self Number
*/
#include <iostream>
#include <cstdio>
using namespace std;
#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
# define long long ll
# define unsigned u

int arr[1000010][2];

int main()
{   /*
    READ("in.txt");*/
    //WRITE("out.txt");
    for(int i=0;i<=1000000;i++)
        arr[i][0]=i;
    char ch[12];
    int i,num,j,n;
    for(i=0;i<=1000000;i++)
    {
        n=i;
        sprintf(ch,"%d",n);
        num=i;
        j=0;
        while(ch[j])
        {
            num+=ch[j]-48;
            j++;
        }
        if(num<1000008)
            arr[num][1]=1;
    }
    for(i=0;i<=1000000;i++)
    {
        if(arr[i][1]==0)
            printf("%d\n",arr[i][0]);
    }

    return 0;
}
