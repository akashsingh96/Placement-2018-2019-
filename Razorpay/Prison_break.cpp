/*				
Prison break:
https://www.evernote.com/client/snv?noteGuid=a46acf88-f8bf-4a0a-8ec6-99b6658da40a&noteKey=6aaeb71b181fe6b3&sn=https%3A%2F%2Fwww.evernote.com%2Fshard%2Fs337%2Fsh%2Fa46acf88-f8bf-4a0a-8ec6-99b6658da40a%2F6aaeb71b181fe6b3&title=HackerRank

Programmer Sam is planning to escape from prison! The prison's gate consists of horizontal and vertical bars that are spaced one unit apart, so the area of each hole between the bars is 1 × 1. Sam manages to remove certain bars and make some of these holes bigger. Determine the area of the largest hole in the gate after the bars are removed.
 
For example, consider the diagram below. The left image depicts the initial prison gate with n = 6 horizontal and m = 6 vertical bars, where the area of the biggest hole in the bars is 1 × 1. The right image depicts that same gate after Sam removes horizontal bar 4 and vertical bar 2, at which point the area of the biggest hole in the bars becomes 2 × 2 = 4:
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    int n,m;
    cin>>n>>m;
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++)
        cin>>h[i];
    int n2;
    cin>>n2;
    vector<int>v(n2);
    for(int i=0;i<n2;i++)
        cin>>v[i];
    
    int maxx=INT_MIN,maxy=INT_MIN;
    int count=1;
    for(int i=1;i<n1;i++)
        if((h[i]-h[i-1])==1)
            count++;
        else
        {   
            maxx=max(maxx,count);
            count=1;
        }
    maxx=max(maxx,count);
    count=1;
    for(int i=1;i<n2;i++)
        if(v[i]-v[i-1]==1)
            count++;
        else
        {   
            maxy=max(maxy,count);
            count=1;
        }
    maxy=max(maxy,count);
    cout<<maxx*maxy<<endl;
    
    return 0;
}
