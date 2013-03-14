
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
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cclear(x,y) memset(x,y,sizeof(x));
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define MAX 100000

#define SDi(x) scanf("%d",&x)
#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}
typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E18;

double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return
r;}

double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(long long a){if(a==0) return "0";string ret;for(long long i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(ret.begin(),ret.end());return ret;}

vector< string > token( string a, string b )
{
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(),
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
int isvowel(char s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}
int isupper(char s) {if(s>='A' and s<='Z') return 1; return 0;}
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}

//bool operator < ( const node& p ) const {      return dist > p.dist;   }

int SET(int N,int pos){	return N=N | (1<<pos);}
int RESET(int N,int pos){	return N= N & ~(1<<pos);}
int check(int N,int pos){	return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=RESET(N,pos);return N=SET(N,pos);}
void PRINTBIT(int N){	printf("("); for(int i=6;i>=1;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}

const i64 INFFF=1e16;

#define DFS_WHITE 0
#define DFS_GRAY 1
#define DFS_BLACK 2

stack< int >dfs_scc;
set< int > in_stack;

int dfsNumberCounter = 0;
int dfs_low[MAX],dfs_num[MAX];

vector< int > edge[MAX];

void tarjanSSC(int u)
{
    dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
    dfs_scc.push(u);in_stack.insert(u);
    rep(i,edge[u].size())
    {
        if(dfs_num[edge[u][i]]==DFS_WHITE)
            tarjanSSC(edge[u][i]);
        if(in_stack.find(edge[u][i])!=in_stack.end())
            dfs_low[u] = min(dfs_low[u],dfs_low[edge[u][i]]);
    }
    if(dfs_low[u]==dfs_num[u])
    {
        printf("SSC: ");
        while(!dfs_scc.empty()&&dfs_scc.top()!=u)
        {
            printf("%d ",dfs_scc.top()); in_stack.erase(dfs_scc.top());dfs_scc.pop();
        }
        printf("%d\n",dfs_scc.top());in_stack.erase(dfs_scc.top());dfs_scc.pop();
    }
}

int main()
{
    READ("in.txt");
    int n,e,t;
    cin>>t;
    while(t--)
    {
        scanf("%d %d",&n,&e);
        rep(i,e)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            edge[x].pb(y);
        }
        tarjanSSC(1);
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 100000
#define LL unsigned long long
using namespace std;

vector <int> Edges [N + 10];
vector <int> rEdges [N + 10];
bool vis [N + 10];
vector <int> sortedNode;
int comp [N + 10];
int in [N + 10];

void reset ()
{
    for ( int i = 0; i < N + 10; i++ ) {
        Edges [i].clear ();
        rEdges [i].clear ();
    }

    sortedNode.clear ();
    memset (vis, false, sizeof (vis));
    memset (in, 0, sizeof (in));
}

void dfs1 (int x)
{
	vis [x] = true;

	for ( size_t u = 0; u < Edges [x].size (); u++ )
		if ( !vis [Edges [x] [u]] ) dfs1 (Edges [x] [u]);

	sortedNode.push_back (x);
}

void dfs2 (int x, int c)
{
	vis [x] = false;
	comp [x] = c;

	for ( size_t u = 0; u < rEdges [x].size (); u++ )
		if ( vis [rEdges [x] [u]] ) dfs2 (rEdges [x] [u], c);
}

int main ()
{
	int testCase;
	scanf ("%d", &testCase);

	while ( testCase-- ) {
		int n, m;
		scanf ("%d %d", &n, &m);

		reset ();

		for ( int i = 0; i < m; i++ ) {
			int a, b;
			scanf ("%d %d", &a, &b);
			Edges [a].push_back (b);
			rEdges [b].push_back (a);
		}

		for ( int i = 1; i <= n; i++ )
			if ( !vis [i] ) dfs1 (i);

		int c = 0;

		for ( int i = sortedNode.size () - 1; i >= 0; i-- ) {
			if ( vis [sortedNode [i]] )
                dfs2 (sortedNode [i], ++c);
		}

		for ( int i = 1; i <= n; i++ ) {
			for ( size_t j = 0; j < Edges [i].size (); j++ ) {
				if ( comp [i] != comp [Edges [i] [j]] )
					in [comp [Edges [i] [j]]]++;
			}
		}

		int cnt = 0;

		for ( int i = 1; i <= c; i++ )
			if ( !in [i] ) cnt++;

		printf ("%d\n", cnt);
	}

	return 0;
}
*/
