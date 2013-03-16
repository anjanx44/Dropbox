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
#define nd 510
template< class T > T _abs(T n) {
    return (n < 0 ? -n : n);
}
template< class T > T sq(T n) {
    return n*n;
}
template< class T > T _max(T a, T b) {
    return (!(a < b) ? a : b);
}
template< class T > T _min(T a, T b) {
    return (a < b ? a : b);
}
template< class T > T gcd(T a, T b) {
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b) {
    return (a / gcd<T>(a, b) * b);
}
template< class T > bool inside(T a, T b, T c) {
    return a<=b && b<=c;
}
template< class T > void setmax(T &a, T b) {
    if(a < b) a = b;
}
template< class T > void setmin(T &a, T b) {
    if(b < a) a = b;
}
template< class T > T power(T N,T P) {
    if(P==0) return 1;
    return (P==1)?  N: N*power(N,P-1);
}

vector<int> edge[nd], cost[nd];
int n,m;

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

void dijkstra(int source, int d[]) {
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while( !q.empty() ) {
        u = q.top();
        q.pop();
        int ucost = d[ u.city ];

        for(U i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i];
            int res = min(d[v.city],max(v.dist,ucost));
            if(d[v.city]>res) {
                d[v.city] = res;
                q.push( v );
            }
        }
    }
}

int main() {
    //READ("in.txt");
    int t,cas=1;
    cin>>t;
    while(t--) {
        printf("Case %d:\n",cas++);
        cin>>n>>m;
        int d[n];
        memset(d,63,sizeof(d));
        REP(i,m) {
            int a,b,dis;
            scanf("%d %d %d",&a,&b,&dis);
            edge[a].pb(b);
            edge[b].pb(a);
            cost[a].pb(dis);
            cost[b].pb(dis);
        }
        int sor;
        cin>>sor;
        dijkstra(sor,d);
        REP(i,n) {
            if(d[i]==1061109567) puts("Impossible");
            else printf("%d\n",d[i]);
        }
        while(n--) {
            edge[n].clear();
            cost[n].clear();
        }
    }
    return 0;
}
