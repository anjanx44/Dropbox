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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int main()
{
    stack<string> fro,back;
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        string str,web;
        back.push("http://www.lightoj.com/");
        pf("Case %d:\n",cas++);
        while(1)
        {
            cin>>str;
            if(str=="VISIT")
            {
                cin>>web;
                pf("%s\n",web.c_str());
                back.push(web);
                while(!fro.empty()) fro.pop();
            }
            else if(str=="BACK")
            {
                if(back.top()=="http://www.lightoj.com/") puts("Ignored");
                else
                {
                    fro.push(back.top());
                    back.pop();
                    pf("%s\n",back.top().c_str());
                }
            }
            else if(str == "FORWARD")
            {
                if(fro.empty()) puts("Ignored");
                else
                {
                    back.push(fro.top());
                    fro.pop();
                    pf("%s\n",back.top().c_str());
                }
            }
            else if(str == "QUIT")
            {
                while(!fro.empty()) fro.pop();
                while(!back.empty()) back.pop();
                back.push("http://www.lightoj.com/");
                break;
            }
        }
    }
    return 0;
}
