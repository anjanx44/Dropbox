/*
Shiakh Shiam Rahman 
UVa : 10603 - Fill
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
#define PI 3.14159265358979323846264338327950
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

#define state struct st
state
{
    int a,b,c;
};

int sum[200][200][200];
bool visit[200][200][200];

int main()
{
    READ("in.txt");
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        bool print = false;
        cin>>a>>b>>c>>d;
        mem(visit,false);
        mem(sum,0);
        queue<state> q;
        state u,v,col;
        u.a = 0,u.b = 0, u.c = c;
        col.a = u.a,col.b = u.b, col.c = u.c;
        q.push(u);
        sum[u.a][u.b][u.c] = 0;
        visit[u.a][u.b][u.c] = true;
        int close=0;
        while(!q.empty())
        {
            u = q.front();q.pop();
            //v.a = u.a, v.b = u.b, v.c = u.c;
            if(u.a==d||u.b==d||u.c==d)
            {
                print = true;
                printf("%d %d\n",sum[u.a][u.b][u.c],d);
                break;
            }
            //a->b
            v.a = u.a, v.b = u.b, v.c = u.c;
            if(u.a+u.b>b)
            {
                v.a = u.a+u.b - b;
                v.b = b;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.a-v.a ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            else
            {
                v.a = 0;
                v.b =  u.a+u.b;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.a ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            if(!visit[v.a][v.b][v.c])
                q.push(v);
            visit[v.a][v.b][v.c] = true;
            //a-> c
            v.a = u.a, v.b = u.b, v.c = u.c;
            if(u.a+u.c>c)
            {
                v.a = u.a+u.b - c;
                v.c = c;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.a-v.a ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            else
            {
                v.a = 0;
                v.c =  u.a+u.c;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.a ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            if(!visit[v.a][v.b][v.c])
                q.push(v);
            visit[v.a][v.b][v.c] = true;
            //b->a
            v.a = u.a, v.b = u.b, v.c = u.c;
            if(u.a+u.b>a)
            {
                v.b = u.a+u.b - a;
                v.a = a;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.b-v.b ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            else
            {
                v.b = 0;
                v.a =  u.a+u.b;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.b ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            if(!visit[v.a][v.b][v.c])
                q.push(v);
            visit[v.a][v.b][v.c] = true;
            //b->c
            v.a = u.a, v.b = u.b, v.c = u.c;
            if(u.c+u.b>c)
            {
                v.b = u.c+u.b - c;
                v.c = c;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.b-v.b ;
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            else
            {
                v.b = 0;
                v.c =  u.c+u.b;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.b ;
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            if(!visit[v.a][v.b][v.c])
                q.push(v);
            visit[v.a][v.b][v.c] = true;
            //c->a
            v.a = u.a, v.b = u.b, v.c = u.c;
            if(u.a+u.c>a)
            {
                v.c = u.a+u.c - a;
                v.a = a;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.c-v.c ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            else
            {
                v.c = 0;
                v.a =  u.a+u.c;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.c ;
                if(v.a>close&&v.a<d)
                {
                    close = v.a;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            if(!visit[v.a][v.b][v.c])
                q.push(v);
            visit[v.a][v.b][v.c] = true;
            //c->b
            v.a = u.a, v.b = u.b, v.c = u.c;
            if(u.c+u.b>b)
            {
                v.c = u.c+u.b - b;
                v.b = b;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c]  = sum[u.a][u.b][u.c]+u.c-v.c ;
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            else
            {
                v.c = 0;
                v.b =  u.c+u.b;
                if(!visit[v.a][v.b][v.c])
                    sum[v.a][v.b][v.c] = u.c ;
                if(v.c>close&&v.c<d)
                {
                    close = v.c;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
                if(v.b>close&&v.b<d)
                {
                    close = v.b;
                    col.a = v.a,col.b = v.b, col.c = v.c;
                }
            }
            if(!visit[v.a][v.b][v.c])
                q.push(v);
            visit[v.a][v.b][v.c] = true;
        }
        if(!print)
        {
            if(close==0)
                puts("0 0");
            else
                printf("%d %d\n",sum[col.a][col.b][col.c],close);
        }
    }
    return 0;
}
