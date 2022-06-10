void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    // Here Its actually copying nd then deleting
    LinkedListNode<int> *temp=node;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        node->data=temp->data;
        if(temp->next!=NULL){
        node=node->next;
        }
    }
    node->next=NULL;  
}
