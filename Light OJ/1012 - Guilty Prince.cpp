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
#define  pii pair<int,int>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define CLEAR(t) memset((t), 0, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
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

string s[21];
int m,n;
map< pii,int > M;

int BFS(int x,int y)
{
    int cal=0;
    pii p(x,y);
    M[p]=1;
    queue < pair < int,int > > q;
    q.push(p);
    while(q.size())
    {
        cal++;
        pii pp;
        pp=q.front();
        int a,b;
        a = pp.first; b = pp.second;
        pii s1(a-1,b),s2(a+1,b),s3(a,b-1),s4(a,b+1);
        if(M.find(s1)==M.end())
        {
            if(s1.first>= 0 && s1.second>=0 && s1.first<n && s1.second<m)
                q.push(s1); M[s1]=1;
        }
        if(M.find(s2)==M.end())
        {
            if(s2.first>= 0 && s2.second>=0 && s2.first<n && s2.second<m)
                q.push(s2); M[s2]=1;
        }
        if(M.find(s3)==M.end())
        {
            if(s3.first>= 0 && s3.second>=0 && s3.first<n && s3.second<m)
            q.push(s3); M[s3]=1;
        }
        if(M.find(s4)==M.end())
        {
            if(s4.first>= 0 && s4.second>=0 && s4.first<n && s4.second<m)
            q.push(s4); M[s4]=1;
        }
        q.pop();
    }
    return cal;
}
int main()
{

    int tc,cas=1;
    cin>>tc;
    int sx,sy;
    while(tc--)
    {
        printf("Case %d: ",cas++);
        cin>>m>>n;//6 9

        REP(i,n)
        {
            cin>>s[i];
                REP(j,m)
                {
                    if(s[i][j]=='@')
                    {
                        sx=i;
                        sy=j;
                    }
                    if(s[i][j]=='#')
                    {
                        pii p; //product3 = make_pair ("shoes",20.0);
                        p = make_pair(i,j);
                        M[p]=1;
                    }
                }
        }
        cout<<BFS(sx,sy)<<"\n";
        M.clear();
    }
    return 0;
}
