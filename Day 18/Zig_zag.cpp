#include<bits/stdc++.h>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    queue<BinaryTreeNode<int>*>q;
    if(root==NULL)return {};
    q.push(root);
    vector<int>ans;
    q.push(NULL);
    int level=0;
    stack<int>st;
    while(q.size()>1)
    {
        auto tmp=q.front();
        q.pop();       
        if(tmp==NULL)
        {
            q.push(NULL);
            while(st.size()>0){
                int val=st.top();
                ans.push_back(val);
                st.pop();
            }
            level++;
            continue;
        }
        if(level%2!=0){
            st.push(tmp->data);
        }
        else{
            ans.push_back(tmp->data);
         }
      
        if(tmp->left!=NULL)
        {
            q.push(tmp->left);
        }
        if(tmp->right!=NULL){
           q.push(tmp->right);
         } 
        
      }
    
    while(st.size()>0){
        ans.push_back(st.top());
        st.pop();
    }
     return ans;    
}
