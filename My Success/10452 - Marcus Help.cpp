/*
Shiakh Shiam Rahman 
UVa : 10452 - Marcus Help
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<utility>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<list>
#include<iterator>
#include <bitset>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define CLEAR(t) memset((t), 0, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI 3.1415926535897932384626433832
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define PS(S) printf(S)

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T n) { return n*n; }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
template< class T > T power(T N,T P){ if(P==0) return 1; return (P==1)?  N: N*power(N,P-1); }

int x,y;
char g[10][10];

void src(int a,int b,char ch)
{
    if(g[a-1][b]==ch)
    {
        x=a-1;y=b;
        PS("forth");
    }
    if(g[a][b-1]==ch)
    {
        x=a;y=b-1;
        PS("left");
    }
    if(g[a][b+1]==ch)
    {
        x=a;y=b+1;
        PS("right");
    }
}

int main()
{
    READ("in.txt");
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int m,n;
        scanf("%d%d",&m,&n);// 6 5
        getchar();
        REP(i,m){
            REP(j,n){
                char c;
                scanf("%c",&c);
                g[i][j] = c;
                if(c=='@'){x=i;y=j;}
            }
            getchar();
        }
        char tar[] = "@IEHOVA#";
        REP(i,7)
        {
            src(x,y,tar[i+1]);
            if(i<6) PS(" ");
        }
        PS("\n");
    }
    return 0;
}

