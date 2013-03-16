#include<cstdio>
#include<vector>
#include<algorithm>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define sf scanf
#define pf printf
#define ps while(1)
#define pb push_back
#define inf 0xffffff
using namespace std;
#include<deque>
int by[210];
vector<int> eg[210],wt[210];
int n,m,d1[210],d2[210];
int main(){
    int T;sf("%d",&T);re(t,1,T){
        pf("Case %d:\n",t);
        fill(d1,d1+210,inf);
        fill(d2,d2+210,inf);
        fill(eg,eg+210,vector<int>());
        fill(wt,wt+210,vector<int>());
        sf("%d",&n);
        re(i,1,n)sf("%d",&by[i]);
        sf("%d",&m);
        re(i,1,m){
            int u,v;
            sf("%d%d",&u,&v);
            eg[u].pb(v);wt[u].pb((by[v]-by[u])*(by[v]-by[u])*(by[v]-by[u]));
        }
        d1[1]=d2[1]=0;
        re(i,1,n-1){
            re(u,1,n){
                re(j,0,int(eg[u].size())-1){
                    int v=eg[u][j],w=wt[u][j];
                    if(d1[u]!=inf&&d1[u]+w<d1[v])
                        d1[v]=d2[v]=d1[u]+w;
                }
            }
        }
        re(i,1,n-1){
            re(u,1,n){
                re(j,0,int(eg[u].size())-1){
                    int v=eg[u][j],w=wt[u][j];
                    if(d2[u]!=inf&&d2[u]+w<d2[v])
                        d2[v]=d2[u]+w;
                }
            }
        }
        int q,dd;
        sf("%d",&q);
        re(i,1,q){
            sf("%d",&dd);
            if(d1[dd]!=d2[dd]||d1[dd]==inf||d1[dd]<3)
                pf("?\n");
            else
                pf("%d\n",d1[dd]);
        }
    }
    return 0;
}
