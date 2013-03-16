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

#define pf printf
#define sf scanf
#define SDi(x) sf("%d",&x)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)

#define  MX 1000
int N = MX,prime[1000];
bool  status[MX+10];
int f[1010],a[MX+10];
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
}

int div(int num)
{
    int ret = 1,n = num;
    int sqrtN = int( sqrt(n) );
    for( int i = 0; prime[i] <= sqrtN; i++ )
    {
        if( n % prime[i] == 0 )
        {
            int cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            ret*=(cnt+1);
        }
    }
    if(n>1)
        ret *= 2;
    return ret;
}

bool com(int a, int b)
{
    if(f[a]!=f[b]) return f[a]<f[b];
    return a>b;
}

int main()
{

    prim();
    repl(i,1000){
        a[i] = i;
        f[i] = div(i);
    }
    sort(a+1,a+1001,com);
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        pf("Case %d: ",cas++);
        int num;
        cin>>num;
        cout<<a[num]<<endl;
    }
    return 0;
}
