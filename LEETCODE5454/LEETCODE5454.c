int numSubmat(int** mat, int matSize, int* matColSize){
    int m = matSize;
    int n = *matColSize;
    int dp[m][n];
    for(int i = 0; i < m; i++)
        memset(dp[i], 0, sizeof(int) * n);
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 1)
                dp[i][j] = (j > 0 ? dp[i][j-1] : 0) + 1;
            int min = INT_MAX;
            for(int k = i; k >= 0; k--){
                min = fmin(min, dp[k][j]);
                ans += min;
            }
        }
    }
    return ans;
}
