/*
Shiakh Shiam Rahman 
UVa : 10469 - To carry or not carry
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,c;
    while(cin>>a>>b)
    {
        c=a ^ b;
        cout<<c<<"\n";
    }
    return 0;
}
