/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 11935 - Through the Desert
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

double fuel_per_kilo,leakage,val,total;

//bool possiable(double fuel){
//
//}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    string state;
    int dis,fuel,pre_dis;
    while(cin>>dis>>state){
        if(state == "Goal"){
            total = total + (dis - pre_dis)*(fuel_per_kilo+leakage);
            val = max(total,val);
            pf("%.3lf\n",val);
            continue;
        } else if(state == "Fuel"){
            if(dis == 0) {
                total = val = leakage = 0;
            } else {
                total = total + (dis - pre_dis)*(fuel_per_kilo+leakage);
            }
            cin>>state>>fuel;
            if(!fuel) break;
            fuel_per_kilo = fuel/100.0;
        } else if(!state.compare("Leak")){
            total = total + (dis - pre_dis)*(fuel_per_kilo+leakage);
            leakage++;
        } else if(!state.compare("Mechanic")){
            total = total + (dis - pre_dis)*(fuel_per_kilo+leakage);
            leakage = 0;
        } else if (!state.compare("Gas")){
            cin>>state;
            total = total + (dis - pre_dis)*(fuel_per_kilo+leakage);
            val = max(total,val);
            total = 0;
        }
        pre_dis = dis;
    }
    return 0;
}
