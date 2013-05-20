/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 11742 - Social Constraints
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

using namespace std;

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
#define memsp(x) mem(x,MEMSET_INF)
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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

vector< pair<pii,int> > v;
int person, cons, seat,used[10],isConstrain[10],taken[10],solu;

bool isGood(int u){
    rep(i,cons){
        int prevper;
        if(v[i].ft.ft == u)
            prevper = v[i].ft.sd;
        else if(v[i].ft.sd == u)
            prevper = v[i].ft.ft;
        else continue;
        if(!used[prevper]) continue;
        int d = 0;
        do{
            d++;
        }while(taken[seat - d]!=prevper);
        if( (v[i].sd > 0 and d > v[i].sd) or (v[i].sd < 0 and d < -v[i].sd) )
            return false;
    }
    return true;
}

void bktk(){
    if(seat == person)
        solu++;
    rep(i,person){
        if(!used[i] and (isGood(i) or !isConstrain[i])){
            used[i] = 1;
            taken[seat++] = i;
            bktk();
            seat--;
            used[i] = 0;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    while(SD2(person,cons) and (person or cons)){
        memca(used), memca(isConstrain),memca(taken);
        rep(i,cons){
            int a,b,c;
            SD3(a,b,c);
            isConstrain[a] = isConstrain[b] = 1;
            v.pb( pmp(pmp(a,b),c) );
        } solu = seat = 0;
        bktk();
        pf("%d\n",solu);
        v.clear();
    }
    return 0;
}
