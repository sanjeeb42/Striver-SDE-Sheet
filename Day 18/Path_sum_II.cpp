https://leetcode.com/problems/path-sum-ii/


class Solution {
public:
    
    void solve(vector<vector<int>>&ans,TreeNode* root,int targetsum,vector<int>&curr,int curr_sum){
        
        curr.push_back(root->val);
        curr_sum+=root->val;
        
        if(root->left==NULL && root->right==NULL){
            if(curr_sum==targetsum){
                ans.push_back(curr);
            }
            curr.pop_back();
            return;
        }
        if(root->left!=NULL)solve(ans,root->left,targetsum,curr,curr_sum);
        if(root->right!=NULL)solve(ans,root->right,targetsum,curr,curr_sum);
        curr.pop_back();
         
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        
        if(root==NULL)return ans;
        solve(ans,root,targetSum,curr,0);
        
        return ans;
    }
};
