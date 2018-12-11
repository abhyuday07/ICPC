vi dfs_num;
void dfs(vvi& AdjList, int u){
    dfs_num[u] = 1; int j;
    for(auto j: AdjList[u]) if(!dfs_num[j]) dfs(AdjList,j);
}