#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<fstream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64
#define MAX 10005

int col[MAX],low[MAX],d[MAX],prev[MAX],T,root;
bool art[MAX],odd[MAX];
vector<int> adj[MAX];

int find_odd(int x,int c,int par){
	if(art[x] || col[x] == 100) return 0;
	if(col[x]!=-1){
		return col[x]!=c;
	}
	col[x] = c;
	int i , sz = adj[x].size(),y;
	for(i = 0;i<sz;i++){
		y = adj[x][i];
		if(y == par) continue;
		if(find_odd(y,1 - c,x))
			return 1;
	}
	return 0;
}

void mark_odd(int x,int oo,int par){
	if(art[x]) return;
	if(col[x] ==100) return ;
	col[x] = 100;
	odd[x] |= oo;
	art[x] = 1;
	int i , sz = adj[x].size(),y;
	for(i = 0;i<sz;i++){
		y = adj[x][i];
		if(y == par) continue;
		mark_odd(y,oo,x);
	}
}
void dfs(int x){
	d[x] = T++;
	low[x] = d[x];
	int i , sz = adj[x].size(),y;
	for(i = 0;i<sz;i++){
		y = adj[x][i];
		if(prev[y]==-1){
			prev[y] = x;
			dfs(y);
			if(d[x]<low[y]){
				int f = 0;
				if(find_odd(y,1,x)){
					f = 1;
				}
				mark_odd(y,f,x);
			}
			low[x] = min(low[x],low[y]);
		}
		else if(prev[x]!=-2 && prev[x]!=y) low[x] = min(low[x],d[y]);
	}
	T++;
}
int main(){
	int m,i,n,cnt,cs = 1,x,y,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(i = 0;i<=n;i++)
			col[i]= -1,adj[i].clear(),prev[i] = -1,odd[i] = 0,art[i] = 0;
		for(i = 0;i<m;i++){
			scanf("%d %d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		cnt = 0;
		for(i = 0,T = 0;i<n;i++){
			if(prev[i]==-1){
				prev[i] = -2;
				root = i;
				dfs(i);
			}
			int f = 0;
			if(find_odd(i,0,-1))
				f = 1;
			mark_odd(i,f,-1);
			cnt+=odd[i];
		}
		printf("Case %d: %d\n",cs++,cnt);
	}
	return 0;
}
