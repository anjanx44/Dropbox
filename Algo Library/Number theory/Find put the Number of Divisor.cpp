/*

Uva - 294  - Divisor

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

#define  MX 1000000
int N = MX,prime[200010];
bool  status[MX+100];

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

int divisor(int n){
    int ans=1;
    int N = (int)sqrt(n);
    rep(i,N+1){
        int count=1;
        while(n%prime[i]== 0){
            n/=prime[i];
            count++;
        }
        ans*=count;
    }
    if(n!=1) ans*=2;
    return ans;
}

int main(){
    READ("in.txt");
    int tc;
    cin>>tc;
    prim();
    while(tc--){
        int up,low;
        int P,D=0;
        SD2(low,up);
        FOR(i,low,up){
            int  p = divisor(i);
            if(p>D){
                P = i;
                D = p;
            }
        }
        pf("Between %d and %d, %d has a maximum of %d divisors.\n",low,up,P,D);
    }
}
