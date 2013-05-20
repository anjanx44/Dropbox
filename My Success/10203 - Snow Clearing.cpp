/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 10203 - Snow Clearing
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

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc;
    cin>>tc;
    while(tc--){
        int x,y;
        SD2(x,y);getchar();
        char ch[1000];
        double hr,mn,ans = 0;
        while(gets(ch) and strlen(ch)){
            int a,b,c,d;
            sscanf(ch,"%d %d %d %d",&a,&b,&c,&d);
            double dis = sqrt((a-c)*(a-c) + (b-d)*(b-d))/1000;
            ans+=dis;
        }
        ans*=2;
        hr = ans/20.0;
        hr = (int)hr;
        double lft = ans/20.0 - hr;
        mn = (int)(lft*60);
        if(lft*60.0 - mn > 0.5) mn++;
        if(mn==60){
            hr++;
            mn=0;
        }
        pf("%d:%02d\n",(int)hr,(int)mn);
        if(tc) puts("");
    }
    return 0;
}
