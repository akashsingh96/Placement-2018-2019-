/*
Given a positive number N. The task is to round N to nearest multiple of 10. Number can be so big and can contains 1000 of digits.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        if(s[n-1]<='5')
        s[n-1]='0';
        else
        {
            s[n-1]='0';
            int carry=1;
            int n=s.size();
            int j=n-2;
            while(carry && j>=0)
            {
                carry=(s[j]-'0'+1)/10;
                s[j]=(s[j]-'0'+1)%10+'0';
                j--;
            }
            if(carry)
            s=to_string(carry)+s;
        }
        cout<<s<<endl;
    }
	return 0;
}

