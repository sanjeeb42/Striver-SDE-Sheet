class Solution
{
    public:

        void link_parent(TreeNode *root, TreeNode *prev, unordered_map<TreeNode*, TreeNode*> &mp)
        {
            if (root == NULL)
            {
                return;
            }
            mp[root] = prev;
            if (root->left != NULL)
            {
                link_parent(root->left, root, mp);
            }
            if (root->right != NULL)
            {
                link_parent(root->right, root, mp);
            }
        }

    void solve(vector<int> &ans,TreeNode*parent,TreeNode *root, int k,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if (root == NULL or k<0) return;
        
        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        
        if(root->left!=NULL && root->left!=parent)solve(ans,root,root->left,k-1,mp);
        if(root->right!=NULL && root->right!=parent)solve(ans,root,root->right,k-1,mp);
        
        if(mp[root]!=NULL && mp[root]!=parent)solve(ans,root,mp[root],k-1,mp);

       	//Try out all the ways
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>mp;
        link_parent(root,NULL,mp);
        // for(auto it: mp){
        //     cout<<it.first->val<<" "<<(it.second!=NULL?it.second->val:0)<<endl;
        // }
        
        
        vector<int>ans;
        solve(ans,NULL,target,k,mp);
        return ans;
        
        
    }
};
