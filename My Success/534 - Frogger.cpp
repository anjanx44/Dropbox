/*
Shiakh Shiam Rahman 
UVa : 534 - Frogger
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
}g[100*100+10];

bool comp(G a,G b){
    return a.cost<b.cost;
}

int main()
{
    READ("in.txt");
    vector<pii> v;
    int cas = 1 ;
    int n;
    while(scanf("%d",&n)&&n)
    {
        double d[205][205];
        memset(d,-1,sizeof(d));
        REP(i,205) d[i][i] = 0 ;
        double x,y;
        REP(i,n)
        {
            scanf("%lf %lf",&x,&y);
            v.pb(make_pair(x,y));
        }

        REP(i,v.size()-1)
        {
            pii p1,p2;
            p1 = v[i];
            double x1 = v[i].first, y1 = v[i].second;

            FOR(j,i+1,v.size()-1)
            {
                p2 = v[j];
                double x2 = v[j].first, y2 = v[j].second;
                double dis = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                d[i][j]=d[j][i] = dis;
            }
        }
        REP(i,205) d[i][i] = 0;
        int c  = n;
        REP(k,c+1) REP(i,c+1) REP(j,c+1) d[i][j]=d[j][i]= min (d [i] [j], max (d [i] [k], d [k] [j]));
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cas++,d[0][1]);
        v.clear();
    }
    return 0;
}


