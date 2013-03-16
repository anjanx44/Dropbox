/*
Shiakh Shiam Rahman 
UVa : 10035 - rimary Arithematic
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

using namespace std;

int main()
{
    unsigned long a,b;
    int i,j,count,carry;
    freopen("Input.txt","r",stdin);
    while(1)
    {
        scanf("%lu %lu",&a,&b);
        if(a==0 && b==0)break;
        for(count=0,carry=0;a>0 || b>0;)
        {
            i=a%10;a=a/10;
            j=b%10;b=b/10;
            if((i+j+carry)>9)
                count++;
            carry=(i+j+carry)/10;
        }
        if(count>1)
            printf("%d carry operations.\n",count);
        else if(count==1)
            printf("%d carry operation.\n",count);
        else
            printf("No carry operation.\n");
    }

    return 0;
}
