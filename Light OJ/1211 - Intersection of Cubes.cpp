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
#define LL long long
#define U unsigned
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
    int t;
    LL ans;
    int cas=1;
    cin>>t;
    while(t--)
    {
        int n;
        int x1,y1,z1,x2,y2,z2;
        vector< int > a1,b1,c1,a2,b2,c2;
        cin>>n;
        REP(i,n)
        {

            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            a1.pb(x1);b1.pb(y1);c1.pb(z1);a2.pb(x2);b2.pb(y2);c2.pb(z2);
        }
        if(n==1)
            ans = abs(x1-x2)*abs(y1-y2)*abs(z1-z2);
        else
        {
            sort(a1.bg(),a1.end());sort(b1.bg(),b1.end());sort(c1.bg(),c1.end());
            sort(a2.bg(),a2.end());sort(b2.bg(),b2.end());sort(c2.bg(),c2.end());
            int a1max,b1max,c1max;
            a1max = a1[a1.size()-1];b1max = b1[b1.size()-1]; c1max = c1[c1.size()-1];

            int a2min,b2min,c2min;
            a2min = a2[0];b2min = b2[0];c2min = c2[0];
            if((a2min<a1max)&&(b2min<b1max)&&(c2min<c1max))
                ans = 0;
            else
                ans = (a2min-a1max)*(b2min-b1max)*(c2min-c1max);
        }
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
