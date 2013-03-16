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

#define MAX 10010

vector< int > G[MAX];
int low[MAX], vis[MAX], used[MAX],  dfsCounter,n,m,cnt,ans,cuts,ncome;
bool cut[MAX];
void ArticulationPoint(int u, int par = -1) {
	int i, v, child = 0;
	used[u] = 1;
	vis[u] = low[u] = ++dfsCounter;
	for(i = 0; i < (int)G[u].size(); i++) {
		v = G[u][i];
		if(v == par) continue;
		if(used[v]) low[u] = min(low[u], vis[v]);
		else {
			child++;
			ArticulationPoint(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= vis[u]) cut[u] = 1;
		}
	}
	if(par == -1) cut[u] = (child > 1);
}

void dfs(int u){
    used[u]=1,cnt++;
    int sz = G[u].size(),v;
    rep(i,sz){
        v = G[u][i];
        if(!used[v] and !cut[v])
            dfs(v);
        if(cut[v] and used[v] != ncome + 1){
            cuts++;
            used[v] = ncome + 1;
        }
    }
}

int main()
{
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        ui64 nways;
        pf("Case %d: ",cas++);
        SD2(n,m);
        rep(i,m){
            int x,y;
            SD2(x,y);
            G[x].pb(y);
            G[y].pb(x);
        }
        memca(low),memca(vis),memca(used),memca(cut);
        dfsCounter = cnt = ans = ncome = 0,nways = 1;
        ArticulationPoint(0,-1);
        memca(used);
        rep(i,n){
            if(!used[i] and !cut[i]){
                cnt = cuts = 0;
                dfs(i);
                ncome++;
                if(cuts<2){
                    ans++;
                    nways*=cnt;
                }
            }
        }
        if(ans == 1){
            nways = n*(n-1)/2;
            ans++;
        }
        pf("%d %llu\n",ans,nways);
        int cl = n + 2;
        while(cl--) G[cl].clear();
    }
    return 0;
}
