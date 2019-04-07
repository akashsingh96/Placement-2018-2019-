/*

Q.)
Given two linked lists sorted in increasing order. Merge them such a way that the result list is in decreasing order. Both the Linked list can be of different sizes.
*/

struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    
    Node* temp1=node1;
    Node* temp2=node2;
    Node* head=NULL;
    while(temp1 && temp2)
    {
        if(temp1->data<temp2->data)
        {
            Node* temp=newNode(temp1->data);
            temp->next=head;
            head=temp;
            temp1=temp1->next;
        }
        {
            Node* temp=newNode(temp2->data);
            temp->next=head;
            head=temp;
            temp2=temp2->next;
        }
        
    }
        
    if(temp1)
    while(temp1)
	{
            Node* temp=newNode(temp1->data);
            temp->next=head;
            head=temp;
            temp1=temp1->next;
        }
        
    if(temp2)
    while(temp2)
        {
            Node* temp=newNode(temp2->data);
            temp->next=head;
            head=temp;
            temp2=temp2->next;
        }
        
        return head;   
}

