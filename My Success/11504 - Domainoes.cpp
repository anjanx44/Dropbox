/*
Shiakh Shiam Rahman 
UVa : 11504 - Domainoes
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

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define REP2(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI 3.14159265358979323846264338327950
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ size()
#define eps 1e-9
#define VI vector<int>
#define VS vector<string>
#define LL long long
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define CLEAR(x) memset(x,0,sizeof(x));
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}
typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)


double dist(double x1,double y1,double x2,double y2){return
sqr(x1-x2)+sqr(y1-y2);}
double dist(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return
r;}
i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return
r;}
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return
r;}


vector<int>edges[100002];  //edge list
int vis[100002];
int taken[100002];
vector<int>order;
void dfs(int src) //for topsort
{
	if(!vis[src])
	{
		vis[src]=1;
		for(int i=0;i<(int)edges[src].size();i++){
            int v = edges[src][i];
            dfs(v);
		}
		order.PB(src);
	}
}
void find(int src)
{
	if(!taken[src])
	{
		taken[src]=1;
		for(int i=0;i<(int)edges[src].size();i++)find(edges[src][i]);
	}
}
int main()
{
	READ("in.txt");
      int N,E,T,ptr=0;
      cin>>T;
     while(T--)
     {
		 ptr=0;
      scanf("%d%d",&N,&E);
      for(int i=0;i<=N;i++) edges[i].clear();
      REP(i,E)
      {
		  int x,y;
		  scanf("%d%d",&x,&y);
		  edges[x].PB(y);
	  }
	  order.clear();
	  for(int i=1;i<=N;i++)
        dfs(i);
	  int ans=0;

	  CLEAR(taken);
	  CLEAR(vis);
     for(int i=order.size()-1;i>=0;i--)
     {
		 int curr=order[i];
		 if(!taken[curr])
		 {
			 find(curr);
			 ans++;
		 }
	 }
	 printf("%d\n",ans); //printing ans :)
 }
return 0;

}

