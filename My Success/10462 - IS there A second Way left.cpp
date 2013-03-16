/*
Shiakh Shiam Rahman 
UVa : 10462 - IS there A second Way left
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
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define pii pair<double,double>
#define G struct node

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


vector < int > pset(1000);
void initSet(int _size){ pset.resize(_size); FOR(i,0,_size-1) pset[i]=i;}
int findSet(int i){return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));}
void unionSet(int i,int j){ pset[findSet(i)]=findSet(j);}
bool isSameSet(int i,int j){ return findSet(i)==findSet(j);}

G {
int u;
int v;
double cost;
}g[220];

bool comp(G a,G b){
    return a.cost<b.cost;
}

int n,e;

int BMST2(int p)
{
    initSet(n+3);
    int mstlen = 0;
    int sum2 = 0;
    for(int i=0;i<e;i++)
    {
        if(i==p)
            continue;
        else if(!isSameSet(g[i].u,g[i].v))//findSet(g[i].u)!=findSet(g[i].u))
        {
            mstlen++;
            sum2 += g[i].cost;
            unionSet(g[i].u,g[i].v);
        }
    }
    if(mstlen<n-1) return -1;
    return sum2;
}

int main()
{
    READ("in.txt");
    vector< int > v;
    int cas,kas = 1;
    scanf("%d",&cas);
    while(cas--)
    {
        printf("Case #%d : ",kas++);
        v.clear();
        scanf("%d %d",&n,&e);
        REP(i,e)
        {
            int x,y,cost;
            scanf("%d %d %d",&x,&y,&cost);
            g[i].u = x;
            g[i].v = y;
            g[i].cost = cost;
        }
        initSet(n+3);

        sort(g,g+e,comp);

        double sum = 0.0;
        for(int i=0;i<e;i++)
        {
            if(!isSameSet(g[i].u,g[i].v))//findSet(g[i].u)!=findSet(g[i].u))
            {
                v.pb(i);
                sum += g[i].cost;
                unionSet(g[i].u,g[i].v);
            }
        }
        if((int)v.size()<n-1)
        {
            puts("No way");
            continue;
        }
        int in,best = 21474836,index = 0;
        bool f = true;
        REP(i,v.size())
        {
            index = v[i];
            in = BMST2(index);
            if(in==-1) continue;
            if(in<best)
            {
                best = in;
                f = false;
            }
        }
        if(f) puts("No second way");
        else printf("%d\n",best);
    }
    return 0;
}
