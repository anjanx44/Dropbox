/*
Shiakh Shiam Rahman 
UVa : 443 - Humble Number
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    double u[6000],g,temp;
    double m,n,o,p;
    int count=0,i,j,res=0;
    //freopen("Input.txt","r",stdin);
    for(p=0;p<31;p++)
        for(m=0;m<31;m++)
            for(n=0;n<31;n++)
                for(o=0;o<31;o++)
                {
                    g=pow(2,o)*pow(3,n)*pow(5,m)*pow(7,p);
                    if(g>=2000000001)
                    {
                        g=0;
                        break;
                    }
                    else
                    {
                        u[count]=g;
                        count++;
                    }
                }

     for(i = 1; i < count;i++)
     {
        for(j = 0; j < count-i;j++)
        {
                if(u[j] > u[j + 1])
                {
                    temp = u[j];
                    u[j] = u[j + 1];
                    u[j + 1] = temp;

                }

        }
    }
    while(1)
    {
        scanf("%d",&res);
        if(res==0)break;
        printf("The %d",res);
        if((res==11 || res%100==11) || (res==12 || res%100==12) || (res==13 || res%100==13))cout<<"th";
        else if(res==1 || (res%10)==1)cout<<"st";
        else if(res==2 || (res%10)==2)cout<<"nd";
        else if(res==3 || (res%10)==3)cout<<"rd";
        else cout<<"th";
        cout<<" humble number is ";
        printf("%.lf.\n",u[res-1]);

    }
    return 0;
}
