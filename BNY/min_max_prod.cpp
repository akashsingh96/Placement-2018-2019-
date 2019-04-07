
/*The input data will be given as pairs of command and value. Valid commands are "push" and "pop" and the value is always integer. These operations are executed on a set of integers where the given value is stored and removed.

Each time any operation is executed, the minimum and the maximum must be calculated and the product of these two must be stored as part of the solution.

Two examples are given:

In the first example, we have the sequence

push 1
push 2
push 3
pop 1
that must output

1
2
3
6
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    map<int,int>mp;
    while(t--)
    {
        string s;
        int n;
        cin>>s>>n;
        if(s=="push")
            mp[n]++;
        else
        {
            mp[n]--;
            if(!mp[n])
                mp.erase(n);
        }
        cout<<mp.begin()->first*mp.rbegin()->first<<endl;
        
    }
    return 0;
}
