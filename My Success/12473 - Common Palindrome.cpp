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

string A,B,findLcs;

int dp[60][60];

int len(int l,int r)
{
    if(l>r) return 0;
    if(l==r) return 1;
    if(dp[l][r]) return dp[l][r];
    if(findLcs[l]==findLcs[r])
        dp[l][r] = 2 + len(l+1,r-1);
    else
        dp[l][r] = max(len(l+1,r),len(l,r-1));
    return dp[l][r];
}

void P_LCS(int i,int j){
    if(i==0 || j==0) return;
    if(A[i-1] == B[j-1]){
        P_LCS(i-1,j-1);
        findLcs.push_back(A[i-1]); pf("%c",A[i-1]);
    }else if(dp[i-1][j] > dp[i][j-1]){
    	P_LCS(i-1,j);
    }else
        P_LCS(i,j-1);
}

int main() {
    READ("in.txt");
    int tc,cas=1;
    cin>>tc;
    while(tc--) {
        pf("Case %d: ",cas++);
        cin>>A>>B;
        memca(dp);
        repl(i,A.size()) repl(j,B.size()) {
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
        findLcs.clear();
        P_LCS(A.size(),B.size());puts("");
        memca(dp);
        int ans = len(0,findLcs.size()-1);
        pf("%d\n",ans);
    }
    return 0;
}
