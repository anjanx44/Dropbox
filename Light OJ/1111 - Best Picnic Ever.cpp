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

/*** typedef ***/

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
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E18;

template<class T> inline T gcd(T a,T b) {if(a<0)return
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}

#define black 1


const i64 INFFF=1e16;

vi edge[1010];
int cnt;
int k,n,m;
int pic[1010],dfs_num[1010];

void dfs(int sor)
{
    pic[sor]++;
    if(pic[sor]==k)
        cnt++;
    dfs_num[sor]=black;
    rep(i,edge[sor].size())
       if(dfs_num[edge[sor][i]]!=black)
           dfs(edge[sor][i]);
}

int main()
{
    //READ("in.txt");
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        memca(pic);
        vi pep;
        SD3(k,n,m);
        rep(i,k)
        {
            int z;
            SDi(z);
            pep.pb(z);
        }
        rep(i,m)
        {
            int u,v;
            SD2(u,v);
            edge[u].pb(v);
        }
        cnt=0;
        rep(i,k){
            memca(dfs_num);
            dfs(pep[i]);
        }
        pf("Case %d: ",cas++);
        pf("%d\n",cnt);
        rep(j,1010)
            edge[j].clear();
    }
    return 0;
}
