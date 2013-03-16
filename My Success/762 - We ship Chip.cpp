/*
Shiakh Shiam Rahman 
UVa : 762 - We ship Chip
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<utility>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<list>
#include<iterator>
#include <bitset>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define CLEAR(t) memset((t), 0, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI 3.1415926535897932384626433832
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define U unsigned
#define pii pair<int,int>
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T n) { return n*n; }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
template< class T > T power(T N,T P){ if(P==0) return 1; return (P==1)?  N: N*power(N,P-1); }

map < int , string > tar;
map < string , int > man;
vector < int > G[1000];
int par[1000];
string s1,s2;
int m,n;

int bfs(int src,int dis)
{
    queue<int>Q;
    Q.push(src);
    int taken[1000]={0},distance[1000];
    taken [src]=1;
        distance [src]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        if(u==dis) return u;
        for(int i=0;i<(int)G[u].size();i++)
        {
            int v=G[u][i];
            if(!taken[v])
            {
                par[v] = u;
                distance[v]=distance[u]+1;
                taken[v]=1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    return -1;
}

void print(int dis)
{
    if(m!=dis)
        print(par[dis]);
    if(m!=dis)
        printf("%s %s\n",tar[par[dis]].c_str(),tar[dis].c_str());
}
int main()
{
    READ("in.txt");
    int N;
    bool b = false;
    while(scanf("%d",&N)==1)
    {
        if(b) printf("\n");
        b = true;
        int i = 1;
        while(N--)
        {
            cin>>s1>>s2;
            if(man.find(s1)==man.end())
            {
                man[s1] = i;
                tar[i] = s1;
                i++;
            }
            if(man.find(s2)==man.end())
            {
                man[s2] = i;
                tar[i] = s2;
                i++;
            }
            m = man[s1];
            n = man[s2];
            G[m].pb(n);
            G[n].pb(m);
        }
        cin>>s1>>s2;
        m = man[s1];
        n = man[s2];
        if(m==0 || n==0) printf("No route\n");
        else if(m==n) printf("%s %s\n",tar[m].c_str(),tar[n].c_str());
        else
        {
            int res = bfs(m,n);
            if(res>=0) print(res);
            else printf("No route\n");
        }

        tar.clear();
        man.clear();
        REP(i,1000) G[i].clear();
    }
    return 0;
}
/*

#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int test_case;
    scanf("%d",&test_case);
    for(int i=1;i<=test_case;i++)
    {
        int number,j,max=0,array[10000];
        scanf("%d",&number);
        for(j=0;j<number;j++)
        {
            scanf("%d",&array[j]);
        }

        for(j=0;j<number;j++)
        {
            if(array[j]>=max)
            {
                max=array[j];
            }
        }
        printf("Case %d: %d\n",i++,max);
    }
    return 0;
}
*/
