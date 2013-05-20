/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 725 - Division
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

char ch[12];
int chk[12];
pii pr;
vector<pii> v[80];

bool unique(){
    rep(j,strlen(ch)){
        chk[ ch[j] - '0' ]++;
    }
    rep(i,12){
        if(chk[i]>1) return false;
    }
    return true;
}

void free(){
    rep(j,strlen(ch)){
        chk[ ch[j] - '0' ]--;
    }
}

int main()
{
    //WRITE("out.txt");
    int t;
    FOR(i,1234,98765) {
        memset(chk,0,sizeof(chk));
        sprintf(ch,"%d",i);
        if(strlen(ch) == 4) chk[0]++;
        if(unique()){
            FOR(k,2,79){
                if(k*i<=98765) {
                    sprintf(ch,"%d",k*i);
                    if(strlen(ch)<5) continue;
                    if(unique()){
                        v[k].pb(pmp(i*k,i));
                    }
                    free();
                }
            }
        }
    }
//    FOR(i,2,79)
//        rep(j,v[i].size())
//            printf("%05d / %05d = %d\n",v[i][j].first,v[i][j].second,i);
    int first = 0;
    while(SDi(t)&&t) {
        if(first) puts(""); first = 1;
        if(v[t].size())
            rep(i,v[t].size())
                printf("%05d / %05d = %d\n",v[t][i].first,v[t][i].second,t);
        else printf("There are no solutions for %d.\n",t);
    }
    return 0;
}
