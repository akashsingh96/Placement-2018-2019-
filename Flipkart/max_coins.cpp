/*

Given a limited number of coins of denominations 1, 5, 10, and 25
as p, q, r, and s respectively, return the maximum number of coins 
which can be used to reach a target "price", if possible.
Your function should return a vector of length 4 representing the
number of coins used for the denominations 1, 5, 10, 25 respectively.
If no solution is possible, return a vector of 0s.
0 <= price, p, q, r, s <= 100000
*/

Tag:Dp

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int a,b,c,d;
map<pair<vector<int>,int>,int>mp;
int find(vector<int>&v,int price)
{
    if(price==0 && a+b+c+d>v[0]+v[1]+v[2]+v[3])
    {
        a=v[0];
        b=v[1];
        c=v[2];
        d=v[3];
        return 0;
    }
    if(price<0)
        return 0;
    if(mp.find({v,price})!=mp.end())
        return mp[{v,price}];
    int h=0;
    if(v[0])
    {
        v[0]--;
        h=max(h,1+find(v,price-1));
        v[0]++;
    }
    if(v[1])
    {
        v[1]--;
        h=max(h,1+find(v,price-5));
        v[1]++;
    }
    if(v[2])
    {
        v[2]--;
        h=max(h,1+find(v,price-10));
        v[2]++;
    }
    if(v[3])
    {
        v[3]--;
        h=max(h,1+find(v,price-25));
        v[3]++;
    }
    return mp[{v,price}]=h;
        
        
}

int main()
{
    vector<int>v(4);
    int p,q,r,s;
    cin>>p>>q>>r>>s;
    v[0]=p;
    v[1]=q;
    v[2]=r;
    v[3]=s;
    int n;
    cin>>n;//price;
    a=p,b=q,c=r,d=s;
    cout<<find(v,n)<<endl;
    cout<<p-a<<q-b<<r-c<<s-d<<endl;
    return 0;
}
