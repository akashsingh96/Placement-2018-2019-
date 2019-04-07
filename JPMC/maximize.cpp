/*
A variation of AGGRESIVE COWS

Given an array representing n positions along a straight line. Find k (where k <= n) elements from the array such that the maximum distance between any two (consecutive points among the k points) is maximized.

Examples :

Input : arr[] = {1, 2, 8, 4, 9}
            k = 3
Output : 3
Largest minimum distance = 3
3 elements arranged at positions 1, 4 and 8, 
Resulting in a minimum distance of 3

Input  : arr[] = {1, 2, 7, 5, 11, 12}
             k = 3
Output : 5
Largest minimum distance = 5
3 elements arranged at positions 1, 7 and 12, 
resulting in a minimum distance of 5 (between
7 and 12)
*/

#include<bits/stdc++.h>
using namespace std;
int func(int mid,vector<int>v,int k)
{
    int start=0;
    int c=1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[start]>=mid)
        {
            c++;
            start=i;
        }
        if(c==k)
            return 1;
    }
    return 0;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int r=v[n-1]-v[0];
    int l=INT_MAX;
    for(int i=1;i<n;i++)
        l=min(l,v[i]-v[i-1]);
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(func(mid,v,k))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans;
    return 0;
}

