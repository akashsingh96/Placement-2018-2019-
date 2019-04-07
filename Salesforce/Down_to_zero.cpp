/* https://www.hackerrank.com/challenges/down-to-zero-ii/problem
*/

#include <bits/stdc++.h>
using namespace std;
int downToZero(int n)
{
    
    queue<pair<int,int>>q;
    q.push({0,n});
    int ans=0;
    set<int>st;
    while(!q.empty())
    {
        int t=q.front().second;
        int steps=q.front().first;
        q.pop();
        
        if(t==0)
        {
            ans=steps;
            break;
        }
        
        //int flag=0;
        for(int i=sqrt(t);i>1;i--)
            if(t%i==0)
            {
                if(st.find(t/i)==st.end())
                {
                    q.push({steps+1,t/i});
                    st.insert(t/i);
                }
            }
        //if(!flag)
        if(st.find(t-1)==st.end())
        {
            q.push({steps+1,t-1});
            st.insert(t-1);
        }
    }
     
    return ans;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<downToZero(n)<<endl;
    }

    return 0;
}

