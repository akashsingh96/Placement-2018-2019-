/*
Q)
	Given a number N tell if its possible to convert it into a fibonacci number by rearranging 		the digits of N.

        Constraints: 1<=N<=10^15.

*/

#include<bitstdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    cin>>t;
    vector<lli>fib(81,0);
    fib[1]=1;
    
    for(int i=2;i<=80;i++)
    fib[i]=fib[i-2]+fib[i-1];
    
    map<string,int>mp;
    
    for(int i=1;i<=80;i++)
    {
        string s=to_string(fib[i]);
        sort(s.begin(),s.end());
        mp[s]=1;
    }
    while(t--)
    {
        int n;
        cin>>n;
        string s=to_string(n);
        sort(s.begin(),s.end());
        
        if(mp.find(s)==mp.end())
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
    }
    
    return 0;
    
}

