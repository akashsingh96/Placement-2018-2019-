#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        
        sort(v.begin(),v.end());
        
        int count=0;
        
        map<int,int>mp;
        mp[v[0]]=1;
        
        for(int i=1;i<n;i++)
        {
            int val=x-v[i];
            if(mp.find(val)!=mp.end())
            {
                count++;
                mp.erase(val);
            }
            else
            mp[v[i]]=1;
        }
        
        cout<<count<<endl;
    }
    return 0;
}
