/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
UVa : 10651 - Pebble Solitaire
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

int SET(int N,int pos){	return N=N | (1<<pos);}
int RESET(int N,int pos){	return N= N & ~(1<<pos);}
int check(int N,int pos){	return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=RESET(N,pos);return N=SET(N,pos);}
void PRINTBIT(int N){	printf("("); for(int i=0;i<12;i++)	{bool x=check(N,i);cout<<x;}	puts(")");}


int dp[(1<<12) + 2],cnt;

int call(int mask){
    if(dp[mask]!=-1) return dp[mask];
    int num  = mask;
    rep(j,10){
        if(check(mask,j) == 0 and check(mask,j+1) != 0 and check(mask,j+2) != 0){
             mask = SET(mask,j), mask = RESET(mask,j+1), mask = RESET(mask,j+2);
             dp[mask] = call(mask);
             mask = num;
        }
        if(check(mask,j) != 0 and check(mask,j+1) != 0 and check(mask,j+2) == 0){
            mask = RESET(mask,j), mask = RESET(mask,j+1), mask = SET(mask,j+2);
            dp[mask] = call(mask);
            mask = num;
        }
    }

    int ans = 0;
    rep(i,12){
        if(check(mask,i))
            ans++;
    }
    cnt = min(cnt,ans);
    return dp[mask] = cnt;
}
int main()
{
    READ("in.txt");
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        cin>>str;
        int mask = 0;
        rep(i,str.size()){
            if(str.at(i) == 'o')
                mask = SET(mask,i);
        }
        memdp(dp);
        cnt = 100;
        int ans = call(mask);

        pf("%d\n",ans);
    }
    return 0;
}
