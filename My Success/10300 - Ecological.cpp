/*
Shiakh Shiam Rahman 
UVa : 10300 - Ecological
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    int a,b,c;
    int i,j,m,n,sum;
    freopen("Input.txt","r",stdin);
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>n;
        for(j=0,sum=0;j<n;j++)
        {
            cin>>a>>b>>c;
            sum+=a*c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
