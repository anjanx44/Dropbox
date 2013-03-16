/*
Shiakh Shiam Rahman 
UVa : 429 - Word Transmission
*/
include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000

using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
# define ull unsigned long long
# define ll long long
# define u unsigned

int node;
map< string , vector < string > > G;

int bfs(string sor,string dis)
{
    u j,k;
    int level=0;
    vector < string > V1,V2;
    V1.clear();V2.clear();
    V1.push_back(sor);
    map <string,bool> taken;
    taken.clear();
    taken[sor]=true;
    while(1)
    {
        level++;
        for(k=0;k<V1.size();k++)
        {
            for(j=0;j<G[V1[k]].size();j++)
                if(!dis.compare(G[V1[k]][j]))
                    return level;
                else if(!taken[G[V1[k]][j]])
                {
                    V2.push_back(G[V1[k]][j]);
                    taken[G[V1[k]][j]]=true;
                }
        }
        V1.clear();
        V1=V2;
        V2.clear();
    }
    return 0;
}
bool bitcheak(string s,string st)
{
    int bit=0;
    for(u i=0;i<s.size();i++)
        if(s[i]!=st[i])
            bit++;

    if(bit==1)
        return true;

    return false;
}

int main()
{
    READ("in.txt");
    map <int, vector<string> > in;
    char ch[200],c[200],sor[200],dis[200];
    int a;
    bool index[12];
    bool cas=false;
    cin>>a;
    getchar();getchar();
    while(a--)
    {
        if(cas)printf("\n");cas=true;
        memset(index,false,sizeof(index));
        while(gets(ch)&& strcmp(ch,"*"))
        {
            in[strlen(ch)].push_back(ch);
            index[strlen(ch)]=true;
        }
        for(int i=1;i<=10;i++)
        {
            if(index[i])
            {
                vector < string > s;
                s=in[i];
                for(u j=0;j<s.size();j++)
                {
                    for(u k=j+1;k<s.size();k++)
                        if(bitcheak(s[j],s[k]))
                        {
                            G[s[j]].push_back(s[k]);
                            G[s[k]].push_back(s[j]);
                        }
                }
            }
        }
        while(gets(c)&&strlen(c))
        {
            sscanf(c,"%s %s",sor,dis);
            printf("%s %s %d\n",sor,dis,bfs(sor,dis));
        }
        G.clear();
        in.clear();
    }
return 0;
}
