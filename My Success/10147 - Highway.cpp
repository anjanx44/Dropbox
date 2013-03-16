/*
Shiakh Shiam Rahman 
UVa : 10147 - Highway
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
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cclear(x,y) memset(x,y,sizeof(x));
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define SDi(x) scanf("%d",&x)
#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}
typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E18;

double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}

const i64 INFFF=1e16;

vector < int > pset(1000);
void initSet(int _size){ pset.resize(_size); FOR(i,0,_size-1) pset[i]=i;}
int findSet(int i){return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));}
void unionSet(int i,int j){ pset[findSet(i)]=findSet(j);}
bool isSameSet(int i,int j){ return findSet(i)==findSet(j);}

#define G struct krus
G
{
    int u;
    int v;
    double w;
}g[3000000];
bool comp(G a,G b){
    return a.w<b.w;
}

void krus(int edge)
{
    bool print = false;
    for(int i=0;i<edge;i++)
        if(!isSameSet(g[i].u,g[i].v))
        {
            unionSet(g[i].u,g[i].v);
            printf("%d %d\n",g[i].u,g[i].v);
            print = true;
        }
    if(!print)
        printf("No new highways need\n");
}


int main()
{
    READ("in.txt");
    int t;
    cin>>t;
    while(t--)
    {
        map<int,pii> m;
        int city;
        cin>>city;
        initSet(city+10);
        rep(i,city)
        {
            int x,y;
            SDi(x);SDi(y);
            m[i+1] = pmp(x,y);
        }
        int build;
        cin>>build;
        rep(i,build)
        {
            int a,b;
            SDi(a);SDi(b);
            if(!isSameSet(a,b))
                unionSet(a,b);
        }
        int edge = 0;
        repl(i,city-1)
            FOR(j,i+1,city)
            {
                    g[edge].u = i;
                    g[edge].v = j;
                    g[edge].w = sqrt((double)distsq(m[i].first,m[i].second,m[j].first,m[j].second));
                    edge++;
            }

        sort(g,g+edge,comp);
        krus(edge);
        if(t) puts("");
    }
    return 0;
}
