ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // create an ans node with one dummy node 0
        ListNode* ans = new ListNode(0);
        // create an head node pointing to ans node
        // head node will be helpful for us in returning our final answer
        ListNode* head = ans;
        // initialize carry with 0
        int carry = 0;
        // iterate till both the linked list are not NULL, they should have some value
        // case1: if l1 and l2 are both of same size
        while(l1 && l2){
            int value = l1 -> val + l2 -> val + carry;
            carry = value / 10;
            // insert the last digit of value to the ans
            ans -> next = new ListNode(value % 10);
            // increment all to next iteration
            ans = ans -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        // something will be left out in l1
        // case2: if length of l1 is greater than l2
        while(l1){
            int value = l1 -> val + carry;
            carry = value / 10;
            // insert the last digit of value to the ans
            ans -> next = new ListNode(value % 10);
            // increment all to next iteration
            ans = ans -> next;
            l1 = l1 -> next;
        }
        // something will be left out in l2
        // case3: if length of l2 is greater than l1
        while(l2){
            int value = l2 -> val + carry;
            carry = value / 10;
            // insert the last digit of value to the ans
            ans -> next = new ListNode(value % 10);
            // increment all to next iteration
            ans = ans -> next;
            l2 = l2 -> next;
        }
        // case4: at last if carry is left over
        // simply add than carry to our ans
        if(carry) ans -> next = new ListNode(carry);
        // return the head of our answer which is head -> next;
        return head -> next;
    }

// Aliter

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    int carry=0;
    Node* ans=new Node(0),*head=ans;        
       
     while(l1!=NULL or l2!=NULL)
        {
            int val=0;
            if(l1!=NULL){
                val+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                val+=l2->data;
                l2=l2->next;
            }
            val+=carry;
            Node*temp=new Node(val%10);
            carry=val/10;
            ans->next=temp;   
            ans=temp;         
        }
        
        if(carry>0){
            Node* temp=new Node(carry);
            ans->next=temp;
            ans=temp;
        }
        return head->next;
   
}
