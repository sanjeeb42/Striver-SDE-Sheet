class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        
        ListNode* ans=new ListNode(-1);
        ListNode* curr=ans;
        
        for(auto it: lists)
        {
            ListNode* firstNode=it;
            if(firstNode!=NULL){
            pq.push({firstNode->val,firstNode});
            }
        }
        
        while(pq.size()>0)
        {
            auto front=pq.top();
            ListNode* tmp=front.second;
           // cout<<tmp->val<<endl;
            pq.pop();
            curr->next=tmp;
            curr=curr->next;
            if(tmp->next)pq.push({tmp->next->val,tmp->next});
        
        }
        curr->next=NULL;
        
        return ans->next;
    }
};
