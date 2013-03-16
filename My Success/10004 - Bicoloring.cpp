/*
Shiakh Shiam Rahman 
UVa : 10004 - Bicoloring
*/
#include <iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<set>
# define MAX 10000
using namespace std;
int flag=0;
vector <int >G[MAX];
set <int> s;
set< int > :: iterator it;

void cheak(int color[MAX]);

void bfs(int sor,int n)
{
    vector<int>V1,V2;
    V1.push_back(sor);
    int taken[MAX]={0};
    int color[MAX]={0};
    taken[sor]=1;
    color[sor]=1;
    int c=2;
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

                    taken[v]=1;
                    color[v]=c;
                    V2.push_back(v);
                }
            }
        }
        V1.clear();
        V1=V2;
        V2.clear();
        if(c==1)c=2;
        else c=1;
    }
    cheak(color);
}
void cheak(int color[MAX])
{
    for(it = s.begin(); it != s.end(); it++)
    {
        for(unsigned i=0;i<G[*it].size();i++)
        {
            if(color[*it]==color[G[*it][i]])
            {
                printf("NOT BICOLORABLE.\n");
                flag=1;
                return;

            }
        }
    }
}
void Clear()
{
    int i=202;
    while(i--)
        G[i].clear();
}

int main()
{
    freopen("in.txt","r",stdin);

    unsigned e,n,i;
    while(scanf("%u %u",&n,&e) && n)
    {
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
        bfs(*it,n);

        if(flag==0)
            printf("BICOLORABLE.\n");
        flag=0;
        Clear();
    }
    return 0;
}

