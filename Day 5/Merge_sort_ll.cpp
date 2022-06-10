#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
int count_node(Node<int>*head){
    Node<int>*front=head;
    int count=0;
    while(front!=NULL){
        count++;
        front=front->next;
    }
    return count;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
//     int cnt1 = count_node(first);
//     int cnt2 = count_node(second);
    
    Node<int> *head;
//     if(cnt1==0 or cnt2==0){
//         // Enter special case dude
//         if(cnt1==0 and cnt2!=0)
//         {   head=second;
//             second=second->next;
//         }
//     else if(cnt1!=0 and cnt2==0){
//         head=first;
//         first=first->next;
//     }
//     else return first;
               
//     }
    
    if(first==NULL)return second;
    else if (second==NULL) return first;
    else if( first==NULL and second==NULL) return head;
    
    if (first != NULL and second != NULL)
    {
        if (first->data <= second->data)
        {
            head = first;
            first = first->next;
        }
        else
        {
            head = second;
            second = second->next;
        }
    }

    Node<int> *temp = head;
    while (first != NULL and second != NULL)
    {
        if (first->data <= second->data)
        {
            head->next = first;
            head = first;
            first = first->next;
        }
        else if (first->data > second->data)
        {
            head->next = second;
            head = second;
            second = second->next;
        }
    }
    while (first != NULL)
    {
        head->next = first;
        head = first;
        first = first->next;
    }
    while (second)
    {
        head->next = second;
        head = second;
        second = second->next;
    }

    return temp;
}
