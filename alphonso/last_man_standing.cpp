#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    int n;
    cin>>n;
    float p=log2(n);
    if(p-(int)p!=0.0)
    p++;
    int pp=pow(2,(int)p);
    cout<<2*n+1-pp<<endl;
    return 0;
}

