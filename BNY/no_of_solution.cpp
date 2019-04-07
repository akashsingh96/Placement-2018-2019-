/*
Given N, find the number of ordered pairs of positive integers (x,y) satisfying
the following relation:
1/x + 1/y = 1/N!
0 <= N <= 100000
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int mod = 1e9 + 7; 
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        vector<lli>v(n+1,1);
        lli ans=1;
        for(lli i=2;i<=n;i++)
        {
            if(v[i])
            {
                for(lli j=1;i*j<=n;j++)
                v[i*j]=0;
                
                lli num=n;
                lli power=0;
                
                while(n!=1)
                {
                    power+=n/v[i];
                    n/=v[i];
                }
                ans=(ans*(1LL+2*power))%mod;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
