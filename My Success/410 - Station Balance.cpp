/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 410 - Station Balance
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

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int c,s,spc[12],total,cas=1;
    double imb,avg;
    while(SD2(c,s)==2){
        pf("Set #%d\n",cas++);
        total = 0;
        rep(i,s) SDi(spc[i]),total+=spc[i];
        imb=0,avg = (double)total / c;
        if(s<2*c)
            for(int i=s;i<2*c;i++) spc[i]=0;
        sort(spc,spc+2*c);
        int i=0, j = 2*c - 1;
        int inc = 0;
        while(i<j){
            cout<<" "<<inc++<<":";
            if(spc[i]) pf(" %d",spc[i]);
            if(spc[j]) pf(" %d\n",spc[j]);
            else pf("\n");
            imb += fabs(avg - (spc[i++]+spc[j--]) );
        } pf("IMBALANCE = %.5lf\n\n",imb);
    }
    return EXIT_SUCCESS;
}
