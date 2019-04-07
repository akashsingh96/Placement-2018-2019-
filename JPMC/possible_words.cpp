/*
            
Given a keypad as shown in diagram, and an N digit number. List all words which are possible by pressing these numbers.



Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line of each test case is N, N is the number of digits. The second line of each test case contains D[i], N number of digits.

Output:
Print all possible words from phone digits with single space.

Constraints:
1 <= T <= 10
1 <= N <= 10
2 <=  D[i] <= 9

Dont use map will get tle on vector
*/

using namespace std;
void func(vector<string>v,vector<int>num,int i,int n,string s)
{
    if(i==n)
    {cout<<s<<" ";
    return;
    }
    
    for(int j=0;j<v[num[i]].size();j++)
    {
        func(v,num,i+1,n,s+v[num[i]][j]);
    }
    
    return;
}
int main() {
	//code
	int t;
	cin>>t;
	vector<string>v{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>num(n);
	    for(int i=0;i<n;i++)
	    cin>>num[i];
	    func(v,num,0,n,"");
	    cout<<endl;
	}
	return 0;
}
