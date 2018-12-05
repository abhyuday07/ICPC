inline ll mul(ll a, ll b, ll m){
    ll q = ( (ld)a * (ld)b )/ (ld) m;
    ll r = a*b - q*m;
    return (r<0 ? r+m : r);
}