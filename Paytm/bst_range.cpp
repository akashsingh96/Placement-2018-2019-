/*
Q.)
Given a Binary Search Tree (BST) of integer values and a range [low, high], return count of nodes where all the nodes under that node (or subtree rooted with that node) lie in the given range.
*/


bool func(Node* root,int& k,int l,int r)
{
	if(!root)
	return true;
	bool left=func(root->left,k,l,r);
	bool right=func(root->right,k,l,r);
	if(left && right && root->data>=l && root->data<=r)
	{
		k++;
		return true;
	}
	return false;
}
int count(Node* root,int k,int l,int r)
{
	int k=0;
	func(root,k,l,r);
	return k;
}

