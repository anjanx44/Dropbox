/*
Shiakh Shiam Rahman 
UVa : 10924 - Parity Word
*/
#include<stdio.h>
#include<math.h>
int main()
{
    char a[30];
    long sum,add,add_ori,condition;
    int i,k;
    freopen("D:\\Input\\Input_10924.txt","r",stdin);
    while(scanf("%s",a)!=EOF)
    {
        printf("%s\n",a);
        for(i=0,add=0,k=2;a[i]!='\0';i++)
        {
            if(a[i]>96 && a[i]<123)
                sum=a[i]-96;
            else
                sum=a[i]-38;
            add+=sum;
        }
        if(add==1 || add==2 || add==3)
            printf("It is a prime word.\n");
        add_ori=add;
        while(sqrt(add_ori)>=k)
        {
            if (add%k==0)
            {
                printf("It is not a prime word.\n");
                condition=1;
                break;
            }
            k++;
            condition=0;
        }
        if(condition==0 && add>4)
        {
            printf("It is a prime word.\n");
            condition=1;
        }
    }
    return 0;
}
