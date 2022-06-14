#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node *merge(Node *head,Node* temp){
    
    Node* front=new Node(0);
    Node *ans=front;
    while(head!=NULL and temp!=NULL){
//         Node *curr;
        if(head->data<=temp->data){
//             curr=new Node(head->data);
//             curr->next=NULL;
            ans->child=head;
            ans=ans->child;
            head=head->child;
        }
        else
        {
//             curr=new Node(temp->data);
//             curr->next=NULL;
            ans->child=temp;
            ans=ans->child;
            temp=temp->child;
        }
        ans->next=NULL;
    }
    if(head!=NULL){
//         Node *curr=new Node(head->data);
//         curr->next=NULL;
        ans->child=head;
//         ans=ans->child;
//         head=head->child;
    }
     if(temp!=NULL){
//         Node *curr=new Node(temp->data);
//          curr->next=NULL;
        ans->child=temp;
//         ans=ans->child;
//         temp=temp->child;
    }
    

    ans->next=NULL;
//     Node *fb=front->child;
//     int cnt=0;
//     cout<<"Exit"<<endl;
//     while(fb!=NULL){
//         if(cnt>=5){
//             break;
//         }
//         cnt++;
//         cout<<fb->data<<" ";
//         fb=fb->child;
//     }
    return front->child;
}


Node *flatten(Node *head){
    if(head==NULL or head->next==NULL){
        return head;
    }
  
    Node*temp=flatten(head->next);
    head=merge(head,temp);
    return head;
}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here   
    Node* ans=flatten(head);
    return ans;     
}
