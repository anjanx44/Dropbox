
#define MX 10000

#define DFS_BLACK 2
#define DFS_WHITE -1
#define DFS_GRAY 1

int dfs_visit[MX];
// memdp(dfs_visit);
void DFS(int u) {
    dfs_counter++;
    dfs_visit[u] = DFS_GRAY
    rep(i,edge[u].size()) {
        int v = edge[u][i];
        if(dfs_visit[v] == DFS_WHITE){
            DFS(v);
        }
    }
    dfs_visit[u] = DFS_BLACK;
}
