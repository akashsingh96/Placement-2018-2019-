#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
    return a.size()<b.size();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end(),cmp);
        map<string,int>mp;
        vector<int>dp(n+1,1);
        mp[v[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                string s=v[i];
                s.erase(s.begin()+j);
                if(mp.find(s)!=mp.end())
                    dp[i]=max(dp[i],dp[mp[s]+1]);
            }
            mp[v[i]]=i;
        }
               
        cout<<*max_element(dp.begin(),dp.end())<<endl;
    }
    return 0;
}

