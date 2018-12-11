int dfsNumCounter,rootChildren,dfsRoot;
void BandA(vvi& AdjList,int u, int dfs_num[], int dfs_low[], int dfs_parent[],bool art_vertex[]){
    dfs_low[u] = dfs_num[u] = dfsNumCounter++; int i;
    for(auto i: AdjList[u]){
        if(dfs_num[i]==0){
            dfs_parent[i]=u;
            if(u == dfsRoot) rootChildren++;
            BandA(AdjList,i,dfs_num,dfs_low,dfs_parent,art_vertex);
            if (dfs_low[i] >= dfs_num[u]) art_vertex[u] = true;
            if (dfs_low[i] > dfs_num[u]) printf(" Edge (%d, %d) is a bridge\n", u, i);
            dfs_low[u] = min(dfs_low[u], dfs_low[i]);
        }
        else if (i != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[i]);
    }
}
void BridgesandArticulation(vvi& AdjList,int V){
    int dfs_num[V],dfs_low[V],dfs_parent[V];
    bool art_vertex[V];
    int dfsNumCounter = 0;
    fill(dfs_num),fill(dfs_low),fill(dfs_parent),fill(art_vertex);
    rep(i,V) if (dfs_num[i] == 0){//BRIDGES
        dfsRoot = i; rootChildren = 0; BandA(AdjList,i,dfs_num,dfs_low,dfs_parent,art_vertex);
        art_vertex[dfsRoot] = (rootChildren > 1);}
    rep(i,V) if (art_vertex[i]){//ARTICULATIONS
        printf("Vertex %d\n",i);
    }
}