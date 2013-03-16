/*
Shiakh Shiam Rahman 
UVa : 10685 - Nature
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

vector < int > pset(1000);
void initSet(int _size){pset.resize(_size); FOR(i,0,_size-1) pset[i]=i;}
int findSet(int i){return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));}
void unionSet(int i,int j){ pset[findSet(i)]=findSet(j);}
bool isSameSet(int i,int j){ return findSet(i)==findSet(j);}

int main()
{
    READ("in.txt");
    map <string,int> m;
    int c,r;
    while(scanf("%d %d",&c,&r)&&(c||r))
    {
        REP(i,c)
        {
            string s;
            cin>>s;
            m[s]=i;
        }
        initSet(c+10);
        int count[c+10];
        REP(i,c+10) count[i] = 1;

        int max = 1 ;
        string a,b;
        REP(i,r)
        {
            cin>>a>>b;
            if(!isSameSet(m[a],m[b]))
            {
                count[findSet(m[b])]+=count[findSet(m[a])];
                if(max<count[findSet(m[b])])
                    max = count[findSet(m[b])];
                unionSet(m[a],m[b]);
            }
        }
        printf("%d\n",max);
        m.clear();
        pset.clear();
    }
    return 0;
}