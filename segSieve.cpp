void Sieve(int n, vector<int>& prime){
    bool mark[n+1];
    memset(mark,true,sizeof(mark));
    mark[1] = mark[0] = false;
    for(int p=2; p*p < n; p++){
        if(mark[p]){
            // cout<<p<<endl;
            for(int i = p*p; i < n; i+=p){
                mark[i] = false;
            }
        }
    }
    for(int i = 1; i<n ; i++){
        if(mark[i]) prime.push_back(i);
    }
}
void segSieve(int n){
    vector<int> prime;
    int limit = floor(sqrt(n)) + 1;
    Sieve(limit,prime);
    int low = limit;
    int high = limit*2;
    while(low<n){
        if(high > n) high = n;
        bool mark[limit+1];
        memset(mark,true,sizeof(mark));
        for(auto p : prime){
            int x = ceil(low/p)*p;
            for(int i = x; i<high; i+=p) mark[i - low] = false;
        }
        for(int i=low; i<high; i++) if(mark[i-low]) cout<<","<<i;
        high += limit;
        low += limit;
        
    }
}
