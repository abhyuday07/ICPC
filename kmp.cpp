int lps[N];
void KMPPreProcess(char P[], int m){
    int i = 0, j = -1; lps[0] = -1;
    while(i<m){
        while(j>=0 && P[i] != P[j]) j=lps[j];
        i++; j++;
        lps[i]=j;
    }
}
void KMPSearch(char T[], char P[], int n, int m){
    int i=0,j=0;
    while(i<n){
        while(j>=0 && T[i]!= P[j]) j=lps[j];
        i++; j++;
        if(j==m){
            printf("P is found at index %d in T\n",i - j);
            j=lps[j];
        }
    }
}