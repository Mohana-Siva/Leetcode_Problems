int path(int i,int j,int m,int n,int **d){
    if(i>=m || j>=n) return 0;
    if(i==(m-1) && j==(n-1)) return 1;
    if(d[i][j]!=-1) return d[i][j];
    return d[i][j] = path(i+1,j,m,n,d) + path(i,j+1,m,n,d);
}

int uniquePaths(int m, int n) {
    int **d = (int **) calloc(m,sizeof(int *));
    for (int i = 0; i < m; i++) 
        d[i] = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
        d[i][j] = -1;
    
    return path(0,0,m,n,d);
}