/*
Shiakh Shiam Rahman 
UVa : 299 - Train Swap
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,u[60],d,i,j,count,temp;
    freopen("Input.txt","r",stdin);
    scanf("%d",&a);
    for(d=0;d<a;d++)
    {
        scanf("%d",&b);
        for(i=0,count=0;i<b;i++)
            scanf("%d",&u[i]);

     for(i = 1; i < b;i++)
     {
        for(j = 0; j < b-i;j++)
        {
                if(u[j] > u[j + 1])
                {
                    temp = u[j];
                    u[j] = u[j + 1];
                    u[j + 1] = temp;
                    count++;

                }

        }
    }
    printf("Optimal train swapping takes %d swaps.\n",count);
    }

    return 0;
}
