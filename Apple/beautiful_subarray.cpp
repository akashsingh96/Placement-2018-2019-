
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        vector<int>pre(n);
        pre[0]=1;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]%2)
            count++;
            pre[count]++;
        }
        
        int ans=0;
        if(m==0)
        {
            for(int i=0;i<n;i++)
            ans+=(pre[i]*(pre[i]-1))/2;
        }
        else
        {
            for(int i=m;i<n;i++)
            ans+=pre[i]*pre[i-m];
            
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
