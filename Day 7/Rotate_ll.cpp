int count(Node *head)
{
    Node* front=head;
    int cnt=0;
    while(front!=NULL)
    {
        cnt++;
        front=front->next;
    }
    return cnt;
}

Node *rotate(Node *head, int k) {
     // Write your code here.
    Node *front=head;
    int cnt=count(head);
    k=k%cnt;
    if(k==0){
        return head;
    }
    for(int i=0;i<cnt-k-1;i++)
    {
        front=front->next;
    }
    Node* temp=front->next;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head=front->next;
    front->next=NULL;
    
    return head;
    
}
