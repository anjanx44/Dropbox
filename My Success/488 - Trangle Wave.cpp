/*
Shiakh Shiam Rahman 
UVa : 488 - Trangle Wave
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    int a,b,m,i,j,x,y,z,flag=0,flag2=0;
    freopen("Input.txt","r",stdin);
    //freopen("Output.txt","w",stdout);
    cin>>m;
    for(i=0;i<m;i++)
    {
        if(flag==1)cout<<endl;
        cin>>a>>b;
        for(j=1;j<=b;j++)
        {
            if(flag2==1)cout<<endl;
            for(x=1;x<=a;x++)
            {
                for(y=1;y<=x;y++)
                {
                    cout<<x;
                }
                cout<<endl;
            }
            for(z=x-2;z>0;z--)
            {
                for(y=z;y>0;y--)
                {
                    cout<<z;
                }
                cout<<endl;
            }
            flag2=1;
        }
        flag=1;
        flag2=0;
    }
    //cout<<"finish";
    return 0;
}
