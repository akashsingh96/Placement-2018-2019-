/*
Array of product prices given. Each product is discounted by the first element to its right which is <= to it. If not present, discount is 0.
*/

int discount(vector<int>v)
{
    int n=v.size();
    stack<int>s;
    
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        s.push(v[i]);
        else if(s.top()<=v[i])
        {
            ans+=v[i]-s.top();
            s.push(v[i]);
        }
        else
        {
            while(!s.empty() && s.top()>v[i])
            s.pop();
            if(!s.empty())
            ans+=v[i]-s.top();
            s.push(v[i]);
        }
    }
    
    return ans;
    
}
