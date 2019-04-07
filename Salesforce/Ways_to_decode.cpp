/*
https://www.interviewbit.com/problems/ways-to-decode/
*/


/*	
	corner cases:
1. 0123---0
2. 123005--0
3. 123056--dp[i]=dp[i-1];
4. 123246--dp[i]=dp[i-1]+dp[i-2]
5. 123555--dp[i]=dp[i-1]'
*/

int Solution::numDecodings(string s) {

    int n=s.size();
    
    vector<int>dp(n+1,0);
    dp[0]=1;
    if(s[0]=='0')
    return 0;
    
    
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        if(s[i-1]=='0')
        {
            if(s[i-2]!='0' && s.substr(i-2,2)<="26")
            dp[i]=dp[i-2];
            else
            return 0;
        }
        else
        {
            dp[i]=dp[i-1];
            if(s[i-2]!='0' && s.substr(i-2,2)<="26")
            dp[i]+=dp[i-2];
        }
    }
    
    return dp[n];
    
}
