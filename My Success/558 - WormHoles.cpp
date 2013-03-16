/*
Shiakh Shiam Rahman 
UVa : 558 - WormHoles
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

/*** typedef ***/

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define memsp(x) mem(x,MEMSET_INF,sizeof(x));
#define memdp(x) mem(x,-1,sizeof(x));
#define memca(x) mem(x,0,sizeof(x));
#define eps 1e-9
#define ii pair<int,int>
#define pmp make_pair
#define vi vector<int>
#define vii vector<ii>
#define si set<int>
#define msi map<string , int >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) scanf("%d",&x)
#define SDi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SDi2(x,y) scanf("%d%d",&x,&y)
#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E18;
vi edge[1010],cost[1010];
int m,n;
vi distan;

void bellman_ford(int sor,int dis)
{
    vi dist(n,INF);
    dist[sor]=0;
    rep(u,n){
        rep(i,n){
            rep(j,edge[i].size()){
                int co = edge[i][j];
                dist[co] = min(dist[co],cost[i][j]+dist[i]);
                //cout<<i<<" "<<co<<" "<<dist[co]<< "\n";
            }
            //puts("");
        }
        /*cout<<"count : "<<u<<"\n";
        rep(i,n)
        printf("SSSP(%d %d) = %d\n",sor,i,dist[i]);*/
    }
    /*puts("Final : ");
    rep(i,n)
    printf("SSSP(%d %d) = %d\n",sor,i,dist[i]);*/
    distan = dist;
}
void find_cycle()
{
    rep(i,n){
        rep(j,edge[i].size()){
            int co = edge[i][j];
            if(distan[co]>cost[i][j]+distan[i]){
                puts("possible");
                return;
            }
        }
    }
    puts("not possible");
}

int main()
{
    READ("in.txt");
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,z;
        cin>>n>>m;
        rep(i,m)
        {
            SDi3(x,y,z);
            edge[x].pb(y);
            cost[x].pb(z);
        }
        bellman_ford(0,n-1);
        find_cycle();
        rep(i,n+2)
        {
            cost[i].clear();
            edge[i].clear();
        }
    }
    return 0;
}
