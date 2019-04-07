/* Chocolate and the wrapper puzzle
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,w;
        cin>>n>>p>>w;
        int val=n/p;
        cout<<val+(val-1)/(w-1);
    }
    return 0;
}
