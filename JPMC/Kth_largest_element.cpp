/*
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.
*/

#include<bits/stdc++.h>
void recur(Node* root,vector<int>&v)
{
    if(root==NULL)
    return;
    recur(root->left,v);
    v.push_back(root->key);
    recur(root->right,v);
        
}
void kthLargest(Node *root, int k)
{
    //Your code here
    vector<int>v;
    recur(root,v);
    // for(int i=0;i<v.size();i++)
    // cout<<v[i]<<" ";
    cout<<v[v.size()-k]<<endl;
    return;
}

