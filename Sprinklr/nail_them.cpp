/* 

Quest5-NAIL THEM :SPOJ
https://www.spoj.com/problems/QUEST5/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<pair<int,int>>v;
	    for(int i=0;i<n;i++)
	    {
	        int a,b;
	        cin>>a>>b;
	        v.push_back({a,b});
	    }
	    sort(v.begin(),v.end());
	    int s1=v[0].first;
	    int s2=v[0].second;
	    int count=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        int s3=v[i].first;
	        int s4=v[i].second;
	        if(s2>=s3)
	        {
	            s1=s3;
	            s2=min(s2,s4);
	        }
	        else
	        {
	            count++;
	            s1=s3;
	            s2=s4;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}

