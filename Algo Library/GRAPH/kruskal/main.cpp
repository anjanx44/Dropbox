#include <iostream>
#include "cstdio"
#include "algorithm"
#include "cstring"
#include "vector"
using namespace std;


#define G struct krus
G
{
    int u;
    int v;
    int w;
}g[100];

int par[100];
vector < int > v;

bool comp(G a,G b){
    return a.w<b.w;
}
int find(int p)
{
    if(par[p]==p)
        return p;
    else
        return par[p] = find(par[p]);
}
void uni(int a,int b)
{
    if(par[a]==a)
    {
        par[a] = find(b);
        return;
    }
    else if(par[b]==b)
    {
        par[b] = par[a];
        return;
    }
    else
    {
        int m = find(a);
        int n = find(b);
        par[m] = n;
    }
}
void krus(int edge,int ver)
{
    int sum = 0;
    for(int i=0;i<edge;i++)
    {
        if(find(g[i].u)!=find(g[i].v))
        {
            v.push_back(g[i].w);
            sum+=g[i].w;
            uni(g[i].u,g[i].v);
            printf("count : %d\n",i);
            for(int j=1;j<=ver;j++) printf("%d ",j); puts("");
            for(int j=1;j<=ver;j++) printf("%d ",par[j]); puts("");
        }
    }
    puts("The edges are : ");
    for(unsigned i=0;i<v.size();i++) printf("%d ",v[i]); puts("");
    printf("\n\nMST : %d\n",sum);
}

int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<100;i++)
        par[i] = i;
    int ed,ve;
    printf("Enter the number of vertex and edge:");
    scanf("%d %d",&ve,&ed);
    for(int i=0;i<ed;i++)
    {
        printf("Enter v1:");
        scanf("%d",&g[i].u);
        printf("Enter v2:");
        scanf("%d",&g[i].v);
        printf("Enter cost:");
        scanf("%d",&g[i].w);
    }
    puts("");
    sort(g,g+ed,comp);
    for(int i=0;i<ed;i++)
        cout<<g[i].u<<","<<g[i].v<<">>"<<g[i].w<<"\n";
    krus(ed,ve);
    return 0;
}
/*
vector < int > pset(1000);
void initSet(int _size){ pset.resize(_size); FOR(i,0,_size-1) pset[i]=i;}
int findSet(int i){return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));}
void unionSet(int i,int j){ pset[findSet(i)]=findSet(j);}
bool isSameSet(int i,int j){ return findSet(i)==findSet(j);}

#define G struct krus
#define MAX 100000
G{
    int u,v,w;
}g[MAX];

bool comp(G a,G b){
    return a.w<b.w;
}

void krus(int edge,int ver)
{
    int sum = 0;
    initSet(ver+10);
    for(int i=0;i<edge;i++)
        if(!isSameSet(g[i].u,g[i].v))
        {
            sum+=g[i].w;
            unionSet(g[i].u,g[i].v);
        }
}
*/
/*
input:
7 10
1 2 2
1 4 8
1 5 14
2 5 25
2 3 19
3 6 5
3 7 9
4 5 21
5 6 13
6 7 1
*/
