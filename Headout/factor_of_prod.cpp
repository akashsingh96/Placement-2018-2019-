/*

Given an array of numbers and a list queries, find the number of factors of the product of the numbers in the range, for each query.
 

n=5

arr={1,2,3,4,5}

Query: 1 3

Output should be 4

Explanation: the product of numbers between 1 to 3 (1-based indexing) is 1*2*3=6

Factors of 6=1,2,3,6. Therefore the answer will be 4.


Constraints:

1<=T<=10000

1<=N<=10000

1<=A[i]<=1000
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q, l, r;
    cin>>n >>q;
    int arr[n];
    bool p[1001];
    vector<int> primes;
    memset(p, true, sizeof(p));
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=2; i<=1000; i++){
        if(p[i]){
            for(int j=i+i; j<=1000; j+=i){
               p[j] = false;
            }
            primes.push_back(i);
        }
    }
    int len = primes.size();
    int dp[len][n+1];
    memset(dp, 0, sizeof(dp));
    for(int j=0; j<n; j++){
        for(int i=0; i<primes.size(); i++)
        {
            while((arr[j]>1) and ((arr[j]%primes[i])==0))
            {
               arr[j]/=primes[i];
               dp[i][j+1]++;
            }
        }
    }
    for(int i=0; i<primes.size(); i++){
        for(int j=2; j<=n; j++){
           dp[i][j] += dp[i][j-1];
        }
    }
    for(int k=0; k<q; k++){
        cin>>l >>r;
        int prod = 1;
        for(int i=0; i<primes.size(); i++){
            prod = prod*(dp[i][r+1] - dp[i][l] + 1);
        }
        cout<<prod <<"\n";
    }
   return 0;
}
