/*
Shiakh Shiam Rahman 
UVa : 10327 - Flip Sort
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,u[1010],d,i,j,count,temp;

    freopen("Input.txt","r",stdin);

    while(cin>>b)
    {
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
    printf("Minimum exchange operations : %d\n",count);
    }

    return 0;
}
