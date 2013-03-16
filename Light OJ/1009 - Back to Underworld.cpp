#include <iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<string.h>
# define MAX 20010
using namespace std;
int flag=0;
vector <int >G[MAX];
set <int> s;
set< int > :: iterator it;
map<int , int > m;
int taken[MAX];
unsigned bfs(int sor,int n)
{
    queue<int> q;
    vector <int> lycan,wolves;
    q.push(sor);

    int color[MAX]={0};
    taken[sor]=1;
    color[sor]=1;
    lycan.push_back(sor);
    while(!q.empty())
    {
            int u=q.front();
            q.pop();
            if(color[u]==0&&!taken[u])
            {
                color[u] = 1;
                lycan.push_back(u);
            }
            for(unsigned j=0;j<G[u].size();j++)
            {
                unsigned v=G[u][j];
                if(!taken[v])
                {
                    taken[v]=1;
                    if(color[u]==1)
                    {
                        wolves.push_back(v);
                        color[v]=2;
                    }
                    else
                    {
                        lycan.push_back(v);
                        color[v]=1;
                    }
                    q.push(v);
                }
            }
        }
    return max(lycan.size(),wolves.size());
}

int main()
{
    unsigned e,i,j=1,cas;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(taken,0,sizeof(taken));
        printf("Case %d: ",j++);
        scanf("%d",&e);
        for(i=1;i<=e;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            s.insert(x);
            s.insert(y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        it=s.begin();
        int sum = 0;
        for(it = s.begin(); it != s.end(); it++)
        {
            if(!taken[*it])
            sum+=bfs(*it,(int)s.size());
        }
        printf("%d\n",sum);
        int i=20010;
        while(i--)
            G[i].clear();
        s.clear();
    }
    return 0;
}

