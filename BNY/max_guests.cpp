/*
Consider a big party where a log register for guest’s entry and exit times is maintained. Find the time at which there are maximum guests in the party. Note that entries in register are not in any order.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>u(n),v(n);
	    for(int i=0;i<n;i++)
	    cin>>u[i];
	    
	    for(int j=0;j<n;j++)
	    cin>>v[j];
	    
	    
	    int mp[1000007]={0};
	    
	    for(int i=0;i<n;i++)
	    {
	        mp[u[i]]++;
	        mp[v[i]+1]--;
	    }	    
	    for(int i=1;i<1000007;i++)
	    mp[i]+=mp[i-1];
	    int maxi=0;
	    int maxg=0;
	    for(int i=0;i<n;i++)
	    if(maxi<mp[u[i]])
	    {
	        maxi=mp[u[i]];
	        maxg=u[i];
	    }
	    
	    cout<<maxi<<" "<<maxg<<endl;
	    
	    
	}
	return 0;
}

