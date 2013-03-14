#define M 55
int visited[M], cycle = 0;
vector<int> edge[M];

void visit( int p ) {
    if( visited[p] == 2 || cycle ) return;
    // we won't process anything if we already have found a cycle
    if( visited[p] == 1 ) {
        cycle = 1; // found cycle
        return;
    }   
    visited[p] = 1;
    for(int i=0; i<edge[p].size(); i++) visit( edge[p][i] );
    visited[p] = 2;
}

#define MAX 10010
#define white 0
#define gray 1
#define black 2

msi w;
si s;
vi edge[MAX];
int indegree[MAX];
int dfs_num[MAX];

bool dfs(int sor)
{
    dfs_num[sor] = gray;
    rep(i,edge[sor].size())
    {
        int v = edge[sor][i];
        if( dfs_num[v] == white)
            dfs(edge[sor][i]);
        else if(dfs_num[v] == gray)
            return false;
    }
    dfs_num[sor] = black;
    return true;
}
