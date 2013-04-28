/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
UVa - 12619 Just Make a wish
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

#define mod 1000000007
#define  MX 1000000

int N = MX,prime[200010],DivisorCounter[MX];
i64 ans=1;
bool  status[MX+100];

struct Euclid {
	i64 x, y, d;
	Euclid() {}
	Euclid( i64 xx, i64 yy, i64 dd ) { x = xx, y = yy, d = dd; }
};
i64 gcd( i64 a, i64 b ) { return !b ? a : gcd ( b, a % b ); }
Euclid egcd( i64 a, i64 b ) { // Input a, b; Output x, y, d; ax + by = d, d = gcd(a,b)
	if( !b ) return Euclid ( 1, 0, a );
	Euclid r = egcd ( b, a % b );
	return Euclid( r.y, r.x - a / b * r.y, r.d );
}
i64 modularInverse( i64 a, i64 n ) { // given a and n, returns x, ax mod n = 1
	Euclid t = egcd( a, n );
	if( t.d > 1 ) return 0;
	i64 r = t.x % n;
	return r < 0 ? r + n : r;
}

void prim()
{
  int i, j, sqrtN;

  sqrtN = int( sqrt( N ) );
  for( i = 2; i <= sqrtN; i += 1 )
    if( status[i] == 0 )
       for( j = 2*i; j <= N; j += i )
          status[j] = 1;

  prime[0]=2;
  for( i = 3,j=1; i <= N; i += 2 )
    if( status[i] == 0 )
        prime[j++]=i;
    //pf("%d\n",prime[j-1]);
}

void divisor(int n){
    bool neg = false;
    if(n<0) {
        n*=-1;
        neg = true;
    }
    int N = (int)sqrt(n);
    for(int i=0;prime[i]<=N;i++){
        int count=1;
        if(n%prime[i]==0){
            i64 inv = modularInverse(DivisorCounter[ prime[i] ]+1,mod);
            ans = ( ans%mod * inv%mod )%mod;
        }
        while(n%prime[i]==0){
            n/=prime[i];
            count++;
            if(neg) DivisorCounter[ prime[i] ]--;
            else DivisorCounter[ prime[i] ]++;
        }
        if(count>1){
            N = (int)sqrt(n);
            ans=(ans%mod * (DivisorCounter[ prime[i] ]+ 1)%mod)%mod;
        }
    }

    if(n!=1){
        i64 inv = modularInverse(DivisorCounter[ n ]+1,mod);
            ans = ( ans%mod * inv%mod )%mod;
        if(neg) DivisorCounter[ n ]--;
        else DivisorCounter[ n ]++;
        ans=(ans%mod * (DivisorCounter[ n ]+ 1)%mod)%mod;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,cas=1;
    cin>>tc;
    prim();
    while(tc--){
        pf("Case %d: ",cas++);
        memca(DivisorCounter);
        int d;
        SDi(d);
        int total = 0;
        rep(i,d){
            int u;
            SDi(u);
            divisor(u);
            total = ( total%mod + ans%mod )%mod;
        }
        pf("%d\n",total);
        ans = 1;
    }
    return 0;
}
