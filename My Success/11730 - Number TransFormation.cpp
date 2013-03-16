/*
Shiakh Shiam Rahman 
UVa : 11730 - Number TransFormation
*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int dis[1010];
#define  MX 1200
int N = MX,prime[20001];
bool  status[MX+100];

void prim()
{
  int i, j, sqrtN;

  sqrtN = int( sqrt( N ) );
  for( i = 2; i <= sqrtN; i += 1 )
    if( status[i] == 0 )
       for( j = 2*i; j <= N; j += i )
          status[j] = 1;

  prime[0]=2;
  for( i = 3,j=1; i <= N; i += 2 )
    if( status[i] == 0 )
        prime[j++]=i;
}

void call(int n)
{
    for(int i=0;prime[i]<n;i++)
    {
        if(n%prime[i]==0)
            if((dis[n+prime[i]] > dis[n]+1) && n+prime[i]<=1000)
                dis[n+prime[i]] = dis[n]+1;
    }
}

int main()
{
    READ("in.txt");
    //WRITE("out.txt");
    prim();
    int cas=1;
    int s,t;
    while(SD2(s,t) && s && t )
    {
        pf("Case %d: ",cas++);
        memsp(dis);
        dis[s] = 0;
        if(s==t){ puts("0");continue;}
        for(int i=s;i<t;i++)
        {
            if(dis[i]!=dis[0])
                call(i);
        }
        if(dis[t]!=dis[0])
            pf("%d\n",dis[t]);
        if(dis[0]==dis[t]) puts("-1");
    }
    return 0;
}
