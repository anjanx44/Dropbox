/*
Shiakh Shiam Rahman 
UVa : 671 - Parenthesis Balence
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

int main()
{

    READ("in.txt");

    int tc;
    char ch[200];
    cin>>tc;getchar();
    while(tc--)
    {
        stack < char > next;
        gets(ch);
        string s(ch);
        bool b = true;
        if(s.length()==0)
        {
            printf("Yes\n");
            continue;
        }
        REP(i,s.length())
        {
            if(s[i]==40 ||s[i]==91)
            {
                if( s[i]==40 ) next.push(')');
                else next.push(']');
            }
            else
            {
                if(next.empty())
                 {
                    b = false;
                     break;
                 }
                else if(next.top()!=s[i])
                {
                     b = false;
                     break;
                }
                next.pop();
            }
        }
        if(next.empty()&&b)
            printf("Yes\n");
        else
            printf("No\n");

        while(!next.empty()) next.pop();
    }
    return 0;
}
