/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
*/


class Solution {
public:
    int findShortestSubArray(vector<int>& v) {
    
    int n=v.size();
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        //n>>v[i];
        mp[v[i]]++;
    }
    int maxi=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    maxi=max(maxi,it->second);
    
    map<int,int>mp2;
    int start=-1;
    int count=0;
    int count_e=-1;
    int ans=INT_MAX;
    int i=0;
    while(i!=n)
    {
        mp2[v[i]]++;
        if(count<=mp2[v[i]])
        {
            count=mp2[v[i]];
            count_e=v[i];
        }
        while(count==maxi && i>start)
        {
            ans=min(ans,i-start);
            start++;
            mp2[v[start]]--;
            if(v[start]==count_e)
            {   
                count=0;
                count_e=-1;
                break;   
            }
        }
        i++;
    }
    
    return ans;
        
    }
};
