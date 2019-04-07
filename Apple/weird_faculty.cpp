#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
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
        
        vector<int>pre(n,0);
        if(v[i]==1)
        pre[0]=1;
        else
        pre[0]=-1;
        
        for(int i=1;i<n;i++)
        if(v[i]==1)
        pre[i]=pre[i-1]+1;
        else
        pre[i]=pre[i-1]-1;
        
        
        if(pre[n-1]<0)
        cout<<"0"<<endl;
        else
        {   
	    int k;
            for(k=0;k<n;k++)
            if(pre[k]>pre[n-1]-pre[k])
            break;
            
            cout<<k+1<<endl;
        }
    }
    
    return 0;
}

