/*
https://www.spoj.com/problems/AGGRCOW/
*/

#include <bits/stdc++.h>
using namespace std;
int func(int x,vector<int>v,int c)
{
    int y=1;
    int start=0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[start]>=x)
        {
            y++;
            start=i;
        }
        if(y==c)
        return 1;
    }
    return 0;
}
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        
        sort(v.begin(),v.end());
        int mini=INT_MAX;
        for(int i=1;i<n;i++)
        mini=min(mini,v[i]-v[i-1]);
         
        int maxi=v[n-1]-v[0];
        
        int l=mini;
        int r=maxi;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(func(mid,v,c))
            {
                l=mid+1;
                ans=max(ans,mid);
            }
            else
            r=mid-1;
        }
        
        cout<<ans<<endl;
        
    }
    return 0;
}
