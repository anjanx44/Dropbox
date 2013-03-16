/*
Shiakh Shiam Rahman 
UVa : 10360 - Rat Attack
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
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI asos(-1.0)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cclear(x,y) memset(x,y,sizeof(x));
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define SDi(x) scanf("%d",&x)
#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}
typedef long long i64;
typedef unsigned long long ui64;

int killed[1025][1025];

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int main()
{
    READ("in.txt");
    int cas;
    cin>>cas;
    while(cas--)
    {

        memset(killed,0,sizeof(killed));
        int d,n;
        SDi(d);
        SDi(n);
        rep(k,n)
        {
            int x,y,pop;
            scanf("%d %d %d",&x,&y,&pop);
            FOR(i,x-d,x+d){
                if(i<0) continue;
                if(i>1024) break;
                FOR(j,y-d,y+d)
                {
                    if(j<0) continue;
                    if(j>1024) break;
                    killed[i][j]+=pop;
                }
            }
        }
        int maxi = 0,row,col;
        rep(i,1025)
            rep(j,1025)
            {
                if(maxi<killed[i][j])
                {
                    maxi = killed[i][j];
                    row = i;
                    col = j;
                }
            }
        printf("%d %d %d\n",row,col,maxi);
    }
    return 0;
}
