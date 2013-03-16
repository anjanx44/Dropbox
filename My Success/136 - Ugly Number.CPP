/*
Shiakh Shiam Rahman 
UVa : 136 - Ugly Number
*/

#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
using namespace std;

int main()
{
    double u[1800],g,temp;
    double m,n,o;
    int count=0,i,j,a;
    for(m=0;m<31;m++)
        for(n=0;n<31;n++)
            for(o=0;o<31;o++)
            {
                g=pow(2,o)*pow(3,n)*pow(5,m);
                if(g>1000000000)
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
     sort(u,u+count);
     /*for(i = 1; i < count;i++)
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
     }*/
    printf("The 1500'th ugly number is %.lf.\n",u[1499]);

    return 0;
}
