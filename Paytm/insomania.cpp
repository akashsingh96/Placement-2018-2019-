/*
Q.)
Chef sometimes suffers from insomnia. During sleepless nights, he often plays this game: He creates an array A of N integers and also decides one integer K. After that, he tries to count the number of non-empty contiguous subsequences (subsegments) of A, such that there are no bad pairs of integers in this subsegment. A pair (x, y) of integers is called bad if x is situated to the left of y in the array and x mod y = K. Finally, before going to sleep, Chef wrote down the answer on a sheet of paper. Sadly, he has forgotten it this morning and want your help regarding that.

Constraints
1 ≤ N, Ai ≤ 10^5
0 ≤ K ≤ 10^5
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{     
    lli n,t;
    cin>>n>>t;
    vector<lli>v(n);
    for(lli i=0;i<n;i++)
        cin>>v[i];
    map<lli,lli>mp;
    lli maxi=*max_element(v.begin(),v.end());
    lli last=-1;
    lli ans=0;
    for(lli i=0;i<n;i++)
    {
        if(v[i]>t)
        {
            for(int j=t;j<=maxi;j+=v[i])
                if(mp.find(j)!=mp.end())
                    last=max(last,mp[j]);
        }
        ans+=i-last;
        mp[v[i]]=i;
    }
    

    cout<<ans;
    return 0;    
}
