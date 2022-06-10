#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
int count_node(LinkedListNode<int>*head)
{
    LinkedListNode<int>*front=head;
    int count=0;
    while(front!=NULL){
        count++;
        front=front->next;
    }
    return count;
}

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(head==NULL) return NULL;
    if(K==0)return head;
    int cnt=count_node(head);
   // cout<<cnt<<endl;
    LinkedListNode<int>*temp=head;
    for(int i=0;i<cnt-K-1;i++)
    {
        temp=temp->next;
    }    
    if(temp==head and cnt==K){
        head=temp->next;
        free(temp);
        return head;
    }
   // cout<<temp->data<<endl;
    LinkedListNode<int>*curr=temp->next;
    temp->next=curr->next;
   // curr->next=NULL;
    free(curr);
    return head;   
}






// Start the fast pointer K steps beforehand so that fast reaches end and slow reaches Kth node from end

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
