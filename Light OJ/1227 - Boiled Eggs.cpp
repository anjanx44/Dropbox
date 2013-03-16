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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)

#define vi vector<int>
#define pb push_back
#define ppb pop_back

#define all(x) x.begin(),x.end()
#define SDi(x) sf("%d",&x)
#define pf printf
#define sf scanf

int main()
{

    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        pf("Case %d: ",cas++);
        int n,p,q;
        cin>>n>>p>>q;
        vi wt;
        rep(i,n){
            int eg;
            SDi(eg);
            wt.pb(eg);
        }
        sort(all(wt));
        int cnt = 0, sum = 0 ;
        for(int i=0;i<p && i<n;i++)
        {
            sum+=wt[i];
            if(sum>q) break;
            cnt++;
        }
        cout<<cnt<<endl;
        wt.clear();
    }
    return 0;
}
