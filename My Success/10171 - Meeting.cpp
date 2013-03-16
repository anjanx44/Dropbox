/*
Shiakh Shiam Rahman 
UVa : 10171 - Meeting
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

/*** typedef ***/

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_HALF_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define n 30
int m[30][30],s[30][30];

//bool meg[30][30],sir[30][30];

int main() {
    READ("in.txt");
    int N;
    while(SDi(N)&&N) {
        getchar();
        memsp(m);
        memsp(s);
        /*mem(meg,false);
        mem(sir,false);*/
        rep(i,n) m[i][i] = s[i][i] = 0;
        rep(i,N) {
            char ch[100];
            gets(ch);
            char de,age,v,u;
            int cost;
            sscanf(ch,"%c %c %c %c %d",&age,&de,&u,&v,&cost);
            int x,y;
            x = u - 'A';
            y = v - 'A';
            if(age == 'M') {
                if(de=='U') {
                    m[x][y] = min(m[x][y],cost);
                    //meg[x][y] = true;
                } else {
                    m[x][y] = m[y][x] = min(m[x][y],cost);
                    //meg[x][y] = meg[y][x] = true;
                }
            } else {
                if(de=='U') {
                    s[x][y] = min(s[x][y],cost);
                    //sir[x][y] = true;
                } else {
                    s[x][y] = s[y][x] = min(s[x][y],cost);
                    //sir[x][y] = sir[y][x] = true;
                }
            }
        }
        /*
        rep(k,n) rep(i,n) rep(j,n)
        {
            meg[i][j] = meg[i][j] | (meg[i][k] & meg[k][j]);
            sir[i][j] = sir[i][j] | (sir[i][k] & sir[k][j]);
        }
        */
        rep(k,n)
        rep(i,n)
        rep(j,n) {
            m[i][j] = min( m[i][j], m[i][k] + m[k][j] );
            s[i][j] = min( s[i][j], s[i][k] + s[k][j] );
            //if(i==23 || j==23) cout<<"dis : "<<m[i][j]<<"\n";
        }

        int sor,dir;
        char sorc,dire;
        cin>>sorc>>dire;
        sor = sorc - 'A';
        dir = dire - 'A';
        int mn = 150000,dis;
        vector< char > ans;
        for(int i=0; i<26; i++) {
            //cout<<i<<" sir : "<<s[sor][i]<<" meg : "<<m[dir][i]<<"\n";
            dis = m[dir][i]+s[sor][i];
            if(mn > dis) {
                mn = dis;
                ans.clear();
                ans.pb(i + 'A');
                continue;
            }
            if(mn == dis) ans.pb(i + 'A');
        }
        if(mn == 150000) puts("You will never meet.");
        else {
            pf("%d",mn);
            for(int i=0; i<(int)ans.size(); i++) {
                pf(" ");
                putchar(ans[i]);
            }
            puts("");
        }
        ans.clear();
    }
    return 0;
}
