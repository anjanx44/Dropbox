/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman

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

# define MAX 110
using namespace std;
int flag=0,blackNode;
vector <int >G[MAX];
map<int , int > m;
int taken[MAX];

vi bfs(int sor) {
    queue<int> q;
    vector <int> lycan,wolves;
    q.push(sor);

    int color[MAX]= {0};
    taken[sor]=1;
    color[sor]=1;
    lycan.push_back(sor);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(color[u]==0&&!taken[u]) {
            color[u] = 1;
            lycan.push_back(u);
        }
        for(unsigned j=0; j<G[u].size(); j++) {
            unsigned v=G[u][j];
            if(!taken[v]) {
                taken[v]=1;
                if(color[u]==1) {
                    wolves.push_back(v);
                    color[v]=2;
                } else {
                    lycan.push_back(v);
                    color[v]=1;
                }
                q.push(v);
            }
        }
    }
    if(wolves.size()){
        if(wolves.size() > lycan.size()){
            return wolves;
        } else {
            return lycan;
        }
    } else {
        return lycan;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif

    unsigned e,i,cas,node;
    scanf("%d",&cas);
    while(cas--) {
        memset(taken,0,sizeof(taken));
        //printf("Case %d: ",j++);
        scanf("%d %d",&node,&e);
        for(i=1; i<=e; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        vi ans;
        repl(i,node){
            if(!taken[i]){
                vi recieve = bfs(i);
                rep(j,recieve.size())
                    ans.pb(recieve[j]);
            }
        }
        pf("%u\n",ans.size());
        sort(all(ans));
        pf("%d",ans[0]);
        repl(i,ans.size()-1){
            pf(" %d",ans[i]);
        } puts("");
        int i=110;
        while(i--)
            G[i].clear();
        ans.clear();
    }
    return 0;
}
