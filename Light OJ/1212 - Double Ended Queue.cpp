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
#include <deque>
using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)


int main ()
{
    //READ("in.txt");
    deque<int> q;
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        printf("Case %d:\n",cas++);
        int sz,op,num;
        cin>>sz>>op;getchar();
        while(op--)
        {
            string str;
            cin>>str;
            if(str == "pushLeft" || str == "pushRight")
            {
                cin>>num;
                if((int)q.size()==sz && (str == "pushLeft" || str == "pushRight")){ puts("The queue is full"); continue;}
                else if(str == "pushLeft"){ q.push_front(num); cout<<"Pushed in left: "<<num<<endl;}
                else if(str == "pushRight"){ q.push_back(num); cout<<"Pushed in right: "<<num<<endl;}
            }

            if(q.empty()){ puts("The queue is empty"); continue; }
            else if(str == "popLeft"){ cout<<"Popped from left: "<<q.front()<<endl; q.pop_front();}
            else if(str == "popRight"){ cout<<"Popped from right: "<<q.back()<<endl; q.pop_back();}
        }
        while(!q.empty()) q.pop_back();
    }
    return 0;
}
