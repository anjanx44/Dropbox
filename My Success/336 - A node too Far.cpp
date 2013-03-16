/*
Shiakh Shiam Rahman 
UVa : 336 - A node too Far
*/
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;
#define MAX 100000 //maximum node

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
# define long long ll

vector<int>G[MAX];
int count=0;
set <int> s;

void bfs(int sor,int n)
{
    vector<int>V1,V2;
    V1.push_back(sor);
    int taken[MAX]={0};
    taken[sor]=1;
    for(int loop=1;loop<=n;loop++)
    {
        for(unsigned i=0;i<V1.size();i++)
        {
            int u=V1[i];
            for(unsigned j=0;j<G[u].size();j++)
            {
                unsigned v=G[u][j];
                if(!taken[v])
                {
                    count++;
                    taken[v]=1;
                    V2.push_back(v);
                }
            }
        }
        V1.clear();
        V1=V2;
        V2.clear();
    }
}
void Clear()
{
    int i=100;
    while(i--)
        G[i].clear();
}
int main()
{
    READ("in.txt");

    int N,i,sor,len,Case=1;
    map <int,int> in,out;
    set< int > :: iterator it;

    //vector<int>cost[MAX]; //parallel vector to store costs;
    while(scanf("%d",&N) && N)
    {
        for(i=1;i<=N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            s.insert(x);
            s.insert(y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        while(scanf("%d%d",&sor,&len))
        {
            if(sor==0 && len==0)break;
            bfs(sor,len);
           // printf("%u  ",s.size());
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",Case++,s.size()-count-1,sor,len);
            count=0;
        }
        s.clear();
        in.clear();
        out.clear();
        Clear();
    }
    return 0;
}

