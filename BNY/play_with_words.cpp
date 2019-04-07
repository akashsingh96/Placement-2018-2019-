/*
Hackerrank:Play with words:https://www.hackerrank.com/challenges/strplay/problem
*/

int playWithWords(string s) {
    /*
     * Write your code here.
     */
    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    
    for(int i=0;i<n;i++)
    dp[i][i]=1;
    
    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1])
            dp[i][i+1]=2;
        else
            dp[i][i+1]=1;
    
    for(int l=3;l<=n;l++)
    for(int i=0;i<=n-l;i++)
    {
        int r=i+l-1;
        if(s[i]==s[r])
            dp[i][r]=dp[i+1][r-1]+2;
        else
            dp[i][r]=max(dp[i+1][r],dp[i][r-1]);
    }
    
    int ans=0;
    for(int i=0;i<n-1;i++)
        ans=max(ans,dp[0][i]*dp[i+1][n-1]);
    return ans;
}

