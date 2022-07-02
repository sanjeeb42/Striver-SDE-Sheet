1. Create a copy initally
like if the list is 1->2->3->4->NULL
  Then list becomes 1->1->2->2->3->3->4->4->null
  
2. connect the random pointer of new nodes 

3. Separate the two lists

//Using Map

/*
	Time complexity: O(N)
	Space complexity: O(N)

	Where 'N' is the number of nodes in the list.
*/

#include <unordered_map>

// Returns head reference of cloned linked list.
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Initialize two references, one with original list's head.
    LinkedListNode<int> *origCurr = head, *cloneCurr = NULL;

    /*
	    Hash map which contains node to node 
		mapping of original and clone linked list.
	*/
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> map;

    /*
	    Traverse the original list and make a copy of that
        in the clone linked list.
	*/
    while (origCurr != NULL)
    {
        cloneCurr = new LinkedListNode<int>(origCurr->data);
        map.insert(make_pair(origCurr, cloneCurr));
        origCurr = origCurr->next;
    }

    // Adjusting the original list reference again.
    origCurr = head;

    /*
	    Traversal of original list again to adjust the next
        and random references of clone list using hash map.
	*/
    while (origCurr != NULL)
    {
        cloneCurr = map[origCurr];
        cloneCurr->next = map[origCurr->next];
        cloneCurr->random = map[origCurr->random];
        origCurr = origCurr->next;
    }

    // Return the head reference of the clone list.
    return map[head];
}

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
