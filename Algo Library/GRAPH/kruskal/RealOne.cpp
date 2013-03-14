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

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define mx  200010

vector < int > pset(mx);
void initSet(int _size){ pset.resize(_size); FOR(i,0,_size-1) pset[i]=i;}
int findSet(int i){return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));}
void unionSet(int i,int j){ pset[findSet(i)]=findSet(j);}
bool isSameSet(int i,int j){ return findSet(i)==findSet(j);}

vector< pair<int,pii> >p;

int krus(int edge,int ver)
{
    int sum = 0;
    for(int i=0;i<edge;i++)
    {
        //cout<<p[i].sd.ft<<" "<<p[i].sd.sd<<" "<<p[i].ft<<endl;
        if(!isSameSet(p[i].sd.ft,p[i].sd.sd))
        {
            sum+=p[i].ft;
            unionSet(p[i].sd.ft,p[i].sd.sd);
        }
    }
    return sum;
}

int main()
{
    READ("in.txt");
    int m,n;
    while(SD2(n,m)&&m&&n){
        unsigned cost = 0 ;
        rep(i,m){
            int x,y,z;
            SD3(x,y,z);
            p.pb(pmp(z,pmp(x,y)));
            cost+=z;
        }
        initSet(n+10);
        sort(p.begin(),p.end());
        pf("%d\n",cost - krus(m,n));
        p.clear();
    }
    return 0;
}
