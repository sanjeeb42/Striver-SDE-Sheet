// Efficinet approach will be to make the linked list circular in order to minimise the traversal - 2 Traversal to one Traversal

Node *rotate(Node *head, int k) {
    
    // Base condition.
    if(head == NULL) {
        return head;
    }
    
    int len = 1;
    Node *temp = head;
        
    // Calculate length of the linked list.
    while(temp->next != NULL) {
        temp = temp->next;
        len += 1;
    }
    
    k = k % len;
    
    // Number of rotations are same as len so no change in LL.
    if(k == len || k == 0) {
        return head;
    }

    // To make a circular linked list.
    temp->next = head;

    temp = head;
    
    for(int i = 0; i < abs(len - k - 1); i++) {
        temp = temp->next;
    }

    // Changing pointers.
    head = temp->next;
    temp->next = NULL;

    return head;
}


// Naive- 2 Traversal

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
