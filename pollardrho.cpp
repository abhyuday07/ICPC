ll pollardrho(ll n){
    if(n==1) return 1;
    if(n%2==0) return 2;
    ll c=myrand(n-1) + 1;
    ll x=myrand(n-2) + 2, y=x;
    ll d=1;
    while(d==1){
        x=mul(x,x,n)+c; if(x>=n) x-=n;
        y=mul(y,y,n)+c; if(y>=n) y-=n;
        y=mul(y,y,n)+c; if(y>=n) y-=n;
        d=__gcd(abs(x-y),n);
        if(d==n) return ispmiller(n)? n: pollardrho(n);
    }
    return d;
}