/*
Shiakh Shiam Rahman 
UVa : 10653 - Bombs no they are mines
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
#define U unsigned
#define pii pair<int,int>
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

queue < pii > Q;
pii sor,dis;
bool visited[1010][1010];
int distan[1010][1010];

int main()
{
    READ("in.txt");
    int mm,n,p,q;
    int R,C;
    while(scanf("%d %d",&R,&C)&&R&&C)
    {
        memset(visited,false,sizeof(visited));
        memset(distan,0,sizeof(distan));
        int row;
        scanf("%d",&row);
        int k=0;
        while(k<row)
        {
            int a,b,c;
            scanf("%d",&a);
            scanf("%d",&c);
            while(c--)
            {
                //pii w;
                scanf("%d",&b);
                //w = make_pair(a,b);
                visited[a][b] = true;
            }
            k++;
        }
        scanf("%d %d",&mm,&n);
        scanf("%d %d",&p,&q);
        sor = make_pair(mm,n);
        dis = make_pair(p,q);
        Q.push(sor);
        while(!Q.empty())
        {
            pii e = Q.front();
            if(e == dis)
            {
                printf("%d\n",distan[e.first][e.second]);
                break;
            }
            int ax[] = {1,-1,0,0};
            int ay[] = {0,0,1,-1};
            REP(i,4)
            {
                int x,y;
                x = e.first+ax[i];
                y = e.second+ay[i];
                pii ne = make_pair(x,y);
                if(!visited[x][y]&&(x>=0 && y>=0 && x<=R && y<=C))
                {

                    visited[x][y] = true;//m[ne] = true;
                    Q.push(ne);
                    distan[x][y] = distan[e.first][e.second] + 1;
                }
            }
            Q.pop();
        }
        while(!Q.empty()) Q.pop();
    }
    return 0;
}
