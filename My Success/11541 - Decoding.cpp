/*
Shiakh Shiam Rahman 
UVa : 11541 - Decoding
*/
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    string str;
    char arr[100];
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
    getline(cin,str);

    k=0;                 //arr-er element no 0;

    for(i=0;str[i];i++)
    {
        if(isdigit(str[i]))
        {
            j=(int)(str[i]-48);      //j-er intger value from charecter;

          while(j--)
            {
                arr[k]=str[i-1];
                k++;

            }
        }
    }
    arr[k]='\0';
    //cout<<arr<<endl;
    printf("%s\n",arr);
}
return 0;
}
