/*
Shiakh Shiam Rahman 
UVa : 10041 - Vito's Family
*/
#include <iostream>
#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int arr[30010];
    vector<int> sum ;
    int cas;
    cin>>cas;
    while(cas--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int m;
        for(int i=0;i<n;i++){
            m = 0;
            for(int j=0;j<n;j++)
                m+=abs(arr[i]-arr[j]);
            sum.push_back(m);
        }
        sort(sum.begin(),sum.end());
        printf("%d\n",sum[0]);
        sum.clear();
    }
    return 0;
}
