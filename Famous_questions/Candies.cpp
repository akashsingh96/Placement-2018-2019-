/* Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. She gives the students candy in the following minimal amounts: 
[1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.

https://www.hackerrank.com/challenges/candies/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
vector<int>dp(n,0);
    dp[0]=1;
    long ans=0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>arr[i-1])
        {
            dp[i]=dp[i-1]+1;
        }
        else
        {
            dp[i]=1;
        } 
    }
    
    for(int i=n-2;i>=0;i--)
    {if(arr[i]>arr[i+1]&&dp[i]<=dp[i+1])
        dp[i]=dp[i+1]+1;        
    }
    for(int i=0;i<n;i++)
        ans+=dp[i];
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
