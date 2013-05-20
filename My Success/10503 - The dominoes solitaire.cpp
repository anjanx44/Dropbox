/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 10503 - The dominoes solitaire
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

int n,m,taken,used[16];
vpii v;
pii lft,rht;
bool found;

void bktk(int side){
    if(taken==n)
        rep(i,m){
            if(!used[i]){
                if(side == v[i].ft and rht.ft == v[i].sd) found = true;
                if(side == v[i].sd and rht.ft == v[i].ft) found = true;
                if(found) return;
            }
        }
    else
        rep(i,m){
            if(!used[i]){
                if(found) return;
                if(side == v[i].ft){
                    used[i] = 1;
                    taken++;
                    bktk(v[i].sd);
                    used[i] = 0;
                    taken--;
                } else if(side == v[i].sd){
                    used[i] = 1;
                    taken++;
                    bktk(v[i].ft);
                    used[i]=0;
                    taken--;
                }
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
	WRITE("out.txt");
#endif
    while(SDi(n) and n){
        SDi(m);
        int x,y;
        SD2(x,y);
        lft = pmp(x,y);
        SD2(x,y);
        rht = pmp(x,y);
        rep(i,m){
            SD2(x,y);
            v.pb(pmp(x,y));
        }
        memca(used);
        taken = 1;
        found = false;
        bktk(lft.sd);
        if(found) puts("YES");
        else puts("NO");
        v.clear();
    }
    return 0;
}
