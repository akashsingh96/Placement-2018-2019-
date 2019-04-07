/*

Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

*/

void linkdelete(struct node  *head, int M, int N)
{

    node* temp=head;
    int count1=1,count2=0;
    while(temp)
    {
        while(count1<M && temp)
        {
            count1++;
            temp=temp->next;
        }
        if(!temp)
        break;
        count1=0;
        node* temp2=temp;
        while(count2<=N && temp2)
        {
            count2++;
            temp2=temp2->next;
        }
        if(!temp2)
        {   temp->next=NULL;
            break;
        }
        temp->next=temp2;
        count2=0;
    }
    
    return;
}
