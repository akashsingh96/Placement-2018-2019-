/*
Maximum sum such that no two elements are adjacent
Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.
*/

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    
	    vector<int>dp(n);
	    
	    dp[0]=v[0];
	    dp[1]=max(v[0],v[1]);
	    
	    for(int i=2;i<n;i++)
	    dp[i]=max(dp[i-1],dp[i-2]+v[i]);
	    
	    cout<<dp[n-1]<<endl;
	}
	
	return 0;
}
