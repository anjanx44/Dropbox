/*
Shiakh Shiam Rahman 
UVa : 10539 - Almost Prime
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define  MX 1000000

using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
# define ull unsigned long long
# define ll long long
# define u unsigned

int N = MX;
bool  status[MX+100];

vector < ll >v,co;
void sieve()
{
    ll i, j, sqrtN;
  sqrtN = (int)( sqrt( N ) );
  for( i = 2; i <= sqrtN; i += 1 )
    if( status[i] == 0 )
       for( j = 2*i; j <= N; j += i )
          status[j] = 1;
    v.push_back(2);
  for( i = 3,j=1; i <= N; i += 2 )
    if( status[i] == 0 )
        v.push_back(i);

}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    sieve();
     int num=0;
    for(u m=0;m<v.size();m++)
    {
       for(ll pr=v[m]*v[m];pr<=1000000000000;pr=pr*v[m])     //1000000000000
       {
            co.push_back(pr);
            num++;
       }
    }
    sort(co.begin(),co.end());
    int y,count=0;
    scanf("%d",&y);
    while(y--)
    {
        ll a,b;
        cin>>a>>b;
        count=0;
        for(int i=0;i<=num;i++)
            if (co[i]>=a&&co[i]<=b )
                count++;
        printf("%d\n",count);
    }
    return 0;
}


