/*
Shiakh Shiam Rahman 
UVa : 567 - Risk
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
#define MAX 1000000000
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

int d[100][100];

int main()
{
    READ("in.txt");
    int a,cas=1;
    while(scanf("%d",&a)==1)
    {
        printf("Test Set #%d\n",cas++);
        REP(i,20) REP(j,20) d[i+1][j+1] = MAX;
        FOR(i,1,19)
        {
            if(i>1) scanf("%d",&a);
            int c;
            while(a--)
            {
                scanf("%d",&c);
                d[i][c]=1;
                d[c][i]=1;
            }

        }
        FOR(k,1,20) FOR(i,1,20) FOR(j,1,20) d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

        int ca;
        scanf("%d",&ca);
        while(ca--)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            printf("%2d to %2d: %d\n",p,q,d[p][q]);
        }
        printf("\n");
    }
    return 0;
}
