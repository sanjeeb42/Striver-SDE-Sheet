1. Create a copy initally
like if the list is 1->2->3->4->NULL
  Then list becomes 1->1->2->2->3->3->4->4->null
  
2. connect the random pointer of new nodes 

3. Separate the two lists



#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL) return head;
    LinkedListNode<int>* curr=head;
    while(curr!=NULL)
    {
        LinkedListNode<int>*temp=new LinkedListNode<int>(curr->data); 
        temp->next=curr->next;
        curr->next=temp;
        curr=temp->next;  
    }

    
    curr=head;  
    LinkedListNode<int>*itr=curr->next;
    LinkedListNode<int>*finalans=itr;

    while(curr!=NULL)
    {
        itr->random=curr->random==NULL?NULL:curr->random->next;
        curr=itr->next;
        if(curr==NULL)break;
        else itr=curr->next;
    }

    curr=head;
    LinkedListNode<int>*ans=finalans;
    
    while(curr!=NULL){
        curr->next=finalans->next;
        curr=curr->next;
        if(curr==NULL) break;
        finalans->next=curr->next; 
        finalans=finalans->next;
    }
    return ans;
}
