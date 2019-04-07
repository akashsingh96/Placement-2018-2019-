/*
		Given a preorder of bst tell if bst is possible or not
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* create(int data)
{
    Node* temp=new Node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int allgreat(vector<int>v,int i,int r,int data)
{
    for(int j=i;j<=r;j++)
    if(v[j]<data)
    return 0;
    
    return 1;
    
}
Node* preorder(vector<int>v,int l,int r,int& flag)
{
    if(l>r)
    return NULL;
    Node* root=create(v[l]);
    int i;
    for(i=l+1;i<=r;i++)
    if(v[l]<v[i])
    break;
    
    if(allgreat(v,i,r,v[l]))
    {
        root->left=preorder(v,l+1,i-1,flag);
        root->right=preorder(v,i,r,flag);
    }
    else
    flag=0;
    return root;
}

void post(Node* root)
{
    if(!root)
    return;
    
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    
	    int flag=1;
	    Node* root=preorder(v,0,n-1,flag);
	    
	    if(flag)
	    post(root);
	    else
	    cout<<"NO";
	    cout<<endl;
	    
	}
	return 0;
}
