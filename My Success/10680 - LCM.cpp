/*
Shiakh Shiam Rahman 
UVa : 10680 - LCM
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

#define stream istringstream
#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define REP2(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI 3.14159265358979323846264338327950
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define CLEAR(x) memset(x,0,sizeof(x));
#define eps 1e-9
#define CLEAR(x) memset(x,0,sizeof(x));
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define SDi(x) scanf("%d",&x)
#define SDl(x) scanf("%lld",&x)
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
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}

string itoa(long long a){string ret;for(long long i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(ret.begin(),ret.end());return ret;}

vector< string > token( string a, string b )
{
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(),
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}

#define  MX 1200
int N =MX,prime[20001];
bool  status[MX+100];

int taken[1000004];
int out[1000004];


int main()
{
  int i, j, sqrtN;

  sqrtN = int( sqrt( N ) );
  for( i = 2; i <= sqrtN; i += 1 )
    if( status[i] == 0 )
       for( j = 2*i; j <= N; j += i )
          status[j] = 1;

  prime[0]=2;
  for( i = 3,j=1; i <= N; i += 2 )
    if( status[i] == 0 )
        prime[j++]=i;
	i64 LCM=1;
	out[1]=1;
	for(int loop=2;loop<=1000000;loop++)
	{
        int n=loop;
		int sqrtN = int( sqrt(n) );
		for( int i = 0; prime[i] <= sqrtN; i++ )
		{
			if( n % prime[i] == 0 )
			{
				int cnt=0;
				while(n%prime[i]==0)
				{
					cnt++;
					n/=prime[i];
				}
				if(cnt>taken[prime[i]])
				{
					for(int j=1;j<=cnt-taken[prime[i]];j++)
					{
						LCM=(LCM%1000000*prime[i]%1000000)%1000000;
						while(LCM%10==0)LCM/=10;
					}
					taken[prime[i]]=cnt;
				}
				sqrtN=sqrt(n);
			}
		}
		if(n>1)
		{
			if(!taken[n])
			{
				LCM=(LCM%1000000*n%1000000)%1000000;
				while(LCM%10==0)LCM/=10;
				taken[n]=1;
			}

		}
		out[loop]=LCM%10;
	}
	int n;
	while(SDi(n)==1 and n)
		printf("%d\n",out[n]);
}
