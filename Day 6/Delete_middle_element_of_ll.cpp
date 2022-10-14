 ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head,*fast=head;
        ListNode* del=slow;
        
        if(head->next==NULL)return NULL;
        while(fast!=NULL && fast->next!=NULL){
            del=slow;
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        
        del->next=slow->next;
        return head;
        
    }
