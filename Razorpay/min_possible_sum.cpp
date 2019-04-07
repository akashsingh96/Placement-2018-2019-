/*
Q.)
Given a sorted integer array. We need to make array elements distinct by increasing values and keeping array sum minimum possible. We need to print the minimum possible sum as output.

Examples:

Input : arr[] = { 2, 2, 3, 5, 6 } ; 
Output : 20
Explanation : We make the array as {2, 
3, 4, 5, 6}. Sum becomes 2 + 3 + 4 + 
5 + 6 = 20

Input : arr[] = { 20, 20 } ; 
Output : 41
Explanation : We make {20, 21}

Input :  arr[] = { 3, 4, 6, 8 };
Output : 21
Explanation : All elements are unique 
so result is sum of each elements.  
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    cin>>t;
    vector<int>v(t);
    for(int i=0;i<t;i++)
        cin>>v[i];
    
    int p=v[0];
    int sum=v[0];
    for(int i=1;i<t;i++)
        if(v[i]<=p)
        {
            p++;
            sum+=p;
        }
        else
        {
            p=v[i];
            sum+=p;
        }
    cout<<sum<<endl;
    return 0;
}
