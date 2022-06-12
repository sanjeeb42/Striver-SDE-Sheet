//My solution using Slow and Fast Pointer

LinkedListNode<int>*reverse(LinkedListNode<int>*head){
    LinkedListNode<int>*prev=NULL, *curr=head;
    while(curr!=NULL){
        LinkedListNode<int>*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;   
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL or head->next==NULL){
        return true;
    }
    LinkedListNode<int>*slow=head, *fast=head;
    do
    {
         slow=slow->next;
        fast=fast->next->next;
    }while(fast!=NULL and fast->next!=NULL);
    
    LinkedListNode<int>*first=head, *second=reverse(slow);
    
    while(first!=NULL and second!=NULL)
    {
        if(first->data!=second->data){
            return false;
        }
        first=first->next;
        second=second->next;
    }
    
    
    return true;
}























// Recursion
// The solution is to use a recursion stack. We will use two pointers left and right, one for the leftmost node and one for the rightmost node, of Linked List.
// In each recursion call, we check
// Sub Linked list is a palindrome or not.
// Values at the current left and right are matching.
// If both above conditions are true then return true from the current recursion.
// At last, if all the recursion calls return true. We can conclude the given Linked List is a palindrome.
 

// Steps:

// Recursively traverse the entire linked list to get the last node as a rightmost node.
// When we return from the last recursion stack. We will be at the last node of the Linked List. Then the last node value is compared with the first node value of Linked List.
// In order to access the first node of Linked List, we create a global left pointer that points to the head of Linked List initially that will be available for every call of recursion and the right pointer which passes in the function parameter of recursion.
// Now, if the left and right pointer node value is matched then return true from the current recursion call. Then the recursion falls back to (n-2)th node, and then we need a reference to the 2nd node from head. So we advance the left pointer in the previous call to refer to the next node in the Linked List.
// If all the recursive calls are returning true, it means the given Linked List is a palindrome else it is not a palindrome.
// Time Complexity
// O(N), where N is the number of nodes in the linked list.

// In the worst case, we are traversing the whole Linked List O(N) using recursion. Hence, the overall complexity will be O(N).

// Space Complexity
// O(N), where N is the total number of nodes in the Linked List.

// In the worst case, extra space is required for recursion stack.


bool isPalindromeUtil(LinkedListNode<int> *right, LinkedListNode<int> **left) {

    // Stop recursion when right reach end of LinkedList.
    if (right == NULL) {
        return true;
    }

    bool isPal = isPalindromeUtil(right->next, left);

    /*
        If sub-list is not palindrome then no need to check for current left and
        right, return false.
    */

    if (!isPal) {
        return false;
    }

    // Check if both left and right node value are same.
    bool isSame = ((*left)->data == right->data) ? true : false;

    // Move left pointer to next node.
    *left = (*left)->next;
    return isSame;

}

bool isPalindrome(LinkedListNode<int> *head) {

    // Assign left node as start of LinkedList.
    LinkedListNode<int> *left = head;

    // Check if LinkedList is palindrome or not.
    bool isPal = isPalindromeUtil(head, &left);

    return isPal;

}
