vi d;
void bfs(vvi& AdjList, int s){
    queue<int> q; q.push(s); int j;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto j: AdjList[u]) if(d[j]==MOD) d[j]=d[u]+1, q.push(j),cout<<j<<endl;
    }
}