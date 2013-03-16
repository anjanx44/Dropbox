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

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)

#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vpii vector<pii>
#define all(x) x.begin(),x.end()
#define pb push_back
#define ppb pop_back

#define SDi(x) sf("%d",&x)
#define pf printf
#define sf scanf

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int main()
{
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        pf("Case %d: ",cas++);
        int n;
        cin>>n;
        vector< pair<int,string> > v;
        rep(i,n)
        {
            int a,b,c;
            string str;
            cin>>str>>a>>b>>c;
            pair<int,string> p(a*b*c,str);
            v.pb(p);
        }
        sort(all(v));
        if(v[0].ft<v[v.size()-1].ft)
            pf("%s took chocolate from %s\n",v[v.size()-1].sd.c_str(),v[0].sd.c_str());
        else puts("no thief");
    }
    return 0;
}
