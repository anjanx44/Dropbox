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
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define LD double
#define PI acos(-1)
#define mod 10000007
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

int main()
{
    //READ("in.txt");
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        printf("Case %d: ",cas++);
        int x,y;
        pii A,B,C,D;
        scanf("%d%d",&x,&y);
        A = make_pair(x,y);
        scanf("%d%d",&x,&y);
        B = make_pair(x,y);
        scanf("%d%d",&x,&y);
        C = make_pair(x,y);

        D = make_pair(A.first+C.first-B.first,A.second+C.second-B.second);
        double area,a1,a2;
        a1 = A.first*B.second+B.first*C.second+C.first*D.second+D.first*A.second;
        a2 = A.second*B.first+B.second*C.first+C.second*D.first+D.second*A.first;
        area = (a1-a2)/2;
        area = fabs(area);
        printf("%d %d %.lf\n",D.first,D.second,area);
    }
	return 0;
}
