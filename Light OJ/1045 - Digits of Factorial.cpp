#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<deque>
#include<queue>
#include<string>
#include<map>
#include<sstream>
using namespace std;
#define SIZE_P 1000000
double arr[SIZE_P+5];
int main()
{
    int test_case;
    double fac_LOG=0;
    cin>>test_case;
    arr[0]=0;
    arr[1]=0;
    for(long long i=2;i<SIZE_P+1;i++)
    {
      fac_LOG=fac_LOG+log10(i);
      arr[i]=fac_LOG;
    }
    int k=0;
    while(test_case--)
    {
        k++;
        long long dn,base;
        cin>>dn>>base;
        double ans=(double)arr[dn];
        ans = ans/(log10(base))+1;
        cout<<"Case "<<k<<": "<<(int)ans<<endl;
    }
}
