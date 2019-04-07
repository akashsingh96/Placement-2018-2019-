/* Truck Tour
Suppose there is a circle. There are  petrol pumps on that circle. Petrol pumps are numbered  to  (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each litre of the petrol.

Input Format

The first line will contain the value of .
The next  lines will contain a pair of integers each, i.e. the amount of petrol that petrol pump will give and the distance between that petrol pump and the next petrol pump.

Constraints:


Output Format

An integer which will be the smallest index of the petrol pump from which we can start the tour.

Sample Input

3
1 5
10 3
3 4
Sample Output

1
Explanation

We can start the tour from the second petrol pump.

https://www.hackerrank.com/challenges/truck-tour/problem?h_r=profile
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{ios_base::sync_with_stdio(false); 
ll n;
cin>>n;
vector<ll>dist(n),pet(n);
queue<ll>q;
for(ll i=0;i<n;i++)
{
    cin>>pet[i]>>dist[i];
}
ll x=0;
ll i=0;
ll p=0;
 
while(1)
{
    if(p>=0)
   { q.push(i);
       p+=pet[i];
       p-=dist[i];
    // cout<<p<<endl;
       x++;
    i=(i+1)%n;
   }
   else
   {
       while(p<0)
       {
           p-=pet[q.front()];
           p+=dist[q.front()];
           // cout<<q.front()<<endl;
           q.pop();
           x--;
           if(!q.empty()&&q.front()==0)
           {
               cout<<-1;
               return 0;
           }
       }
   }
   
   if(i==q.front())
       break;
   
}
cout<<q.front();
}
