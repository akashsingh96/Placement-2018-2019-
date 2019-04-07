/*
Q.)
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

*/


int find(Node* root)
{
    if(!root)
    return 0;
    else if(!root->left && !root->right)
    return root->data;
    
    int left=find(root->left);
    int right=find(root->right);
    return root->data +max(left,right);
}
int func(Node* root)
{
    if(!root)
    return 0;
    if(!root->right && !root->left)
    return root->data;
    int left=find(root->left);
    int right=find(root->right);
    int data=root->data+left+right;
    int l=func(root->left);
    int r=func(root->right);
    return max(data,max(l,r));
}
int maxPathSum(struct Node *root)
{
    if(!root)
    return 0;
    return func(root);
}
