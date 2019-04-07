/*Morgan Stanley 
Q) Find clusters of 1 surrounded by completely by 0s where diagonal moments are not allowed

Tags:Graph

Input:
6 7
1 0 1 0 0 1 0
0 1 0 0 0 1 1
0 0 1 1 0 1 0
0 0 0 1 0 1 1
1 1 0 1 0 0 0
1 1 0 1 0 1 1
Output=3

Input:
1 1 0 0
1 1 0 0
0 0 1 1
0 0 1 1

Output:
0

Input:
4 4
1 1 0 0
1 1 0 0 
0 0 1 1 
1 1 1 0

Output:
0

Input:
4 4
1 1 0 0
1 1 0 0 
0 0 1 1 
1 0 1 0

Output:
1

Input:
6 7
1 1 1 0 0 1 0
0 1 0 0 0 1 1
0 0 0 1 0 1 0
0 0 0 1 0 1 1
1 1 0 1 0 0 0
1 1 0 1 0 1 1

Output:
5
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int  lli;
int invalid(int i,int j,vector<vector<int>>&v)
{
    int n=v.size();
    int m=v[0].size();
    if(!v[i][j])
    return 1;
    if(i+1<n && j+1<m && v[i+1][j+1] && !v[i+1][j] && !v[i][j+1])
    return 1;
    if(i+1<n && j-1>=0 && v[i+1][j-1] && !v[i+1][j] && !v[i][j-1])
    return 1;
    if(i-1>=0 && j+1<m && v[i-1][j+1] && !v[i-1][j] && !v[i][j+1])
    return 1;
    if(i-1>=0 && j-1>=0 && v[i-1][j-1] && !v[i-1][j] && !v[i][j-1])
    return 1;
    
    return 0;
}
int issafe(int i,int j,vector<vector<int>>&vis,vector<vector<int>>v)
{
    if(i>=0 && i<v.size() && j>=0 && j<v[0].size() && v[i][j] && !vis[i][j])
    return 1;
    else
    return 0;
}
void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>v,int& flag)
{
    if(invalid(i,j,v))
    flag=0;
    vis[i][j]=1;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    
    for(int k=0;k<4;k++)
    {
        int x=i+dx[k];
        int y=j+dy[k];
        if(issafe(x,y,vis,v))
        dfs(x,y,vis,v,flag);
    }
    
    return;
}
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>v[i][j];
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    int count=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(!vis[i][j] && v[i][j])
        {
            int flag=1;
            dfs(i,j,vis,v,flag);
            if(flag)
            count++;
        }
    }
    cout<<count;
    return 0;
}
