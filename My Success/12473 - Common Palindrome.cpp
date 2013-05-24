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

string A,B;
int dp[60][60][60][60];
/*
int call(int al,int ar,int bl,int br){
    if( al>ar || bl>br )
        return 0;
    if(al == ar && bl == br){
        if(A[al]==B[bl] and A[ar]==B[br] and A[al]==A[ar] and B[bl]==B[br]){
           return 1;
        } else if(al == ar || bl == br){
            return 0;
        }
    }
    if(A[al]==B[bl] and A[ar]==B[br] and A[al]==A[ar] and B[bl]==B[br])
        return 2 + call(al+1,ar-1,bl+1,br-1);

    if(dp[al][ar][bl][br]!=-1)
        return dp[al][ar][bl][br];

    int p = max(call(al+1,ar,bl,br),max(call(al,ar-1,bl,br),max(call(al,ar,bl+1,br),call(al,ar,bl,br-1))));
    int q = max(call(al+1,ar,bl+1,br),max(call(al,ar-1,bl,br-1),max(call(al,ar-1,bl+1,br),call(al+1,ar,bl,br-1))));
    int r = max(call(al+1,ar-1,bl+1,br),max(call(al+1,ar-1,bl,br-1),max(call(al,ar-1,bl+1,br-1),call(al+1,ar,bl+1,br-1))));
    return dp[al][ar][bl][br] = max(p,max(q,r));
}
*/

int call(int al,int ar,int bl,int br) {
    if( al>ar || bl>br )
        return 0;

    if(dp[al][ar][bl][br]!=-1)
        return dp[al][ar][bl][br];

    if(al == ar || bl == br) {
        if(A[al]==B[bl] and A[ar]==B[br] and A[al]==A[ar] and B[bl]==B[br]) {
            return 1;
        } else if(al == ar and bl!=br) {
            return dp[al][ar][bl][br] = max(call(al,ar,bl+1,br),call(al,ar,bl,br-1)) ;
        } else if(bl == br and al!=ar) {
            return dp[al][ar][bl][br] = max(call(al+1,ar,bl,br),call(al,ar-1,bl,br)) ;
        } else {
            return 0;
        }
    }
    if(A[al]==B[bl] and A[ar]==B[br] and A[al]==A[ar] and B[bl]==B[br])
        return 2 + call(al+1,ar-1,bl+1,br-1);

    int p = max(call(al+1,ar,bl,br),max(call(al,ar-1,bl,br),max(call(al,ar,bl+1,br),call(al,ar,bl,br-1))));
    return dp[al][ar][bl][br] = p;

}

int main() {
    READ("in.txt");
    int tc,cas=1;
    cin>>tc;
    while(tc--) {
        pf("Case %d: ",cas++);
        memdp(dp);
        cin>>A>>B;
        int ans = call(0,A.size()-1,0,B.size()-1);
        pf("%d\n",ans);
    }
    return 0;
}
