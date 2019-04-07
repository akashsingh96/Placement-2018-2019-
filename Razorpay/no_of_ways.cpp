/*

Given a number N, the task is find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int count=0;
        for(long long int i=1;(i*(i+1))<2*n;i++)
        {
            double a=(1.0*n-(i*(i+1)/2))/(i+1);
            if(a-(int)a==0.0)
            count++;
        }
        cout<<count<<endl;
    }
}

