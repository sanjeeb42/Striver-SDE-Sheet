/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:

        int countNodes(ListNode *head)
        {
            ListNode *tmp = head;
            if (head == NULL) return 0;
            int cnt = 0;
            while (tmp != NULL)
            {
                cnt++;
                tmp = tmp->next;
            }
            return cnt;
        }

    ListNode* solve(ListNode *head, int k)
    {
        if (head == NULL) return NULL;

       	//Pahele Count ki K nodes available hai ki nhi
        int count = 0;
        int cnt = countNodes(head);
        if (cnt < k) return head;
       	//First K ko reverse karo bruh
        ListNode *p = NULL, *q = NULL, *r = head;

        while (r != NULL && count < k)
        {
            p = q;
            q = r;
            r = r->next;
            q->next = p;
            count++;
        }

       	//Do Recursive Case: 
        head->next = solve(r, k);

       	//return q;
        return q;
    }
    ListNode* reverseKGroup(ListNode *head, int k)
    {

       	// 3 step hai

       	//step 1: Mai first K list ko reverse karunga

       	//step2: recursion mujhe baaki Nodes ko reverse krke dega ->jo ki currhead ka next se attach hoga

       	//step3: Mai q return krunga
        return solve(head, k);
    }
};
