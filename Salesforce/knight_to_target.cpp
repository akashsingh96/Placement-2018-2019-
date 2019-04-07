/*
			Minimum number of steps taken by a knight to reach the target
			Tried using set but getting tle so better to use vis[n+1][n+1]
*/

#include<bits/stdc++.h>
using namespace std;
int issafe(int x,int y,vector<vector<int>>& vis,int n)
{
    if(x>=1 && x<=n && y>=1 && y<=n && !vis[x][y])
    return 1;
    else 
    return 0;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    pair<int,int>p1,p2;
	    cin>>p1.first>>p1.second;
	    cin>>p2.first>>p2.second;
	    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        
        queue<pair<pair<int,int>,int>>q;
        q.push(make_pair(make_pair(p1.first,p1.second),0));
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        vis[p1.first][p1.second]=1;
        int flag=0;
        while(!q.empty())
        {
            pair<pair<int,int>,int>p= q.front();
            q.pop();
            int x=p.first.first;
            int y=p.first.second;
            if(x==p2.first && y==p2.second)
            {
                cout<<p.second<<endl;
                flag=1;
                break;
            }
            
            for(int i=0;i<8;i++)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(issafe(xx,yy,vis,n))
                {   vis[x][y]=1;
                    int dis=p.second;
                    q.push(make_pair(make_pair(xx,yy),dis+1));
                }
            }
        }
        if(!flag)
        cout<<"1"<<endl;
	}
	return 0;
}

