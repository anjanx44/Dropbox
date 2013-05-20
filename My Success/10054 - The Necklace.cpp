/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 10054 - The Necklace
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

int found[60],deg[60],g[60][60];

bool isConnected(){
    queue< int > q;
    int m,color[51];
    repl(i,50) color[i] = (found[i]?0:2);
    for(m=1;color[m];++m); color[m] = 1;
    q.push(m);
    while(q.size()){
        int u = q.front();q.pop();
        repl(i,50){
            if( g[u][i] && !color[i]){
                q.push(i);
                color[i] = 1;
            }
        }
        color[u] = 2;
    }
    repl(i,50)
        if(color[i] != 2) return false;
    return true;
}

bool hasEularPath(){
    if(!isConnected()) return false;
    repl(i,50){
        if(deg[i]&1) return false;
    }
    return true;
}

void findCycle(int u){
    repl(v,50)
        if(g[u][v]){
            g[u][v]--;
            g[v][u]--;
            findCycle(v);
            pf("%d %d\n",v,u);
        }
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        pf("Case #%d\n",cas++);
        int m;
        memca(deg),memca(g),memca(found);
        SDi(m);
        rep(i,m){
            int u,v;
            SD2(u,v);
            deg[u]++;
            deg[v]++;
            found[u] = found[v] = 1,g[u][v]++;g[v][u]++;
        }
        if(hasEularPath()){
            for(m=1;!deg[m];m++);
                findCycle(m);
        }
        else puts("some beads may be lost");
        if(tc) puts("");
    }
    return 0;
}
