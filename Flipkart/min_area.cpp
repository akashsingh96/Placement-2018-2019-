/*

Given two vectors of length n representing the x and y 
coordinates of cartesian points, find the minimum possible area 
of a rectangle which can be formed using four distinct points.

1 <= n <= 1000
*/



#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int canbediagonal(int x1,int y1,int x2,int y2)
{
    if(x1 !=x2 && y1!=y2)
        return 1;
    else
        return 0;
    
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>p(n);
    for(int i=0;i<n;i++)
        cin>>p[i].first;
    for(int j=0;j<n;j++)
        cin>>p[j].second;
    
    map<pair<int,int>>mp
    for(int i=0;i<n;i++)
    {
         mp[p[i]]=1;
    }
    sort(p.begin(),p.end());
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int x1=p[i].first;
            int y1=p[i].second;
            int x2=p[j].first;
            int y2=p[j].second;
            
            if(canbediagonal(x1,y1,x2,y2))
            {
                if(mp.find(make_pair(x1,y2)) && mp.find(make_pair(x2,y1)))
                {
                    int area=abs((x2-x1)*(y2-y1));
                    mini=min(mini,area);
                }
            }
        }
    cout<<mini<<endl;
    return 0;
}
