#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    cin>>t;
    vector<pair<int,int>>vp(t);
    for(int i=0;i<t;i++)
        cin>>vp[i].first;
    int maxi=0;
    for(int i=0;i<t;i++)
    {
        cin>>v[i].second;
        maxi=max(maxi,v[i].second);
    }
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++)
        mp[v[i].second].push_back(v[i].first);
    priority_queue<int>pq;
    
    int ans=0;
    while(maxi)
    {
        if(mp.find(maxi)!=mp.end())
        for(int i=0;i<mp[maxi].size();i++)
        pq.push(mp[maxi][i]);
        
        if(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        maxi--;
    }
    
    cout<<ans<<endl;   

    return 0;
}

