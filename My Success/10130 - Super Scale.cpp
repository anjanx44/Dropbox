/*
Shiakh Shiam Rahman 
UVa : 10130 - Super Scale
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


#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define pf printf
#define sf scanf
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >


#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%l64d",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)


int CAP;
int weight[1010],cost[1010];
int n;
int dp[1010][110];

int func(int i,int w)
{
    if(i>=n) return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    int profit1;
    if(w+weight[i]<=CAP)
        profit1=cost[i]+func(i+1,w+weight[i]);
    else
        profit1=0;
    int profit2=func(i+1,w);

    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}

int main()
{
    READ("in.txt");
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        rep(i,n)
            SD2(cost[i],weight[i]);
        int man;
        SDi(man);
        int ans=0,arr[110];
        memdp(arr);
        rep(i,man)
        {
            memdp(dp);
            SDi(CAP);
            if(arr[CAP]<0)
                arr[CAP] = func(0,0);
            ans+=arr[CAP];
        }
        pf("%d\n",ans);
    }
    return 0;
}
