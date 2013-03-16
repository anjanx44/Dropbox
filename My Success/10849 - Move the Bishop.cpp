/*
Shiakh Shiam Rahman 
UVa : 10849 - Move the Bishop
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int CAS;
    scanf("%d",&CAS);
    while(CAS--)
    {
        int cas,N,count;
        scanf("%d",&cas);
        scanf("%d",&N);
        while(cas--)
        {
            count=0;
            int X,Y,x,y;
            scanf("%d %d %d %d",&X,&Y,&x,&y);
            int bis,move;
            bis=X+Y;
            move=x+y;
            if((bis%2)!=(move%2))
            {
                printf("no move\n");
                continue;
            }
            else if(x==X && y==Y)
            {
                printf("0\n");
            }
            else if(x>N || y>N || X>N || Y>N)
                printf("no move\n");
            else
            {
                if(abs(X-x)==abs(Y-y))
                    printf("1\n");
                else printf("2\n");

            }
        }
    }
    return 0;
}
