/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa : 12616 - Gymman vs Fila
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

using namespace std;

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
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAX 20010
vector < int > G[MAX],tN;
int low[MAX],vis[MAX],prev[MAX],dfscounter;
ui64 cnt,ans,sum,cur;
bool cut[MAX];

int dfs(int u){
    int sz = G[u].size(),v,ret = 1;
    rep(i,sz){
        v = G[u][i];
        if(prev[v] == -1){
            prev[v] = u;
            ret+=dfs(v);
        }
    }
    return ret;
}

int articulationPoint(int u , int par){
    int v, r2 = 0,r, child = 0,sz = G[u].size(), ret = 1;
    vector< int > package;
    vis[u] = low[u] = ++dfscounter;
    rep(i,sz){
        v = G[u][i];
        if(v == par ) continue;
        else if(vis[v]) low[u] = min(low[u],vis[v]);
        else{
            child++;
            r = articulationPoint(v,u);
            ret+=r;
            low[u] = min(low[u],low[v]);
            if(low[v] >= vis[u]){
                cut[u] = 1;
                package.pb(r);
                r2+=r;
            }
        }
    }
    if(par == -1) cut[u] = (child > 1);
    if(cut[u]){
        if(par != -1)
            package.pb(tN.at(cur) - r2 - 1);
        sum = 0,sz = package.size();
        rep(j,sz){
            r2 = package[j];
            ans += sum*package[j];
            sum += package[j];
        }
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int cas=1,tc;
    cin>>tc;
    while(tc--){
        pf("Case %d: ",cas++);
        int n,m;
        SD2(n,m);
        rep(i,m){
            int x,y;
            SD2(x,y);
            G[x].pb(y);
            G[y].pb(x);
        }
        memca(low),memca(vis),memdp(prev),memca(cut);
        dfscounter = cnt = ans = sum = cur = 0;
        int ret;
        rep(i,n){
            if(prev[i+1]==-1){
                prev[i+1] = -2;
                ret = dfs(i+1);
                tN.pb(ret);
            }
        }
        rep(i,n){
            if(vis[i+1] == 0){
                articulationPoint(i+1,-1);
                cur++;
            }
        }
        cout<< 2*ans <<endl;
        rep(i,MAX) G[i].clear();
        tN.clear();
    }
    return 0;
}
