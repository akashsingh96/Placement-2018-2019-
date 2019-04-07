/*Q. Friend Circles
https://www.hackerrank.com/contests/juniper-hackathon/challenges/friend-circles
*/

#include<bits/stdc++.h>
using namespace std;
int find(int x,vector<int>& parent)
{
    if(parent[x]==x)
        return x;
    parent[x]=find(parent[x],parent);
    return parent[x];
}
void merge(int x,int y,vector<int>&parent,vector<int>&size)
{
    if(size[x]>size[y])
    {
        parent[y]=x;
        size[x]+=size[y];
    }
    else
    {
        parent[x]=y;
        size[y]+=size[x];
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    vector<int>parent(n);
    for(int i=0;i<n;i++)
        parent[i]=i;
    vector<int>size(n,1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j && v[i][j]=='Y')
            {
                int x=find(i,parent);
                int y=find(j,parent);
                if(x==y)
                    continue;
                else
                    merge(x,y,parent,size);
            }
    for(int i=0;i<n;i++)
        int x=find(i,parent);
    set<int>s;
    for(int i=0;i<n;i++)
        if(s.find(parent[i])==s.end())
            s.insert(parent[i]);
    cout<<s.size()<<endl;
    return 0;
}
