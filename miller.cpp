bool ispmiller(ll p){
    if (p<2) return false;
    if (p==2) return true;
    if (p%2==0) return false;
    ll s=p-1; s>>=__builtin_ctzll(s);
    rep(i,30){
        ll val=pwr(myrand(p-1)+1,s,p);
        ll temp=s;
        while(temp!=p-1&&(2<=val)&&(val<=p-2)){
            val=mul(val,val,p);
            temp<<=1;
        }
        if(val!=p-1 && temp%2==0) return false;
    }
    return true;
}