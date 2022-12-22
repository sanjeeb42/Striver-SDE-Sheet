class Solution
{
    public:

        ListNode* findMid(ListNode *head)
        {

            ListNode *slow = head;
            ListNode *fast = head->next;

            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }
    
    
    ListNode* merge(ListNode* left,ListNode* right)
    {
        if(left==NULL && right==NULL)return left;
        if(left==NULL && right!=NULL)return right;
        if(left!=NULL && right==NULL)return left;
        
//         cout<<"Before Sorting: "<<endl;
        
//         ListNode* tmp=left;
//         cout<<"Left Part is : ";
//         while(tmp!=NULL){
//             cout<<tmp->val<<" ";
//             tmp=tmp->next;
//         }
//         cout<<endl;
        
//         cout<<"Right Part is: ";
//         tmp=right;
//         while(tmp!=NULL){
//             cout<<tmp->val<<" ";
//             tmp=tmp->next;
//         }
//         cout<<endl;
        
        ListNode* temp=new ListNode(1e6);
        ListNode * join=temp;
        while(left && right)
        {
            if(left->val<right->val){
                join->next=left;
                left=left->next;
                join=join->next;
            }
            else {
                join->next=right;
                right=right->next;
                join=join->next;
            }
        }
        while(left){
            join->next=left;
            left=left->next;
            join=join->next;
        }
        while(right){
            join->next=right;
            right=right->next;
            join=join->next;
        }
        // cout<<"After sorting : ";
        // tmp=temp->next;
        // while(tmp!=NULL){
        //     cout<<tmp->val<<" ";
        //     tmp=tmp->next;
        // }
        // cout<<endl;
        // cout<<" ***************** "<<endl;
        
        return temp->next;
    }

    ListNode* mergesort(ListNode *head)
    {
       	//Firstly Break it into two half
       	//Break from 0 to mid and mid+1 to last
       	

        if (head == NULL or head->next == NULL) return head;

        ListNode *left = head;
        
        ListNode *mid = findMid(head);
        ListNode *right = mid->next;
        
        //set mid->next=NULL
        mid->next = NULL;

       	//Sort The two halfs recursively
       	
        left=mergesort(left);       
        right=mergesort(right);
       
        //Merge the two halfs
        head=merge(left,right);

        return head;
    }
    ListNode* sortList(ListNode *head) {
        return mergesort(head);
       
    }
};
