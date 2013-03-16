/*
Shiakh Shiam Rahman 
UVa : 11185 - Tirnary
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int value,a;
 int string[9000]={0};
 while(scanf("%d",&value) && value>=0)
 {
    int i=8999,flag=0;
    if(value==0)
    {
        printf("0\n");
        continue;
    }
    while(value>0)
    {
       a=value%3;
       value/=3;
       string[i]=a;
       i--;
    }
    for(int j=0;j<9000;j++)
    {
        if(string[j]==0 && flag==0)
            flag=0;
        else
        {
            printf("%d",string[j]);
            flag=1;
			string[j]=0;
        }


    }
    printf("\n");
}
 return 0;

}
