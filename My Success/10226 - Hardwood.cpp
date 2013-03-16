/*
Shiakh Shiam Rahman 
UVa : 10226 - Hardwood
*/
#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <string>
#include <set>
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);

map<string,int> m;
set<string> s;
set< string > :: iterator it;
int total=0;

void print()
{
    double ans;
    for(it=s.begin();it!=s.end();it++)
    {
        ans=(double)(m[*it]*100.00)/total;
        cout<<*it;
        printf(" %.4lf\n",ans);
    }
    m.clear();
    s.clear();
}
int main()
{
    READ("in.txt");
    char  ch[200];
    int a;
    scanf("%d",&a);
    getchar();
    getchar();
    while(a--)
    {

            while(gets(ch)&&ch[0])
            {
                string tree(ch);
                m[tree]++;
                s.insert(tree);
                total++;

            }

            print();
               if(a)
            cout<<endl;
            total=0;
    }

return 0;
}
