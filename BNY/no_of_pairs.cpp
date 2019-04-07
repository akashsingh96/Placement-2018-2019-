/*
Given an array if ‘n’ positive integers, count number of pairs of integers in the array that have the sum divisible by 4.
instead of 4 it was 60 but same concept will be used
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
	    vector<int>v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    sort(v.begin(),v.end());
	    vector<int>rem(4);
	    for(int i=0;i<n;i++)
	    rem[v[i]%4]++;
	    int ans=(rem[0]*(rem[0]-1))/2;
	    for(int i=1;i<2;i++)
	    ans+=rem[i]*rem[4-i];
	    ans+=rem[2]*(rem[2]-1)/2;
	    cout<<ans<<endl;
	}
	return 0;
}
