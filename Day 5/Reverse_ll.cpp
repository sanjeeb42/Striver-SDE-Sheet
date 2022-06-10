LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{

    // Base condition
    if (head == NULL || head->next == NULL) 
	{
        // Return the last node.
        return head;
    }

    // Reverse the rest of Linked List
    LinkedListNode<int> *rest = reverseLinkedList(head->next);

    // Changing the reference of next node next to itself
    head->next->next = head;

    // Assign current node next to NULL.
    head->next = NULL;

    // Return the reverse Linked List.
    return rest;

}


// two pointer

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{

    // Creating node for remembering previous node in Linked List.
    LinkedListNode<int> *prev = NULL;

    // Creating temporory node.
    LinkedListNode<int> *current = head;

    while (current != NULL) 
    {
        LinkedListNode<int> *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;

    }

    // Return reverse Linked List.
    return prev;
}

// Or we can also use the xor property
// Initially, we will take two-pointers, given head that points to the head of Linked List, prev, points to null.
// Then we will iterate over the linked list until the current is not equal to NULL and do the following update in every step of the iteration:
// prev = prev ⊕ head->next
// head->next = prev ⊕ head->next
// prev = prev ⊕ head->next
// prev = prev ⊕ head
// head= prev ⊕ head
// prev = prev ⊕ head
// Now return the prev pointer which is now the head of reverse Linked List.


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    LinkedListNode<int> *pre = NULL;
    while (head != 0) {

        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head->next);
        head->next = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head->next); 
        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head->next);       
 
        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head);
        head = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head);
        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head);

    }

    return pre;

}
