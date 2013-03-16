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

#define ll long long

#define pf printf
#define sf scanf

template<class T> inline T sqr(T x){return x*x;}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}

double SafeAcos (double x)
{
    if (x < -1.0) x = -1.0 ;
    else if (x > 1.0) x = 1.0 ;
    //cout<<"\nfunc : "<<x<<" ans : "<<acos(x)<<endl;
    return acos (x) ;
}

int main()
{
    //READ("in.txt");
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        pf("Case %d: ",cas++);
        ll r,c;
        int ox,oy,ax,ay,bx,by;
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        r = distsq(ox,oy,ax,ay);//pf("%I64d\n",2*r);
        c = distsq(bx,by,ax,ay);//pf("%I64d\n",c);
        //pf("%I64d\n",2*r - c);
        double ratio = ((double)(2*r-c)/(double)(2*r));
        /*
        pf("%2.20lf\nans : ",ratio);
        pf("%2.20lf\n",SafeAcos(ratio));
        */
        pf("%.3lf\n",SafeAcos(ratio)*_dist(ox,oy,ax,ay));
    }
    return 0;
}
