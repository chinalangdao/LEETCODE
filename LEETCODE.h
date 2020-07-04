int longestValidParentheses(char * s){
    int n = strlen(s);
    if(n == 0) return 0;
    int dp[n];
    memset(dp, 0, sizeof(int) * n);
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == ')' && i - 1 - dp[i-1] >= 0 && s[i - 1 - dp[i-1]] == '(')
            dp[i] = dp[i-1] + (i - 2 - dp[i-1] > 0 ? dp[i-2-dp[i-1]] : 0) + 2;
        ans = fmax(ans, dp[i]);
    }
    return ans;
}
