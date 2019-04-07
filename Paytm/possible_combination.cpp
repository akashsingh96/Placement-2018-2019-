/*				Dynamic Programming
Q.)
Given a number k, find all the possible combinations of k-bit numbers with n-bits set where 1 <= n <= k. The solution should print all numbers with one set bit first, followed by numbers with two bits set,.. up to the numbers whose all k-bits are set. If two numbers have the same number of set bits, then smaller number should come first.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{	
	int t;
	cin>>t;
	vector<vector<vector<string>>>(k+1,vector<vector<string>(k+1));
	v[0][0]="";
	for(int i=1;i<=k;i++)
	v[i][0]=v[i-1][0]+"0";
	
	for(int i=1;i<=k;i++)
	for(int j=1;j<=k;j++)
	{
		for(int z=0;i<v[i-1][j].size();z++)
		v[i][j].push_back("0"+v[i-1][j][z]);
		
		for(int z=0;i<v[i-1][j-1].size();z++)
		v[i][j].push_back("1"+v[i-1][j-1][z]);
	}
	for(int i=1;i<=k;i++)
	{
		for(int z=0;z<v[k][i].size();z++)
		cout<<v[k][i][z]<<" ";
		cout<<endl;
	}	
	
	return 0;
}
