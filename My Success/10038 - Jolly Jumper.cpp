/*
Shiakh Shiam Rahman 
UVa : 10038 - Jolly Jumper
*/
#include <iostream>
#include "cstdio"
#include "cstdlib"
#define M 3010

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int res[M];
    int n;
    bool flag;
    while(cin>>n)
    {
        flag = false;
        int dif[M] = {0};
        cin>>res[0];
        for(int i=1;i<n;i++)
        {
            scanf("%d",&res[i]);
            int num = abs(res[i]-res[i-1]);
            if(num>0&&num<n&&dif[num]==0)
                dif[num] = 1;
            else
                flag = true;
        }
        if(flag) puts("Not jolly");
        else puts("Jolly");
    }
    return 0;
}

/*
#include<stdio.h>
int main ()
{
    int num[3000], test,i,j,dif, dif1, dif2;
    while(scanf("%d", &test)!=EOF)
    {
        for(i=0;i<test; i++)
        scanf("%d", &num[i]);
        if (test==1)
        {
            printf("Jolly\n");
            continue;
        }
        if(num[1]>num[0])
        dif1=num[1]-num[0];
        else
        dif1=num[0]-num[1];
        if (dif1!=(test-1))
        {
            printf("Not jolly\n");
            continue;
        }
        for(i=2; i<test; i++)
        {
            if(num[i]>num[i-1])
            dif2=num[i]-num[i-1];
            else
            dif2=num[i-1]-num[i];
            if (dif1>dif2)
            dif=dif1-dif2;
            else
            dif=dif2-dif1;
            if(dif==1)
            {
                dif1=dif2;
                continue;
            }
            else
            {
                printf("Not jolly\n");
                break;
            }

        }
        if((dif==1) || (dif==-1))
        printf("Jolly\n");
    }
    return 0;
}
*/
