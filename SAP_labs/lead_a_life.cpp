/*https://drive.google.com/file/d/1vkAT9IqPARME5C2TVZYhRfViQbpBlnB1/view*/

#include <bits/stdc++.h>
using namespace std;

int recur(int j,vector<int>u,vector<int>v,int e,int energ,vector<vector<int>> &dp,int n)
{
    if(energ<0)
        return 0;
    else if(j==n-1)
        return energ*u[j];
    if(dp[j][energ]!=-1)
        return dp[j][energ];
    
    int maxi=0;
    int diff=u[j]-v[j];
    for(int energy=e;energy>=0;energy--)
    {
        if(diff>=0)
        maxi=max(maxi,energ*u[j]-energy*v[j]+recur(j+1,u,v,e,energy,dp,n));
        else
        maxi=max(maxi,(energ-energy)*u[j]+recur(j+1,u,v,e,energy,dp,n));
    }
    dp[j][energ]=maxi;
    return dp[j][energ];
}
int calculateProfit(int n,vector<int>u,vector<int>v,int e)
{
    vector<vector<int>> dp(n+1,vector<int>(e+1,-1));
    int q = recur(0,u,v,e,e,dp,n);
   /* rep(i,0,n){
        rep(j,0,e+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return q;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    int n,x,i,e;
    cin>>n>>e;
    vector<int> u;
    vector<int> v;
    rep(i,0,n){
        cin>>x;
        u.pb(x);
    }
    rep(i,0,n){
        cin>>x;
        v.pb(x);
    }
    // cin>>t;
    while(t--){
       cout<<calculateProfit(n,u,v,e);
    }
    return 0;
}

/*
6
6
2 8 5 3 4 6
2 2 2 3 5 5

6 6
8 4 3 5 9 6
10 6 3 8 10 100
*/
