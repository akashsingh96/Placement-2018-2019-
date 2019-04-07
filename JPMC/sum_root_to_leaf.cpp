/*

Q.)Given a binary tree, where every node value is a number . Find the sum of all the numbers which are formed from root to leaf paths.

For example consider the following Binary Tree.
 

           6                               
         /   \                          
        3     5                      
      /   \     \
     2    5      4             
        /  \                        
       7    4                 
            
  There are 4 leaves, hence 4 root to leaf paths:
  Path                      Number
  6->3->2                   632
  6->3->5->7                6357
  6->3->5->4                6354
  6->5>4                    654   
Answer = 632 + 6357 + 6354 + 654 = 13997 
*/

void func(Node* root,long long int& ans,int val)
{
    if(!root)
    return;
    
    if(!root->left && !root->right)
    {
        ans+=10*val+root->data;
    }
    
    long long int  value=10*val+root->data;
    func(root->left,ans,value);
    func(root->right,ans,value);
    return;    
}
long long treePathsSum(Node *root)
{
    //Your code here
    long long int ans=0;
    func(root,ans,0);
    return ans;
}
