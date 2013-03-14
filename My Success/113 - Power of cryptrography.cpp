/*
Shiakh Shiam Rahman 
UVa : 113 - Power of Cryptrography
*/
#include <cstdio>
#include <cmath>

int main()
{
    //freopen("Input.txt","r",stdin);
    double x;
    int y;
    while(scanf("%d %lf",&y,&x)==2)
        printf("%.lf\n",pow(x,1/(double)y));
    return 0;
}
