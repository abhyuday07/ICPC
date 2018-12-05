void sieve(int N){
    int np=0,prime[N],isprime[N];
    memset(isprime,1,sizeof(isprime));
    for(int i=2; i<N; i++){
        if(isprime[i]){
            prime[++np]=i;
            for(int j=2*i; j<N; j+=i){
                isprime[j] = false;
            }
        }
    }
//    rep1(i,np-1) cout<<prime[i]<<endl;
}