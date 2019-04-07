/*
https://www.hackerrank.com/contests/hack-it-to-win-it-paypal/challenges/q4-traveling-is-fun

*/


#include <bits/stdc++.h>

using namespace std;

vector <int> connectedCities(int n, int g, vector <int> x, vector <int> y)
 {
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++)
        parent[i]=i;
    
    for(int i=g+1;i<=n/2;i++)
    {
        for(int j=2*i;j<=n;j+=i)
        {
            if(parent[j]==j)
            parent[j]=parent[i];
            else
            {
                parent[i]=parent[j];
            }
        }
        for(int j=2*i;j<=n;j+=i)
        {
            parent[j]=parent[i];
        }
    }
    
    int t=x.size();
    vector<int>ans(t);
    for(int i=0;i<t;i++)
        if(parent[x[i]]==parent[y[i]])
            ans[i]=1;
        else
            ans[i]=0;
    
    return ans;
            
        
}

int main() {
    int n;
    cin >> n;
    int g;
    cin >> g;
    int originCities_cnt;
    cin >> originCities_cnt;
    vector<int> originCities(originCities_cnt);
    for(int originCities_i = 0; originCities_i < originCities_cnt; originCities_i++){
    	cin >> originCities[originCities_i];
    }
    int destinationCities_cnt;
    cin >> destinationCities_cnt;
    vector<int> destinationCities(destinationCities_cnt);
    for(int destinationCities_i = 0; destinationCities_i < destinationCities_cnt; destinationCities_i++){
    	cin >> destinationCities[destinationCities_i];
    }
    vector <int> res = connectedCities(n, g, originCities, destinationCities);
    for (ssize_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
