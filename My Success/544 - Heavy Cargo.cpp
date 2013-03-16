/*
Shiakh Shiam Rahman 
UVa : 544 - Heavy Cargo
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

int main()
{
    READ("in.txt");
    map<string,int> m;
    int c,r,cost,cases = 1;
    int d[205][205];
    while(scanf("%d %d",&c,&r)&&(c||r))
    {
        memset(d,-1,sizeof(d));
        REP(i,205) d[i][i] = 0 ;
        string a,b;
        int index = 0 ;
        REP(i,r)
        {
            cin>>a>>b>>cost;
            if(!m[a]) m[a] = index++;
            if(!m[b]) m[b] = index++;
            d[m[a]][m[b]] = cost;
            d[m[b]][m[a]] = cost;
        }
        REP(k,c+1) REP(i,c+1) REP(j,c+1) d[i][j]=d[j][i]= max (d [i] [j], min (d [i] [k], d [k] [j]));
        string source, dest;
        cin >> source >> dest;
        printf ("Scenario #%d\n", cases++);
        printf ("%d tons\n\n", d [m [source]] [m [dest]]);
        m.clear();
    }
    return 0;
}


