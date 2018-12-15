//------------|MATRIX EXP|---------------------//
#define MAX_N 2
struct Matrix { int mat[MAX_N][MAX_N]; };

Matrix matMul(Matrix a, Matrix b){
    Matrix ans; int k;
    rep(i,MAX_N) 
        rep(j,MAX_N) 
            for(ans.mat[i][j]=k=0; k<MAX_N; k++)
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return ans;
}
Matrix matPow(Matrix base, int p){
    Matrix ans; int i,j;
    rep(i,MAX_N) rep(j,MAX_N) ans.mat[i][j] = (i==j);
    while(p){
        if (p&1) ans = matMul(ans,base);
        base = matMul(base,base);
        p >>= 1;
    }
    return ans;
}
//---------------------------------------------//