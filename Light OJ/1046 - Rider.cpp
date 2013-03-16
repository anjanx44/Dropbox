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
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define LD double
#define PI acos(-1)
#define mod 10000007
#define pii pair<int,int>
int x,y;
string s[11];
bool tes;
bool flag;
int bfs(pii sor,int node)
{
    queue< pii > q;
    map<pii,bool> m;
    map < pii,int > distan;
    q.push(sor);m[sor] = true;
    flag = false;
    pii pr;
    int cost = 0,nod =0 ;
    while(!q.empty())
    {
        pr = q.front();
        q.pop();
        int X,Y;
        X = pr.first;
        Y = pr.second;
        pii nxt;
        int ax[] = {2,2,-2,-2,1,-1,1,-1};
        int ay[] = {1,-1,1,-1,2,2,-2,-2};
        REP(i,8)
        {
            int a=X+ax[i],b=Y+ay[i];
            nxt = make_pair(a,b);
            if(!m[nxt]&&(a>=0 && b>=0 && a<x && b<y))
            {
                m[nxt] = true;
                q.push(nxt);
                distan[nxt]=distan[pr]+1;
                if(s[a][b]!='.')
                {
                    char ch = s[a][b];
                    int b = ch - 48;
                    int wi = distan [nxt]/b;
                    if(distan[nxt]%b!=0) wi++;
                    cost+=(int)wi;
                    nod++;
                }
            }
        }

    }
    if(node==nod) flag = true;
    m.clear();
    distan.clear();
    return cost;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int cas,cass=1,node;
    scanf("%d",&cas);
    while(cas--)
    {
        getchar();
        node=0;
        tes = true;
        printf("Case %d: ",cass++);
        scanf("%d %d",&x,&y);
        REP(i,x)
        {
            cin>>s[i];
            REP(j,y)
            {
                if(s[i][j]!='.')
                {
                    node++;
                }
            }
        }
        int min =1000000 ;
        int val;
        REP(i,x)
            REP(j,y)
            {
                pii par;
                par = make_pair(i,j);
                if(s[i][j]!='.')
                    val = bfs(par,node-1);
                else val = bfs(par,node);
                if(flag)
                {
                    if(min>val) min = val ;
                }

            }
            if(min==1000000) printf("-1\n");
            else printf("%d\n",min);
    }
	return 0;
}
