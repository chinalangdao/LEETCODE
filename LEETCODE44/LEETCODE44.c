bool isMatch(char * s, char * p){
    int m = strlen(s) + 1;
    int n = strlen(p) + 1;
    bool dp[m][n];
    for(int i = 0; i < m; i++)
        memset(dp[i], false, sizeof(bool) * n);
    dp[0][0] = true;
    for(int j = 1; j < n; j++){
        if(p[j-1] == '*') dp[0][j] = true;
        else break;
    }


    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(p[j-1] != '*')
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
            else
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
