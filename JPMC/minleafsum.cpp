/*

Given a Binary Tree of size N, your task is to complete the function minLeafSum(), that should return the sum of all the leaf nodes that are at minimum level of the given binary tree.
Example:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \ 
 7    2      
Output :
sum = 5 + 8 = 13
*/


#include<bits/stdc++.h>
void func(Node* root,map<int,int>&mp,int count)
{
    if(root==NULL)
    return;
    else if(!root->left && !root->right)
    if(mp.find(count)!=mp.end())
    mp[count]+=root->data;
    else
    mp[count]=root->data;
    
    func(root->left,mp,count+1);
    func(root->right,mp,count+1);
    
}
int minLeafSum(Node* root)
{
	// Code A
	int count=0;
	map<int,int>mp;
	func(root,mp,count);
	auto it=mp.begin();
	return it->second;	
}
